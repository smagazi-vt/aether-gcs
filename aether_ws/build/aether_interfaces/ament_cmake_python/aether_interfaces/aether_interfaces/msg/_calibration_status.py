# generated from rosidl_generator_py/resource/_idl.py.em
# with input from aether_interfaces:msg/CalibrationStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CalibrationStatus(type):
    """Metaclass of message 'CalibrationStatus'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('aether_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'aether_interfaces.msg.CalibrationStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__calibration_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__calibration_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__calibration_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__calibration_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__calibration_status

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CalibrationStatus(metaclass=Metaclass_CalibrationStatus):
    """Message class 'CalibrationStatus'."""

    __slots__ = [
        '_system_id',
        '_instruction_text',
        '_progress_percentage',
        '_is_complete',
        '_success',
    ]

    _fields_and_field_types = {
        'system_id': 'uint8',
        'instruction_text': 'string',
        'progress_percentage': 'float',
        'is_complete': 'boolean',
        'success': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.system_id = kwargs.get('system_id', int())
        self.instruction_text = kwargs.get('instruction_text', str())
        self.progress_percentage = kwargs.get('progress_percentage', float())
        self.is_complete = kwargs.get('is_complete', bool())
        self.success = kwargs.get('success', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.system_id != other.system_id:
            return False
        if self.instruction_text != other.instruction_text:
            return False
        if self.progress_percentage != other.progress_percentage:
            return False
        if self.is_complete != other.is_complete:
            return False
        if self.success != other.success:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def system_id(self):
        """Message field 'system_id'."""
        return self._system_id

    @system_id.setter
    def system_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'system_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'system_id' field must be an unsigned integer in [0, 255]"
        self._system_id = value

    @builtins.property
    def instruction_text(self):
        """Message field 'instruction_text'."""
        return self._instruction_text

    @instruction_text.setter
    def instruction_text(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'instruction_text' field must be of type 'str'"
        self._instruction_text = value

    @builtins.property
    def progress_percentage(self):
        """Message field 'progress_percentage'."""
        return self._progress_percentage

    @progress_percentage.setter
    def progress_percentage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'progress_percentage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'progress_percentage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._progress_percentage = value

    @builtins.property
    def is_complete(self):
        """Message field 'is_complete'."""
        return self._is_complete

    @is_complete.setter
    def is_complete(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_complete' field must be of type 'bool'"
        self._is_complete = value

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value
