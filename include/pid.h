#include "main.h"
#include "robot.h"
#ifndef PIDH
#define PIDH
struct pidConstants {
    float p;
    float i; 
    float d;
};
extern void set_constants(pidConstants constants);
extern void turn_heading (double target, pidConstants constants = {3,0,0});
extern void forward_move(float target, float timeout = 100000, pidConstants constants (1, 0, 0));
#endif