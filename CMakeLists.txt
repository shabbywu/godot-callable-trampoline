cmake_minimum_required(VERSION 3.13)

set(VCPKG_OVERLAY_PORTS ${CMAKE_CURRENT_LIST_DIR}/.vcpkg/ports/godot-cpp)
project(godot-callable-trampoline)

find_package(godot-cpp CONFIG REQUIRED)
get_target_property(GODOT_INTERFACE_INCLUDE_DIRECTORIES godot-cpp::godot-cpp INTERFACE_INCLUDE_DIRECTORIES)
add_subdirectory(godot-callable-trampoline)
