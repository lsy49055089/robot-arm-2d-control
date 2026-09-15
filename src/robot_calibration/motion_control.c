#include "common/robot_types.h"
#include "robot_calibration/robot_calibration.h"
#include "robot_calibration/robot_calibration_config.h"
#include "robot_calibration/motion_control.h"

// 이 파일 안에서만 쓰는, 즉 application에서 사용하지 않는 함수는 static이며 header에 포함하지 않는다.
static float map_joint_angle(
    float human_deg,
    const JointCalibration *config
)
{
    return human_deg
         * config->scale
         * (float)config->direction
         + config->zero_offset_deg;
}
