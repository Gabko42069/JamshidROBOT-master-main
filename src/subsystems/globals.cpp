#include "lemlib/api.hpp"
#include "main.h"
#include "pros/adi.h"
#include "pros/adi.hpp"
#include "pros/motors.h"

bool lazyMode = false;
int elevationCount = 0; 

pros ::Motor leftFront(leftFrontPort, pros ::E_MOTOR_GEARSET_06, true);
pros ::Motor leftMiddle(leftMiddlePort, pros ::E_MOTOR_GEARSET_06, true);
pros ::Motor leftBack(leftBackPort, pros ::E_MOTOR_GEARSET_06, true);

pros ::Motor rightFront(rightFrontPort, pros ::E_MOTOR_GEARSET_06);
pros ::Motor rightMiddle(rightMiddlePort, pros ::E_MOTOR_GEARSET_06);
pros ::Motor rightBack(rightBackPort, pros ::E_MOTOR_GEARSET_06);

pros ::Motor intake(intakePort, pros ::E_MOTOR_GEARSET_06);
pros ::Motor cata(cataPort, pros ::E_MOTOR_GEARSET_06);
pros ::Motor cata2(cata2Port, pros::E_MOTOR_GEARSET_06, true);
pros ::Controller controller(pros ::E_CONTROLLER_MASTER);

pros ::ADIPort limitswitch(limitswitchPort,
                           pros::E_ADI_DIGITAL_IN); // limit switch
pros ::ADIPort leftWing(leftWingPort, pros::E_ADI_DIGITAL_OUT);
pros ::ADIPort rightWing(rightWingPort, pros::E_ADI_DIGITAL_OUT); // piston
pros ::ADIPort blocker(blockerPort, pros::E_ADI_DIGITAL_OUT);
pros ::ADIPort dblactingR(dblactingRPort, pros::E_ADI_DIGITAL_OUT);
pros ::ADIPort snglactingR(snglactingRPort, pros::E_ADI_DIGITAL_OUT);
pros ::ADIPort dblactingL(dblactingLPort, pros::E_ADI_DIGITAL_OUT);
pros ::ADIPort snglactingL(snglactingLPort, pros::E_ADI_DIGITAL_OUT);

pros ::Optical colorSensor(opticPort);
pros ::Optical colorSensor2(opticPort2);
pros::Imu inertial(inertialPort);

pros::MotorGroup left_side_motors({leftFront, leftMiddle, leftBack});
pros::MotorGroup right_side_motors({rightFront, rightMiddle, rightBack});

lemlib::Drivetrain_t drivetrain = {
    &left_side_motors, &right_side_motors, 13, 4, 300, 8};

lemlib::OdomSensors_t sensors = {nullptr, nullptr, nullptr, nullptr, &inertial};
lemlib::ChassisController_t lateralController = {
    10,  // kP 7.85
    30,  // kD 80
    1,   // smallErrorRange
    100, // smallErrorTimeout
    3,   // largeErrorRange
    500  // largeErrorTimeout
};       // slew rate
lemlib::ChassisController_t angularController = {
    3.56, // kP 3.78
    32,  // kD 31
    1,   // smallErrorRange
    100, // smallErrorTimeout
    3,   // largeErrorRange
    300  // largeErrorTimeout
};

lemlib::Chassis chassis(drivetrain, lateralController, angularController,
                        sensors);
