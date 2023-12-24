#include "lemlib/api.hpp"
#include "main.h"
#include "pros/adi.hpp"

extern bool lazyMode;
extern int elevationCount;

//Motors
extern pros ::Motor leftFront;
extern pros ::Motor leftMiddle;
extern pros ::Motor leftBack;
extern pros ::Motor rightFront;
extern pros ::Motor rightMiddle;
extern pros ::Motor rightBack;

extern pros ::Motor intake;
extern pros ::Motor cata;
extern pros ::Motor cata2;
extern pros ::Imu inertial;
extern pros ::Controller controller;

extern pros ::ADIPort leftWing;
extern pros ::ADIPort rightWing;
extern pros ::ADIPort blocker;    // piston
extern pros ::ADIPort limitswitch; // limit switch
extern pros ::ADIPort dblactingR;  // double acting solanoid on the right
extern pros ::ADIPort snglactingR; // single acting solanoid on the right
extern pros ::ADIPort dblactingL;  // double acting solanoid on the left
extern pros ::ADIPort snglactingL; // single acting solanoid on the left

extern pros ::Optical colorSensor;
extern pros ::Optical colorSensor2;
extern pros ::Imu inertial;

extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;

extern lemlib::Drivetrain_t drivetrain;
extern lemlib::OdomSensors_t sensors;
extern lemlib::ChassisController_t lateralController;
extern lemlib::ChassisController_t angularController;
extern lemlib::DriveCurveFunction_t driveCurve;

extern lemlib::Chassis chassis;

#define leftFrontPort 13
#define leftMiddlePort 12
#define leftBackPort 11
#define rightFrontPort 18
#define rightMiddlePort 17
#define rightBackPort 16

#define intakePort 20
#define cataPort 3
#define cata2Port 4
#define inertialPort 21
#define opticPort 10
#define opticPort2 14

#define limitswitchPort 'D'
#define leftWingPort 'A'
#define rightWingPort 'H'
#define blockerPort 'E'
#define dblactingRPort 'F'
#define snglactingRPort 'G'

#define dblactingLPort 'C'
#define snglactingLPort 'B'
