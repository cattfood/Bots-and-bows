#include "vex.h"
#include "robot.h"
vex::brain       Brain;
using namespace vex;
motor LF(PORT12, true);
   motor RF(PORT6);
   motor lift(PORT7, false);
   motor lift2(PORT1, true);
   motor beam1(PORT8, false);
   motor beam2(PORT2, true);
   pneumatic clamp = pneumatic(PORT9, true);

   controller con = controller();
   inertial BrainInertial = inertial();