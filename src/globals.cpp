#include "main.h"

int ARM_MOTOR_PORT =  3;
int CLAW_MOTOR_PORT =  8;
int LEFT_MOTOR_PORT =  1;
int RIGHT_MOTOR_PORT =  10;

okapi::Controller master;
okapi::ControllerButton armUpButton(okapi::ControllerDigital::L1);
okapi::ControllerButton armDownButton(okapi::ControllerDigital::L2);
okapi::ControllerButton clawOpenButton(okapi::ControllerDigital::A);
okapi::ControllerButton clawCloseButton(okapi::ControllerDigital::B);


okapi::Motor armMtr(ARM_MOTOR_PORT);
okapi::Motor clawMtr(CLAW_MOTOR_PORT);

using namespace okapi::literals;
okapi::ChassisControllerIntegrated drive = okapi::ChassisControllerFactory::create(
    LEFT_MOTOR_PORT, RIGHT_MOTOR_PORT,
    okapi::AbstractMotor::gearset::green,
    {4_in, 11.5_in}
);
