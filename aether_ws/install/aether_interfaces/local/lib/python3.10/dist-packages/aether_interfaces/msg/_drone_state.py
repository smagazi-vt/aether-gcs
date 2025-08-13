# generated from rosidl_generator_py/resource/_idl.py.em
# with input from aether_interfaces:msg/DroneState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DroneState(type):
    """Metaclass of message 'DroneState'."""

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
                'aether_interfaces.msg.DroneState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__drone_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__drone_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__drone_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__drone_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__drone_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DroneState(metaclass=Metaclass_DroneState):
    """Message class 'DroneState'."""

    __slots__ = [
        '_system_id',
        '_firmware_type',
        '_flight_mode',
        '_is_armed',
        '_is_connected',
    ]

    _fields_and_field_types = {
        'system_id': 'uint8',
        'firmware_type': 'string',
        'flight_mode': 'string',
        'is_armed': 'boolean',
        'is_connected': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.system_id = kwargs.get('system_id', int())
        self.firmware_type = kwargs.get('firmware_type', str())
        self.flight_mode = kwargs.get('flight_mode', str())
        self.is_armed = kwargs.get('is_armed', bool())
        self.is_connected = kwargs.get('is_connected', bool())

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
        if self.firmware_type != other.firmware_type:
            return False
        if self.flight_mode != other.flight_mode:
            return False
        if self.is_armed != other.is_armed:
            return False
        if self.is_connected != other.is_connected:
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
    def firmware_type(self):
        """Message field 'firmware_type'."""
        return self._firmware_type

    @firmware_type.setter
    def firmware_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'firmware_type' field must be of type 'str'"
        self._firmware_type = value

    @builtins.property
    def flight_mode(self):
        """Message field 'flight_mode'."""
        return self._flight_mode

    @flight_mode.setter
    def flight_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'flight_mode' field must be of type 'str'"
        self._flight_mode = value

    @builtins.property
    def is_armed(self):
        """Message field 'is_armed'."""
        return self._is_armed

    @is_armed.setter
    def is_armed(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_armed' field must be of type 'bool'"
        self._is_armed = value

    @builtins.property
    def is_connected(self):
        """Message field 'is_connected'."""
        return self._is_connected

    @is_connected.setter
    def is_connected(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_connected' field must be of type 'bool'"
        self._is_connected = value
