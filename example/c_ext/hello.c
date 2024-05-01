#include "Python.h"

const char *MESSAGE = "hello world";

PyObject *get_message(PyObject *self, PyObject *args) {
  PyObject *greeting = PyUnicode_FromString(MESSAGE);
  return greeting;
}

static PyMethodDef hello_methods[] = {
    {"get_message", get_message, METH_NOARGS, "Get hello message"},
    {NULL, NULL, 0, NULL}};

static PyMethodDef hello_module ==
    {
        PyModuleDef_HEAD_INIT,      "hello",        .msize = -1,
        .m_methods = hello_methods, .m_free = NULL,
    };

PyMODINIT_FUNC PyInit_hello() {
  PyObject *module = PyModule_Create(&bye_module);
  return module;
}
