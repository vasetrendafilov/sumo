/*Multytasking motor contorl by Nikola Stoimenov*/

#include <Arduino_FreeRTOS.h>
#include <ZumoMotors.h>

#define leftIR A0

ZumoMotors motors;

void TaskMotorControl(void *pvParameters);
void TaskSensorRead(void *pvParameters);

void setup() {
  xTaskCreate(TaskMotorControl, "Motor control", 128, NULL, 2, NULL);
  xTaskCreate(TaskSensorRead, "Senzori", 128, NULL, 2, NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}

 void TaskMotorControl(void *pvParameters __attribute__((unused))){
  for(;;){
    motors.setLeftSpeed(400);
    motors.setRightSpeed(368);
    vTaskDelay(133);
  
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    vTaskDelay(66);
    
    motors.setLeftSpeed(400);
    motors.setRightSpeed(368);
    vTaskDelay(133); 
  
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    vTaskDelay(66);
  }
 }
 
 void TaskSensorRead(void *pvParameters __attribute__((unused))){
  Serial.begin(9600);
  for(;;){
     Serial.println(analogRead(leftIR));
     vTaskDelay(14);
  }  
 }

void turnRight(int sp){
  motors.setLeftSpeed(sp);
  motors.setRightSpeed(-sp);
}
void turnLeft(int sp){
  motors.setLeftSpeed(-sp);
  motors.setRightSpeed(sp);
}
