from setuptools import find_packages, setup

package_name = 'cat'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='hamilton',
    maintainer_email='hamilton@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'pc_controller = cat.pc_controller:main',
            'state_machine = cat.state_machine:main',
            'udp_send_node = cat.udp_send_node:main',
        ],
    },
)
