# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cat_messages:msg/JoyCat.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_JoyCat(type):
    """Metaclass of message 'JoyCat'."""

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
            module = import_type_support('cat_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cat_messages.msg.JoyCat')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__joy_cat
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__joy_cat
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__joy_cat
            cls._TYPE_SUPPORT = module.type_support_msg__msg__joy_cat
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__joy_cat

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class JoyCat(metaclass=Metaclass_JoyCat):
    """Message class 'JoyCat'."""

    __slots__ = [
        '_x',
        '_yaw',
        '_button_1',
        '_button_2',
    ]

    _fields_and_field_types = {
        'x': 'double',
        'yaw': 'double',
        'button_1': 'boolean',
        'button_2': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', float())
        self.yaw = kwargs.get('yaw', float())
        self.button_1 = kwargs.get('button_1', bool())
        self.button_2 = kwargs.get('button_2', bool())

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
        if self.x != other.x:
            return False
        if self.yaw != other.yaw:
            return False
        if self.button_1 != other.button_1:
            return False
        if self.button_2 != other.button_2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._yaw = value

    @builtins.property
    def button_1(self):
        """Message field 'button_1'."""
        return self._button_1

    @button_1.setter
    def button_1(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'button_1' field must be of type 'bool'"
        self._button_1 = value

    @builtins.property
    def button_2(self):
        """Message field 'button_2'."""
        return self._button_2

    @button_2.setter
    def button_2(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'button_2' field must be of type 'bool'"
        self._button_2 = value
