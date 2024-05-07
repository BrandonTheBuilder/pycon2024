#include "Python.h"

extern int load_file(char* name);
extern int find_value(int value);

PyObject *find_value_py(PyObject *self, PyObject *arg) {
  int val = (int)PyLong_AsLong(arg);
  int result = find_value(val);
  return PyLong_FromLong(result);
}

PyObject *load_file_py(PyObject *self, PyObject *arg) {
  const char* filename = PyUnicode_AsUTF8(arg);
  int res = load_file(filename);
  return PyLong_FromLong(res);
}

static PyMethodDef extension_methods[] = {
    {"load_file_c", load_file_py, METH_O, ""},
    {"find_value_c", find_value_py, METH_O, ""},
    {NULL, NULL, 0, NULL}};

static PyModuleDef extension_module = {
    PyModuleDef_HEAD_INIT,          "read_data_extension",    .m_size = -1,
    .m_methods = extension_methods, .m_free = NULL,
};

PyMODINIT_FUNC PyInit_read_data_extension() {
  PyObject *module = PyModule_Create(&extension_module);
  return module;
}
