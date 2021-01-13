/*
 * Quadrupedal Robot Setup Sketch
 * Rob Reynolds
 * SparkFun Electronics
 * 
 * This simple sketch sets the joints of a
 * quadupedal robot to a neutral position,
 * then swings them slighty back and forth
 * simply to test control and movement.
 * Currently setup for 8 DoF, but can easily
 * be adjusted by changing to integer in
 * Servo leg[*] to correspond to the
 * number of servos.
 */


#include <Servo.h>

Servo leg[8];  // create servo objects to control a servo
int pos = 90;    // variable to store the servo position

void setup() {
  delay(1000);
  for (int l = 0; l < 8; l++){
    leg[l].attach(l + 2); // attach servos sequencially starting with pin 2
    delay(100);
  }
  delay(1000);
  for (int l = 0; l < 8; l++){
    leg[l].write(pos); // set all servos to 90°
    delay(100);
  }
}

void loop() {  
  allServoTest(); // Initial test or all servo movement  
  while(1){ 
  }
}

void allServoTest(){
  // Initial movement test for all servos. All servos are set to 90°.
  // then swept front and back before returning to 90° once again.

  for (int i = 0; i < 8; i++){
    for (pos = 90; pos <= 135; pos += 1) { 
      leg[i].write(pos);                   // tell servo to go to position in variable 'pos'
      delay(10);                           // wait 10ms for the servo to reach the position
    }
    for (pos = 135; pos >= 45; pos -= 1) { 
      leg[i].write(pos);                   // tell servo to go to position in variable 'pos'
      delay(10);                           // waits 15ms for the servo to reach the position
    }
    for (pos = 45; pos <= 90; pos += 1) { 
      leg[i].write(pos);                   // tell servo to go to position in variable 'pos'
      delay(10);                           // waits 15ms for the servo to reach the position
    }
  }
  
}
