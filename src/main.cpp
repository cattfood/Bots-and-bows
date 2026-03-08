/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       alice                                                     */
/*    Created:      2/7/2026, 1:34:23 PM                                      */
/*    Description:  IQ2 project                                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the IQ2 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here
  



int main() {
	
    Brain.Screen.printAt( 2, 30, "Hello IQ2" );
   motor LF(PORT12, true);
   motor RF(PORT6);
   motor lift(PORT7, false);
   motor lift2(PORT1, true);
   motor beam1(PORT8, false);
   motor beam2(PORT2, true);
   pneumatic clamp = pneumatic(PORT9, true);
   pneumatic aligner = pneumatic(PORT4, true);

   lift.setStopping(hold);
   lift2.setStopping(hold);
   beam1.setStopping(hold);
   beam2.setStopping(holld);

   controller con = controller();


   
    while(true) {
        lift.setVelocity(100, percent);
        lift2.setVelocity(100, percent);
        beam1.setVelocity(100, percent);
        beam2.setVelocity(100, percent);
        int l = con.AxisA.position();
        int r = con.AxisD.position();
bool clamp_toggle;
bool claw_toggle;
bool aligner_toggle
        RF.spin(forward, r, rpm);
        LF.spin(forward, l, rpm);

        if(con.ButtonRUp.pressing()) {
            lift2.spin(forward);
            lift.spin(forward);
        }
            else if(con.ButtonRDown.pressing()) {
            lift2.spin(reverse);
            lift.spin(reverse);
            }
            else {
            lift2.spin(forward, 0, rpm);
            lift.spin(forward, 0, rpm);
            }



            if(con.ButtonLUp.pressing()) {
                beam1.spin(forward);
                beam2.spin(forward);
            }
        else if(con.ButtonLDown.pressing()) {
            beam1.spin(reverse);
            beam2.spin(reverse);
        }
        else {
            beam1.spin(forward, 0, rpm);
            beam2.spin(forward, 0, rpm );
        }

    



if(con.ButtonFDown.pressing()) {
   clamp_toggle=!clamp_toggle;
   wait(250, msec);
}


 if(clamp_toggle)  {
        clamp.extend(cylinder2);
    }
    else{
        clamp.retract(cylinder2);
    }
if(con.ButtonEDown.pressing()) {
    claw_toggle=!claw_toggle;
    wait(250, msec);
}
if(claw_toggle) {
    clamp.extend(cylinder1);
}
else {
    clamp.retract(cylinder1);
}

if(con.ButtonEUp.pressing()) {
    aligner_toggle=!aligner_toggle;
    wait(250, msec);
}

if(aligner_toggle) {
    aligner.extend(cylinder1);
}
else {
    aligner.retract(cylinder1);
}

//im writing more code
        // Allow other tasks to run
        wait(10, msec);
    }
}