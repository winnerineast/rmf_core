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

add_subdirectory(external/pybind11)

find_package(ament_cmake REQUIRED)
find_package(rmf_traffic REQUIRED)

file(GLOB_RECURSE bind_lib_srcs "src/*.cpp")
pybind11_add_module(py_rmf_traffic
  ${bind_lib_srcs}
)

target_link_libraries(py_rmf_traffic
  PUBLIC
    rmf_traffic::rmf_traffic
)

target_include_directories(py_rmf_traffic
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

ament_export_dependencies(rmf_traffic)

install(
  DIRECTORY include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  TARGETS py_rmf_traffic
  EXPORT  py_rmf_traffic
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

ament_package()
