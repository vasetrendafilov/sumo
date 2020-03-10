#include <ZumoMotors.h>
#define LED_PIN 13

ZumoMotors motors;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  
  // uncomment one or both of the following lines if your motors' directions need to be flipped
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);

  motors.setLeftSpeed(400);
  motors.setRightSpeed(368);
  delay(2000);

  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  delay(1000);
  
  motors.setLeftSpeed(400);
  motors.setRightSpeed(368);
  delay(2000);   

  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);
  delay(1000);
}

void loop()
{

}

void turnRight(int sp){
  motors.setLeftSpeed(sp);
  motors.setRightSpeed(-sp);
}
void turnLeft(int sp){
  motors.setLeftSpeed(-sp);
  motors.setRightSpeed(sp);
}
