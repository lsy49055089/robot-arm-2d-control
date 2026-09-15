#ifndef COMMON_ROBOT_TYPES_H
#define COMMON_ROBOT_TYPES_H

#include <stdint.h>

/* A point measured in camera pixel coordinates. */
typedef struct {
    float x;
    float y;
    uint8_t valid;
} Point2D;

/* A point expressed in the robot coordinate system. */
typedef struct {
    float x;
    float y;
    float z;
    uint8_t valid;
} Robot3D;

/* Pose detector output consumed by the pose mapping module. */
typedef struct {
    Point2D finger1;
    Point2D finger2;
    Point2D elbow;
    Point2D wrist;
    Point2D shoulder_l;
    Point2D shoulder_r;

    uint32_t frame_id;
    uint8_t valid;
} HumanArm2D;

/* Robot-space target produced by pose mapping for the motion module. */
typedef struct {
    Robot3D finger1;
    Robot3D finger2;
    Robot3D wrist;
    Robot3D elbow;
    Robot3D shoulder;

    uint8_t valid;
} TargetPose3D;

/* Joint target produced by motion control for the servo module. */
typedef struct {
    float base_deg;

    float shoulder_deg;
    float elbow_deg;
    float wrist_pitch_deg;
    float wrist_roll_deg;

    float gripper_norm;

    uint8_t valid;
} JointCommand;

#endif /* COMMON_ROBOT_TYPES_H */
