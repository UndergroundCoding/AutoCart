# RoboCart, Half Robot : Half Cart.
Welcome to the RoboCart OFFICIAL repository.

RoboCart (from now on referred to as RC) is - or 'was', if in the future - a senior design project by a team from Florida Internation University. Our goal with this project is to graduate, but also to create something fun and interesting in the process.

This project's goal is to create an autonomous shopping cart that follows the user through the use of a physical token whilst avoiding incoming obstacles.

## How this project is organized
The RB repository is organized into 4 sections:
1. Obstacle Avoidance Module
2. Location Module
3. Motor Control
4. Brain

### Obtacle Avoidance Module (OAM)
OAM consists of a total of 10 ultrasonic sensors across the front and sides of AC. Its sole purpose it to alert the Brain if any obstacles are within 6 feet of distance of an object.

This module is divided into 3 sections, based on the location of the sensor:
1. Left and Right Side 
..Contain two sensors per side (Front, Back)
2 Front
..Contains 6 sensors (Left, Center, Right)

We are using 2 (or 3) arduinos to control all 

### Location Module (LM)
My baby-to-be...

This is the "GPS" of the machine. It will provide to the Brain the location of the token in reference to itself (the Brain).

LM consists of 4 ultra-wide band (UWB) modules (DWM1000):
1. 3 Anchors
..Two placed on the back (one near each motor) and one placed in the front (center)
2. 1 Tag
..Placed in a token that the user will carry.

Each UWB module has its own arduino.

### Motor Control (MC)
The motor control is exactly what it sounds. We are going to set up the motor in a way that both motors are controlled as one unit by the Brain. All the processing of how to control the actual, physical motor is done here inside the MC. The Brain controls the MC with commands such as turnRight(FULL), turnLeft(MILD), break(FULL).

It consists of 2 parts:
1. Left Motor
2. Right Motor

Notice that the motor is also responsible for the speed controller (which is what, in reality, drives the motor).  

Both motors are controlled by a single arduino.

### Brain
The Brain is the central processing unit of AC, a raspberry pi 3 b+. Here all data is processed and decisions made. 

###
"You think you do....... But you don't" - Richard

