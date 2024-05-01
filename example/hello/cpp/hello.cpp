#include "Python.h"
#include <string>
#include <unordered_map>

const char *MESSAGE = "hello world";
extern std::unordered_map<std::string, long> messages;

PyObject *get_message(PyObject *self, PyObject *arg) {
  std::string key = PyUnicode_AsUTF8(arg);
  auto result = messages.find(key);
  PyObject *greeting;
  if (result == messages.end()) {
    greeting = PyUnicode_FromString(key.c_str());
  } else {
    greeting = PyLong_FromLong(result->second);
  }
  return greeting;
}

PyObject *increment_value(PyObject *self, PyObject *arg) {
  std::string key = PyUnicode_AsUTF8(arg);
  auto result = messages.find(key);
  PyObject *greeting;
  if (result == messages.end()) {
    greeting = PyUnicode_FromString(key.c_str());
  } else {
    result->second += 1;
    greeting = PyLong_FromLong(result->second);
  }
  return greeting;
}

static PyMethodDef hello_methods[] = {
    {"get_message", get_message, METH_O, "Get hello message"},
    {"increment_value", increment_value, METH_O, "increment the value"},
    {NULL, NULL, 0, NULL}};

static PyModuleDef hello_module = {
    PyModuleDef_HEAD_INIT,      "get_message",  .m_size = -1,
    .m_methods = hello_methods, .m_free = NULL,
};

PyMODINIT_FUNC PyInit_get_message() {
  PyObject *module = PyModule_Create(&hello_module);
  return module;
}
