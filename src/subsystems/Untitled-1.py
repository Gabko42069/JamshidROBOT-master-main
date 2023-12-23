"""
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
"""
import math
TO_RADIANS = 0.0174533

def turnDegrees(changeTheta,right,pos):
    X,Y = pos[0],pos[1]
    newDeg = changeTheta * TO_RADIANS
    print(newDeg)
    if right:
        faceX = X + 45*math.sin(newDeg)
        faceY = Y + 45*math.cos(newDeg)
        return faceX,faceY

print(turnDegrees(45,True,[0,0]))

