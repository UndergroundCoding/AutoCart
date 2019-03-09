/*
 * AutoCart: SpeedControl
 * Controls the motor ESC with a breadboard and two buttons. Check image in folder for controller
 * design.
 * 
 * Remember the ESC pins that must be connected are only the center (orange) pin to CONTROL (pin 3)
 * and the brown one to GROUD. For more info check the Arduino's Servo library web reference.
 */

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  
  pinMode(8, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  if(digitalRead(12) && digitalRead(12) && digitalRead(12))
  {
      myservo.write(180);              // tell servo to go to position in variable 'pos'
      Serial.println("FULL THROTTLE!");
  }
  else if(digitalRead(8) && digitalRead(8) && digitalRead(8))
  {
    Serial.println("FULL REVERSE!");
      myservo.write(0);              // tell servo to go to position in variable 'pos'
  }
  else
  {
    myservo.write(90);
    Serial.println("NEUTRAL");
  }
delay(15);
}
