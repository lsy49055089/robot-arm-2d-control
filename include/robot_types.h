#ifndef ROBOT_TYPES_H
#define ROBOT_TYPES_H

#include <stdint.h>

typedef struct {
    float x;
    float y;
    uint8_t valid;
} Point2D;

typedef struct {
    Point2D shoulder;
    Point2D elbow;
    Point2D wrist;

    Point2D finger1;
    Point2D finger2;

    uint32_t frame_id;
    uint8_t valid;
} HumanArm2D;

typedef struct {
    float wrist_x_mm;
    float wrist_z_mm;

    float hand_pitch_deg;

    float gripper_norm;

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