/*
 * RaspbController
 * Receives 9bit input from raspberry and translate it into motor ESC
 * output. The raspberry generates its commands using /Brain/MotorControl
 * 
 */
#include <Servo.h>

#define TRANSFORM 62.5    // Forward rotation in servo motor is in range (1500,2000). (3bit integer * TRANSFORM) + 1500
                          // will place us in this range:
                          // (0x1 * TRANSFORM) + 1500 = 1562.5
                          // ...
                          // (0x7 * TRANSFORM) + 1500 = 2000

#define controlP 2    // Controller On/OFF switch

// Left motor pins
#define lMotorSP0 3   // Speed pin 0
#define lMotorSP1 4   // Speed pin 1
#define lMotorSP2 5   // Speed pin 2
#define lMotorDP 6    // Direction pin

// Right motor pins
#define rMotorSP0 7
#define rMotorSP1 8
#define rMotorSP2 9
#define rMotorDP 13

// ON/OFF indicator
#define lMotorControl 10  // Left ESC control pin
#define rMotorControl 11  // Right ESC control pin

// Motor objects
Servo lMotor;
Servo rMotor;

void setup()
{
  Serial.begin(9600);
  
  pinMode(controlP, INPUT);
  pinMode(lMotorSP0, INPUT);
  pinMode(lMotorSP1, INPUT);
  pinMode(lMotorSP2, INPUT);
  pinMode(lMotorDP, INPUT);
  pinMode(rMotorSP0, INPUT);
  pinMode(rMotorSP1, INPUT);
  pinMode(rMotorSP2, INPUT);
  pinMode(rMotorDP, INPUT);

  lMotor.attach(lMotorControl);
  rMotor.attach(rMotorControl);
}

void loop()
{  
  int control = digitalRead(controlP);
  Serial.println("CONTROL");
  Serial.println(control);

  // Left motor
  // Get speed
  int lMotorS = (digitalRead(lMotorSP2) << 2);    // Consume most significant bit
  lMotorS |= (digitalRead(lMotorSP2) << 1);   // Consume middle bit
  lMotorS |= digitalRead(lMotorSP2);    // Consume last bit
  lMotorS *= TRANSFORM;    // Convert speed. Read TRANSFORM definition
  int lMotorD = digitalRead(lMotorDP);    // Get direction
  // Output
  Serial.println("LEFT SPEED");
  Serial.println(lMotorS);
  Serial.println("LEFT DIR");
  Serial.println(lMotorD);

  // Right motor
  // Get speed
  int rMotorS = (digitalRead(rMotorSP2) << 2);
  rMotorS |= (digitalRead(rMotorSP2) << 1);
  rMotorS |= digitalRead(rMotorSP2);
  int rMotorD = digitalRead(rMotorDP);
  // Output
  rMotorS *= TRANSFORM;
  Serial.println("RIGHT SPEED");
  Serial.println(rMotorS);
  Serial.println("RIGHT DIR");
  Serial.println(rMotorD);

  // Control ESC
  while(digitalRead(controlP))
  {
    lMotor.writeMicroseconds(lMotorS);
    rMotor.writeMicroseconds(rMotorS);
  }  
}
