#ifndef ROBOT_CALIBRATION_H
#define ROBOT_CALIBRATION_H

#include "common/robot_types.h"

/*
 * Agent 2 public API.
 *
 * Converts an Agent 1 HumanJointTarget into a calibrated and safety-limited
 * JointCommand for the robot arm.
 */
int robot_calibration_apply(
    const HumanJointTarget *input,
    JointCommand *output
);

#endif /* ROBOT_CALIBRATION_H */
