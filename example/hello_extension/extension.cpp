#include "Python.h"

const char *MESSAGE = "hello world";

PyObject *get_message(PyObject *self, PyObject *arg) {
  return PyUnicode_FromString(MESSAGE);
}

static PyMethodDef extension_methods[] = {
    {"get_message", get_message, METH_NOARGS, "Return the message"},
    {NULL, NULL, 0, NULL}
};

static PyModuleDef extension_module = {
    PyModuleDef_HEAD_INIT,      "extension",  .m_size = -1,
    .m_methods = extension_methods, .m_free = NULL,
};

PyMODINIT_FUNC PyInit_extension() {
  PyObject *module = PyModule_Create(&extension_module);
  return module;
}
