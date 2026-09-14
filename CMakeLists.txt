cmake_minimum_required(VERSION 3.16)

project(robot_arm_2d_control C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(config)

add_executable(robot_arm_2d_control
    src/main.c
)