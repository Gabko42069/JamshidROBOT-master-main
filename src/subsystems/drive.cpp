#include "lemlib/chassis/chassis.hpp"
#include "main.h"
static float TO_RADIANS = 0.0174533;

void tankDrive()
{
 int l_stick = controller.get_analog(ANALOG_LEFT_Y);
 int r_stick = controller.get_analog(ANALOG_RIGHT_Y);
 chassis.tank(l_stick, r_stick,0);
}

void setDriveBrake(pros::motor_brake_mode_e_t brake_type)
{
    left_side_motors.set_brake_modes(brake_type);
    right_side_motors.set_brake_modes(brake_type);
}

void moveIn(double inches, int tout, bool ays = false, bool f = true)
{
   lemlib::Pose current = chassis.getPose(true);
   float oldX = current.x;
   float oldY = current.y;
   float theta = current.theta;
    if(f)
    {
        int newX = oldX*cos(theta) + oldX;
        int newY = oldY*sin(theta) + oldY;
        chassis.moveTo(newX,newY,theta,tout,ays,true);
    }
    if(!f)
    {
        int newX = oldX*cos(theta) - oldX;
        int newY = oldY*sin(theta) - oldY;
        chassis.moveTo(newX,newY,theta,tout,ays,false);
    }
}
void turnDegrees(double changeTheta, int tout, bool right=true)
{
   lemlib::Pose current = chassis.getPose(true);
   float X = current.x;
   float Y = current.y;
   float oldtheta = current.theta;
   
 //  double toAngle=right?currentAngle+changeTheta:currentAngle-changeTheta;
   if(right)
   {
    lemlib::Pose newDeg = current.rotate(changeTheta * TO_RADIANS );
    float faceX = X + cos(newDeg.theta);
    float faceY = Y + sin(newDeg.theta);
    chassis.turnTo(faceX,faceY,tout);
   } else
   {
    lemlib::Pose newDeg = current.rotate(changeTheta * TO_RADIANS );
    float faceX = X - cos(newDeg.theta);
    float faceY = Y - sin(newDeg.theta);
    chassis.turnTo(faceX,faceY,tout);
   }

}


