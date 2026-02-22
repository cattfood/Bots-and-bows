#inlude "main.h"
#include "robot.h"
#include "pid.h"
    void turn_heading(double target, double kp) {
        current_heading = BrainInertial.heading(degrees); 
        error = target - current_heading;
        LF.spin(foward, error * kp, voltageunits);
        RF.spin(reverse, -error * kp, voltageunits);
    }
        while(error > 0.2){
            LF.spin(0)
    