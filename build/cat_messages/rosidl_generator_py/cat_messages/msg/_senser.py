# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cat_messages:msg/Senser.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Senser(type):
    """Metaclass of message 'Senser'."""

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
                'cat_messages.msg.Senser')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__senser
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__senser
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__senser
            cls._TYPE_SUPPORT = module.type_support_msg__msg__senser
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__senser

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Senser(metaclass=Metaclass_Senser):
    """Message class 'Senser'."""

    __slots__ = [
        '_senser1',
        '_senser2',
        '_senser3',
        '_senser4',
    ]

    _fields_and_field_types = {
        'senser1': 'int64',
        'senser2': 'int64',
        'senser3': 'int64',
        'senser4': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.senser1 = kwargs.get('senser1', int())
        self.senser2 = kwargs.get('senser2', int())
        self.senser3 = kwargs.get('senser3', int())
        self.senser4 = kwargs.get('senser4', int())

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
        if self.senser1 != other.senser1:
            return False
        if self.senser2 != other.senser2:
            return False
        if self.senser3 != other.senser3:
            return False
        if self.senser4 != other.senser4:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def senser1(self):
        """Message field 'senser1'."""
        return self._senser1

    @senser1.setter
    def senser1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'senser1' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'senser1' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._senser1 = value

    @builtins.property
    def senser2(self):
        """Message field 'senser2'."""
        return self._senser2

    @senser2.setter
    def senser2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'senser2' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'senser2' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._senser2 = value

    @builtins.property
    def senser3(self):
        """Message field 'senser3'."""
        return self._senser3

    @senser3.setter
    def senser3(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'senser3' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'senser3' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._senser3 = value

    @builtins.property
    def senser4(self):
        """Message field 'senser4'."""
        return self._senser4

    @senser4.setter
    def senser4(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'senser4' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'senser4' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._senser4 = value
