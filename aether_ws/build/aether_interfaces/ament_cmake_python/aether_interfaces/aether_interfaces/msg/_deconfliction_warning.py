# generated from rosidl_generator_py/resource/_idl.py.em
# with input from aether_interfaces:msg/DeconflictionWarning.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DeconflictionWarning(type):
    """Metaclass of message 'DeconflictionWarning'."""

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
                'aether_interfaces.msg.DeconflictionWarning')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__deconfliction_warning
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__deconfliction_warning
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__deconfliction_warning
            cls._TYPE_SUPPORT = module.type_support_msg__msg__deconfliction_warning
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__deconfliction_warning

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DeconflictionWarning(metaclass=Metaclass_DeconflictionWarning):
    """Message class 'DeconflictionWarning'."""

    __slots__ = [
        '_header',
        '_drone_id_1',
        '_drone_id_2',
        '_warning_text',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'drone_id_1': 'uint8',
        'drone_id_2': 'uint8',
        'warning_text': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.drone_id_1 = kwargs.get('drone_id_1', int())
        self.drone_id_2 = kwargs.get('drone_id_2', int())
        self.warning_text = kwargs.get('warning_text', str())

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
        if self.header != other.header:
            return False
        if self.drone_id_1 != other.drone_id_1:
            return False
        if self.drone_id_2 != other.drone_id_2:
            return False
        if self.warning_text != other.warning_text:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def drone_id_1(self):
        """Message field 'drone_id_1'."""
        return self._drone_id_1

    @drone_id_1.setter
    def drone_id_1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drone_id_1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'drone_id_1' field must be an unsigned integer in [0, 255]"
        self._drone_id_1 = value

    @builtins.property
    def drone_id_2(self):
        """Message field 'drone_id_2'."""
        return self._drone_id_2

    @drone_id_2.setter
    def drone_id_2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drone_id_2' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'drone_id_2' field must be an unsigned integer in [0, 255]"
        self._drone_id_2 = value

    @builtins.property
    def warning_text(self):
        """Message field 'warning_text'."""
        return self._warning_text

    @warning_text.setter
    def warning_text(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'warning_text' field must be of type 'str'"
        self._warning_text = value
