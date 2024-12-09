# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cat_messages:msg/Vel.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Vel(type):
    """Metaclass of message 'Vel'."""

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
                'cat_messages.msg.Vel')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__vel
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__vel
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__vel
            cls._TYPE_SUPPORT = module.type_support_msg__msg__vel
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__vel

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Vel(metaclass=Metaclass_Vel):
    """Message class 'Vel'."""

    __slots__ = [
        '_vel_x',
        '_vel_y',
        '_vel_yaw',
        '_vel_wheel_right',
        '_vel_wheel_left',
    ]

    _fields_and_field_types = {
        'vel_x': 'double',
        'vel_y': 'double',
        'vel_yaw': 'double',
        'vel_wheel_right': 'double',
        'vel_wheel_left': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vel_x = kwargs.get('vel_x', float())
        self.vel_y = kwargs.get('vel_y', float())
        self.vel_yaw = kwargs.get('vel_yaw', float())
        self.vel_wheel_right = kwargs.get('vel_wheel_right', float())
        self.vel_wheel_left = kwargs.get('vel_wheel_left', float())

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
        if self.vel_x != other.vel_x:
            return False
        if self.vel_y != other.vel_y:
            return False
        if self.vel_yaw != other.vel_yaw:
            return False
        if self.vel_wheel_right != other.vel_wheel_right:
            return False
        if self.vel_wheel_left != other.vel_wheel_left:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def vel_x(self):
        """Message field 'vel_x'."""
        return self._vel_x

    @vel_x.setter
    def vel_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_x = value

    @builtins.property
    def vel_y(self):
        """Message field 'vel_y'."""
        return self._vel_y

    @vel_y.setter
    def vel_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_y = value

    @builtins.property
    def vel_yaw(self):
        """Message field 'vel_yaw'."""
        return self._vel_yaw

    @vel_yaw.setter
    def vel_yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_yaw = value

    @builtins.property
    def vel_wheel_right(self):
        """Message field 'vel_wheel_right'."""
        return self._vel_wheel_right

    @vel_wheel_right.setter
    def vel_wheel_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_wheel_right' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_wheel_right' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_wheel_right = value

    @builtins.property
    def vel_wheel_left(self):
        """Message field 'vel_wheel_left'."""
        return self._vel_wheel_left

    @vel_wheel_left.setter
    def vel_wheel_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_wheel_left' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_wheel_left' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_wheel_left = value
