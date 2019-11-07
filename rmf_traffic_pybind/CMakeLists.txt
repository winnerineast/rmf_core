cmake_minimum_required(VERSION 3.5.0)

project(rmf_traffic_pybind)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rmf_traffic REQUIRED)
find_package(rmf_traffic_msgs REQUIRED)

add_subdirectory(external/pybind11)

pybind11_add_module(py_rmf_traffic src/main.cpp)

ament_package()
