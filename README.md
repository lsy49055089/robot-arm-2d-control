# robot-arm-2d-control

C-based 2D human-motion tracking and 6-axis servo robot arm control project.

## Project structure

```text
robot-arm-2d-control/
├── include/
│   ├── common/    # Shared data contracts
│   ├── pose/      # Camera pose mapping
│   ├── motion/    # Kinematics and motion control
│   └── servo/     # Servo output, modes, and recording
├── src/            # Implementations grouped by module
├── tests/          # Tests grouped by module
├── config/         # Robot-wide hardware configuration
├── docs/           # Interface and coordinate documentation
└── scripts/        # Ubuntu setup and build helpers
```

Module headers are included with their module path, for example:

```c
#include "common/robot_types.h"
#include "motion/kinematics_2d.h"
```

## Build and test

```bash
./scripts/build.sh
ctest --test-dir build --output-on-failure
```
