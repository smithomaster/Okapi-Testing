#include "main.h"
#include "globals.hpp"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    using namespace okapi;

    // false red, true blue
    // 0 left, 1 right

    if (alliance == false) {
        if (position  == 0) {
            drive.turnAngle(-90_deg);
            drive.moveDistance(3.5_ft);
        } else if (position == 1) {
            drive.turnAngle(-90_deg);
            drive.moveDistance(7.5_ft);
        } else {
            drive.moveDistance(2_ft);
        }
    } else if (alliance == true) {
        if (position  == 0) {
            drive.turnAngle(90_deg);
            drive.moveDistance(7.5_ft);
        } else if (position == 1) {
            drive.turnAngle(90_deg);
            drive.moveDistance(3.5_ft);
        } else {
            drive.moveDistance(2_ft);
        }
    }
}
