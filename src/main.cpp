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
   motor LF(11, true);
   motor RF(5);
   motor lift(6, true);
   motor lift2(8, true);

   controller con = controller();

    while(true) {
        int l = con.AxisA.position();
        int r = con.AxisD.position();

        RF.spin(forward, r, rpm);
        LF.spin(forward, l, rpm);

        if(con.ButtonRUp.pressing()) {
            lift.spin(forward);
            lift2.spin(forward);
        }
            else if(con.ButtonRDown.pressing()) {
            lift.spin(reverse);
            lift.spin(reverse);
            }
            else {
            lift.spin(forward, 0, rpm);
            lift2.spin(forward, 0, rpm);
            }

//im writing more code
        // Allow other tasks to run
        wait(10, msec);
    }
}