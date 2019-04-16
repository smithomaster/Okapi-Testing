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

double liftkP = 0.001;
double liftkI = 0.0001;
double liftkD = 0.0001;

using namespace okapi::literals;
okapi::ChassisControllerIntegrated drive = okapi::ChassisControllerFactory::create(
    LEFT_MOTOR_PORT, RIGHT_MOTOR_PORT,
    okapi::AbstractMotor::gearset::green,
    {4_in, 11.5_in}
);

okapi::AsyncPosPIDController armController = okapi::AsyncControllerFactory::posPID(
    ARM_MOTOR_PORT, liftkP, liftkI, liftkD
);

bool alliance = false; // false red, true blue
int position = 0; // 0 left, 1 right
