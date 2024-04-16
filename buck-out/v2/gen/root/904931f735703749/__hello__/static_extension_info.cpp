#include "Python.h"
#include "import.h"
#include <unordered_map>
#include <string_view>
typedef PyObject* (*pyinitfunc)();
std::unordered_map<std::string_view, pyinitfunc> _static_extension_info = {
};
