//#pragma once 
#include "lemlib/asset.hpp"
#include "autons.hpp"
#include "main.h"
#include "pros/motors.h"

ASSET(right8_txt); // drives from under the bar to ram into the goal
ASSET(swingy10_txt);
ASSET(skills0_txt);
ASSET(clone3_txt);
ASSET(swing1_txt);
ASSET(clone5_txt);
ASSET(final_txt);
ASSET(final5ball_txt);
ASSET(swingy12_txt);
ASSET(unretard_txt);
int catashots = 0;

void sixBAll()
{
    /*
   chassis.setPose(30,-58,-90);
    rightWing.set_value(!rightWing.get_value());
    pros::delay(150);
    rightWing.set_value(!rightWing.get_value());
    pros::delay(300);
    setIntake(-127);
    chassis.moveTo(23,-58, -90, 2000, false,true,0,.06,50);
    pros ::delay(500);*/
    chassis.setPose(25,-58,-90);
    setIntake(-127);
    chassis.moveTo(22,-58,-90,1000,false,true,0,.06,50);
    pros::delay(500);
    chassis.moveTo(12,-58,-90,2000,false,true,0,.06,50);
    pros::delay(100);
    setIntake(0);
    chassis.follow(swingy12_txt, 1200,11,true,false);
    pros::delay(1000);
    changeMode(leftWing);
    pros::delay(400);
    changeMode(leftWing);
    pros::delay(5000);
    chassis.turnTo(66, -26, 1000, false, true);
    chassis.moveTo(69,-26,180,1800,false,false);
    chassis.follow(swingy10_txt, 5000,12);
    chassis.turnTo(50,-5,1000);//make aysnc for time cut
    setIntake(127);
    pros::delay(300);
    setIntake(-127);
    chassis.setPose(23,-23,60);
   // pros::delay(2000);
    chassis.turnTo(5,-4,1500);
    chassis.follow(unretard_txt, 1500, 10, true);
    pros ::delay(600);
    changeMode(rightWing);
    pros::delay(600);
    changeMode(rightWing);
    pros::delay(400);
    chassis.turnTo(45,-10,1500);
    chassis.moveTo(45,-10,90,1500,true);
    pros::delay(100);
    setIntake(127);
    pros::delay(800);
    setIntake(0);
    pros::delay(800);
    chassis.setPose(40,0,90);
    chassis.turnTo(8,-30,2000);
    chassis.moveTo(8,-35,-90,2000);

}


void autonskills()
{
    chassis.setPose(49,53,0);
    chassis.moveTo(62,0,0,1500,false, false);
    chassis.setPose(61,28,0);
    setDriveBrake(MOTOR_BRAKE_HOLD);
    chassis.follow(clone5_txt,3000,9);
    chassis.turnTo(-40,17,2000,false,true);
    pros::delay(2000);
    //chassis.setPose(57,42,100);
    while (true) {
    if (colorSensor.get_proximity() >= 70 ) {
      pros::delay(200);
      cataAysnc();
      catashots++;
    }
    pros ::delay(100);
    if (catashots >= 1) {
      break;
    }
    }
    chassis.moveTo(13,60,90,3000,false,false);
    chassis.follow(skills0_txt,3500,12,false,false);
    chassis.moveTo(-64,26,180,1500,false,false); // 1.31 1.88
    chassis.turnTo(-41,47,1000);
    chassis.follow(right8_txt,5000,11);
    chassis.turnTo(-48,0,2000,false,true);
}


void tester()
{
  setDriveBrake(pros::E_MOTOR_BRAKE_HOLD);
  chassis.setPose(0,0,0);
  chassis.turnTo(5, 0, 5000);
}


void fiveBall()
{
   chassis.setPose(30,-58,-90);
    rightWing.set_value(!rightWing.get_value());
    pros::delay(150);
    rightWing.set_value(!rightWing.get_value());
    pros::delay(300);
    setIntake(-127);
    chassis.moveTo(25,-58, -90, 2000, false,true,0,.06,50);
    pros ::delay(500);
    chassis.moveTo(12,-58,-90,2000,false);
    pros::delay(100);
    setIntake(0);
    chassis.follow(clone3_txt, 1500,11,true,false);
    pros::delay(1000);
    changeMode(leftWing);
    pros::delay(400);
    changeMode(leftWing);
    pros::delay(200);
    chassis.turnTo(61, -26, 1000, false, true);
    chassis.moveTo(64,-26,180,1800,false,false);
    chassis.follow(swingy10_txt, 5000,12);
    chassis.turnTo(50,-5,1000);//make aysnc for time cut
    setIntake(127);
    pros::delay(300);
    setIntake(-127);
    chassis.setPose(23,-23,60);
   // pros::delay(2000);
    chassis.turnTo(5,-3,1500);
    chassis.follow(unretard_txt, 1500, 10, true);
    pros ::delay(500);
    changeMode(rightWing);
    pros::delay(600);
    changeMode(rightWing);
    pros::delay(400);
    chassis.turnTo(53,-4,1000);
    setIntake(127);
    pros::delay(500);
    setIntake(0);
    chassis.turnTo(53, 4, 2000,false,true);
    pros::delay(100);
    chassis.follow(final5ball_txt, 1500, 15, true, false);
    pros::delay(300);
    ledouble();
    pros::delay(800);
    ledouble();
    chassis.moveTo(0,-48,225,2000);
    
}
/*

chassis.setPose(30,-58,-90);
    rightWing.set_value(!rightWing.get_value());
    cataBysnc();
    pros :: delay(100);
    rightWing.set_value(!rightWing.get_value());
    pros::delay(400);
    setIntake(-127);
    chassis.moveTo(20,-58, -90, 2000, false,true,0,.06,70);
    pros ::delay(400);
    chassis.moveTo(14,-58,-90,2000,false);
    pros::delay(200);
    setIntake(0);
    chassis.follow(right8_txt, 1500,10,true,false);
    pros::delay(1000);
    changeMode(leftWing);
    pros::delay(500);
    chassis.turnTo(75, -15,1500,false, true);
    changeMode(leftWing);
    pros ::delay(500);
    chassis.moveTo(75,-15,0,2000,false, false);
    chassis.follow(swingy0_txt, 2000, 10);
    pros::delay(1000);
    chassis.turnTo(50,-10,500,true);
    pros::delay(300);
    setIntake(127);
    pros ::delay(500);
    chassis.turnTo(10,-5,1000);
    setIntake(-127);
    chassis.moveTo(10,5,-35,2000);
    pros::delay(300);
    setIntake(0);

    */