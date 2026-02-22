#include "vex.h"
#ifndef ROBOTH
#define ROBOTH
vex::brain       Brain;
using namespace vex;
extern motor LF;
extern   motor RF;
extern   motor lift;
extern   motor lift2;
extern   motor beam1;
extern   motor beam2;
extern   pneumatic clamp = pneumatic;

extern   controller con = controller;
extern inertial BrainInertial;
#endif
