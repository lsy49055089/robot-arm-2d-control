#ifndef ROBOT_TYPES_H
#define ROBOT_TYPES_H

#include <stdint.h>

typedef struct {
    float x;
    float y;
    uint8_t valid;
} Point2D;
typedef struct {
    float x;
    float y;
    float z;
    uint8_t valid;
} Robot3D;

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

typedef struct {
    Robot3D finger1;
    Robot3D finger2;
    Robot3D wrist;
    Robot3D elbow;
    Robot3D shoulder;

    uint8_t valid;
} Target2D;

typedef struct {
    float base_deg;

    float shoulder_deg;
    float elbow_deg;
    float wrist_pitch_deg;
    float wrist_roll_deg;

    float gripper_norm;

    uint8_t valid;
} JointCommand;

#endif