#include "main.h"
#include "pros/misc.h"

void controlPistons() {
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
     if(elevationCount % 2 == 0)
     {
      dblactingL.set_value(1);
      dblactingR.set_value(1);
      snglactingL.set_value(0);
      snglactingR.set_value(0);
     }
     else{
      dblactingL.set_value(0);
      dblactingR.set_value(0);
      snglactingL.set_value(1);
      snglactingR.set_value(1);
     }
     elevationCount++;
  }
  if (controller.get_digital_new_press(DIGITAL_A)) {
    rightWing.set_value(!rightWing.get_value());
    leftWing.set_value(!leftWing.get_value());
  }
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
    blocker.set_value(!blocker.get_value());
  }
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
    rightWing.set_value(!rightWing.get_value());
  }
  if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    leftWing.set_value(!leftWing.get_value());
  }
}

void ledouble() {
  rightWing.set_value(!rightWing.get_value());
  leftWing.set_value(!leftWing.get_value());
}

void changeMode(pros::ADIPort wing) { wing.set_value(!wing.get_value()); }