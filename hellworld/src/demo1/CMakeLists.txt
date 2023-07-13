cmake_minimum_required(VERSION 3.8)
project(demo1)

set(demo1_MAJOR_VERSION 0)
set(demo1_MINOR_VERSION 0)
set(demo1_PATCH_VERSION 0)
set(demo1_VERSION
  ${demo1_MAJOR_VERSION}.${demo1_MINOR_VERSION}.${demo1_PATCH_VERSION})

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(rclcpp REQUIRED)
