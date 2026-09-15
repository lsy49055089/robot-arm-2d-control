cmake_minimum_required(VERSION 3.16)

project(robot_arm_2d_control C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

function(configure_robot_target target_name)
    target_include_directories(${target_name}
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/config>
    )

    if(MSVC)
        target_compile_options(${target_name} PRIVATE /W4)
    else()
        target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endfunction()

add_library(robot_pose STATIC
    src/pose/pose_mapping.c
)
configure_robot_target(robot_pose)

add_library(robot_motion STATIC
    src/motion/kinematics_2d.c
    src/motion/motion_control.c
)
configure_robot_target(robot_motion)

add_library(robot_servo STATIC
    src/servo/servo_control.c
    src/servo/servo_config.c
    src/servo/motion_record.c
    src/servo/robot_mode.c
)
configure_robot_target(robot_servo)

add_executable(robot_arm_2d_control
    src/main.c
)
configure_robot_target(robot_arm_2d_control)
target_link_libraries(robot_arm_2d_control
    PRIVATE
        robot_pose
        robot_motion
        robot_servo
)

include(CTest)

if(BUILD_TESTING)
    add_executable(test_pose_mapping tests/pose/test_pose_mapping.c)
    configure_robot_target(test_pose_mapping)
    target_link_libraries(test_pose_mapping PRIVATE robot_pose)
    add_test(NAME pose_mapping COMMAND test_pose_mapping)

    add_executable(test_kinematics_2d tests/motion/test_kinematics_2d.c)
    configure_robot_target(test_kinematics_2d)
    target_link_libraries(test_kinematics_2d PRIVATE robot_motion)
    add_test(NAME kinematics_2d COMMAND test_kinematics_2d)

    add_executable(test_servo_control tests/servo/test_servo_control.c)
    configure_robot_target(test_servo_control)
    target_link_libraries(test_servo_control PRIVATE robot_servo)
    add_test(NAME servo_control COMMAND test_servo_control)

    add_executable(test_record tests/servo/test_record.c)
    configure_robot_target(test_record)
    target_link_libraries(test_record PRIVATE robot_servo)
    add_test(NAME motion_record COMMAND test_record)
endif()
