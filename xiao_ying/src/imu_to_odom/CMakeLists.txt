cmake_minimum_required(VERSION 3.8)
project(imu_to_odom)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

###############################################################
#build
###############################################################
include_directories(
  include
)

set(EXEC_NAME "imu_to_odom")

set(dependencies 
    "nav_msgs" 
    "sensor_msgs" 
    "rclcpp")
    
add_executable(${EXEC_NAME} src/imu_to_odom.cpp)
ament_target_dependencies(${EXEC_NAME} ${dependencies})

###############################################################
#install
###############################################################
install(DIRECTORY include/
  DESTINATION include/
)

install(TARGETS ${EXEC_NAME}
  DESTINATION lib/${PROJECT_NAME}
)


ament_package()
