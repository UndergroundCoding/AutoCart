/*
 *  RoboCart: Obstacle Avoidance  
 *  
 *  03/08/19
 *  Todo:
 *   * Make code less repetitive (array of sensor objects[x]?)
 *   * Arrange sensors by side
 *   * Comment behavior
 *   * Update Done/TODO whenever something has beem implemented/thought of
 *  Done:
 *   * Created GitHub
 *   * Added header
 *   * Copied modified library to local folder
 *   * goddamnit magno....
 */

#include "SR04.h"   // Use modified library in folder

#define minDistance 90.0

// Left sensor pins
#define trigL 2
#define echoLL 3
#define echoLR 5

// Center sensor pins
#define trigC 4
#define echoCL 7
#define echoCR 9

// Right sensor pins
#define trigR 10
#define echoRL 11
#define echoRR 13

// LED pin
#define ledL  12
#define ledC  8
#define ledR  6

// Sensor objects
SR04 usLL = SR04(echoLL, trigL);
SR04 usLR = SR04(echoLR, trigL);
SR04 usCL = SR04(echoCL, trigC);
SR04 usCR = SR04(echoCR, trigC);
SR04 usRL = SR04(echoRL, trigR);
SR04 usRR = SR04(echoRR, trigR);

void setup()
{
   Serial.begin(9600);
   delay(1000);

   pinMode(ledL, OUTPUT);
   pinMode(ledC, OUTPUT);
   pinMode(ledR, OUTPUT);
}

void loop()
{  
  if(usLL.Distance() < minDistance || usLR.Distance() < minDistance)
  {
    digitalWrite(ledL, HIGH);
  } 
  else {
    digitalWrite(ledL, LOW);
  }
   
  if(usCL.Distance() < minDistance || usCR.Distance() < minDistance)
  {
    digitalWrite(ledC, HIGH);
  }
  else
  {
    digitalWrite(ledC, LOW);
  }
   
  if(usRL.Distance() < minDistance || usRR.Distance() < minDistance)
  {
    digitalWrite(ledR, HIGH);
  } 
  else
  {
    digitalWrite(ledR, LOW);
  }

  // Why are these calls here? Probably unnecessary.
  // Remember each call to getDistance() takes a long time, so unnecessary calls
  // will reduce response time considerably.
  long usDistLL = usLL.getDistance();
  long usDistLR = usLR.getDistance();
  long usDistCL = usCL.getDistance();
  long usDistCR = usCR.getDistance();
  long usDistRL = usRL.getDistance();
  long usDistRR = usRR.getDistance();

  /*Serial.println("LL");
  Serial.println(usDistLL);
  Serial.println("LR");
  Serial.println(usDistLR);*/
  Serial.println("CL");
  Serial.println(usDistCL);
  Serial.println("CR");
  Serial.println(usDistCR);
  /*Serial.println("RL");
  Serial.println(usDistRL);
  Serial.println("RR");
  Serial.println(usDistRR);*/
}
