#include "main.h"

#ifndef GLOBALS
#define GLOBALS

extern int ARM_MOTOR_PORT;
extern int CLAW_MOTOR_PORT;
extern int LEFT_MOTOR_PORT;
extern int RIGHT_MOTOR_PORT;

extern double liftkP;
extern double liftkI;
extern double liftkD;

extern okapi::Controller master;
extern okapi::ControllerButton armUpButton;
extern okapi::ControllerButton armDownButton;
extern okapi::ControllerButton clawCloseButton;
extern okapi::ControllerButton clawOpenButton;

extern okapi::ChassisControllerIntegrated drive;
extern okapi::Motor armMtr;
extern okapi::Motor clawMtr;

extern okapi::AsyncPosPIDController armController;

extern bool alliance;
extern int position;


#endif
