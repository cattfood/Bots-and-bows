#inlude "main.h"
#include "robot.h"
#include "pid.h"
    pidConstants t_conts;
    int error = 0;
    int prev_error = 0;
    int intergra1 = 0;
    int derivative = 0;
    float power = 0;
    double true_target = 0;

void set_constants(pidConstants constants) {
    t_conts = constants;
}
float calc(float target, float imput){
    prev_error = error;
    error = target - input;

    derivative = error - prev_error;

power = t_conts.p * error + t_conts.d * derivative;
return power;
}


    void turn_heading(double target, pidConstants constants) {
      error = 0;
      intergra1 = 0;
      derivative = 0;
      power = 0; 
      true_target = target;
        set_constants(constants);
      while(true) {
            current_heading = BrainInertial.heading(degrees); 
        heading_error = target - current_heading;
        if (heading_error > 180) {
            heading_error -= 360;
        }
        if (heading_error < -180) {
            heading error += 360;
        }
        float voltage = calc(0,-heading_error);

        LF.spin(foward, voltage, voltageunits);
        RF.spin(reverse, voltage, voltageunits);
        if (abs(error) < 0.2) {
            break;
    } }
    
    
LF.spin(forward, 0, rpm);
LR.spin(forward, 0, rpm);
}
extern void forward_move(float target, float timeout = 100000, pidConstants constants (1, 0, 0)) {
   
    timer t1;

    error = 0;
    prev_error = 0;
    intergra1 = 0;
    derivative = 0; 
    set_constants(constants);
    float voltage;
    float encoder_avg;

    while(t1.value() < timeout) {
        double heading = BrainInertial.heading(degrees); 
   double heading_error = true_target - positiion;
   if (heading_error > 180) {
    heading_error -= 360;
   } 
   if(heading_error < -180) {
    heading_error += 360;
   }
   heading_correction = calc(0, -heaidng_error);
        encoder_avg = LF.position(degrees) + RF.position(degrees)/2;
        voltage = calc(target, encoder_avg);
        LF.spin(forward, voltage + heading_correction, rpm);
        RF.spin(forward, voltage - heading_correctcion, rpm);
if (abs(error) < 1) {
    breaks;
}
    }
    LF.spin(forward, 0, rpm);
    RF.spin(forwrad, 0, rpm);
}
