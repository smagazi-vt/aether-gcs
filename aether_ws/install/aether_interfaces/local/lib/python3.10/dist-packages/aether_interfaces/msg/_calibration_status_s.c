// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from aether_interfaces:msg/CalibrationStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "aether_interfaces/msg/detail/calibration_status__struct.h"
#include "aether_interfaces/msg/detail/calibration_status__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool aether_interfaces__msg__calibration_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[60];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("aether_interfaces.msg._calibration_status.CalibrationStatus", full_classname_dest, 59) == 0);
  }
  aether_interfaces__msg__CalibrationStatus * ros_message = _ros_message;
  {  // system_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "system_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->system_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // instruction_text
    PyObject * field = PyObject_GetAttrString(_pymsg, "instruction_text");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->instruction_text, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // progress_percentage
    PyObject * field = PyObject_GetAttrString(_pymsg, "progress_percentage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->progress_percentage = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // is_complete
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_complete");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_complete = (Py_True == field);
    Py_DECREF(field);
  }
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * aether_interfaces__msg__calibration_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CalibrationStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("aether_interfaces.msg._calibration_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CalibrationStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  aether_interfaces__msg__CalibrationStatus * ros_message = (aether_interfaces__msg__CalibrationStatus *)raw_ros_message;
  {  // system_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->system_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "system_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // instruction_text
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->instruction_text.data,
      strlen(ros_message->instruction_text.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "instruction_text", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // progress_percentage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->progress_percentage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "progress_percentage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_complete
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_complete ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_complete", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
