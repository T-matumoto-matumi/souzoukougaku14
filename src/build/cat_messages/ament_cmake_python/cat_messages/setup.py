from setuptools import find_packages
from setuptools import setup

setup(
    name='cat_messages',
    version='0.0.0',
    packages=find_packages(
        include=('cat_messages', 'cat_messages.*')),
)
