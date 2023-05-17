
//This code serves to allow the servo to rotate, pause, and then rotate backwards.
//Uses standard arduino and dual servos rotating in opposite directions

#include <Servo.h>

const int SERVO_PIN_1 = 9;
const int SERVO_PIN_2 = 10;
const int TIME_SERVO = 540; // TIME_SERVO it takes for one extension (default 0.54 seconds)

bool servo_up = true;
bool servo_reverse = true;

Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
}

void activate_probe() {
  if (!servo_reverse) {
    for (int i = 0; i < 180; i++) { 
      servo1.write(i);
      servo2.write(180 - i);             
      delay(TIME_SERVO / 180.0);                      
    }

    for (int i = 180; i > 0; i--) { 
      servo1.write(i);           
      servo2.write(180 - i);             
      delay(TIME_SERVO / 180.0);            
    }

  } else {

    for (int i = 180; i > 0; i--) { 
      servo1.write(i);              
      servo2.write(180 - i);               
      delay(TIME_SERVO / 180.0);            
    }

    for (int i = 0; i < 180; i++) { 
      servo1.write(i);                
      servo2.write(180 - i);             
      delay(TIME_SERVO / 180.0);                      
    }
  }
}

void loop() {
  activate_probe();
  delay(1000);
}