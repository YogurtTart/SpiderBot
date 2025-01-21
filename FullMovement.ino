// Locate the initial position of legs 
// Modified for PCA9685 - 2025-01-17

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the servo parameters
const int servoMin = 150; // Minimum pulse length
const int servoMax = 600; // Maximum pulase length

// Define servos' channels on PCA9685
const int servo_channel[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };

// Map angles to PCA9685 pulse lengths
int angleToPulse(int angle) {
  return map(angle, 0, 180, servoMin, servoMax);
}

void setup() {

  pwm.begin();   // Initialize the PCA9685 driver
  pwm.setPWMFreq(60); // Set frequency to 60 Hz

  Serial.println("Servo service started");
  initial();
  delay(2000);
}

void loop() {

  //Standing Function
  Serial.println("Stand");
  stand();
  delay(2000);

  //walk function
  Serial.println("Walk");
  forward();
  delay(2000);

  //Sitting Function
  Serial.println("Sit");
  sit();
  delay(2000);

  //Wave Function
  Serial.println("Wave");
  wave();
  delay(2000);

  //Stand Function
  Serial.println("Stand");
  stand();
  delay(2000);
  
}

void initial(){

  Shoulder(135, 135, 45, 45);// 4, 13, 10, 7
  delay(2000); // Pause for 2 seconds after shoulder movements
  Elbows(140, 40, 40, 140);// 8 , 11 , 2 ,5 
  delay(2000); // Pause for 2 seconds after elbow movements
  Hands(70, 70, 110, 110);// 3, 12, 6, 9

}

void sit(){

  Elbows(140, 40, 40, 140);// 8 , 11 , 2 ,5 
  delay(1000); // Pause for 4 seconds after elbow movements

/* Extra feature
  for(int i = 0; i <3; i++){
  Hands(140, 140, 50, 50);// 3, 12, 6, 9
  delay(500); // Pause for 4 seconds after elbow movements
  Hands(70, 70, 110, 110);// 3, 12, 6, 9
  }
*/

}

void stand() {

 Elbows(100, 80, 80, 100); // 8 , 11 , 2 ,5  
 delay(1000); // Pause for 2 seconds after elbow movements
  
}

void wave() {

Elbows(140, 40, 20, 140);// 8 , 11 , 2 ,5 
delay(1000); // Pause for 2 seconds after elbow movements
Hands(150, 70, 110, 110);// 3, 12, 6, 9 

for(int i = 0; i <3; i++){
  Shoulder(155, 135, 45, 45);// 4, 13, 10, 7
  delay(200); // Pause for 4 seconds after elbow movements
  Shoulder(135, 135, 45, 45);// 4, 13, 10, 7
  }

  delay(200); // Pause for 4 seconds after elbow movements
  Hands(70, 70, 110, 110);// 3, 12, 6, 9
  delay(200); // Pause for 4 seconds after elbow movements
  Elbows(140, 40, 40, 140);// 8 , 11 , 2 ,5 

}

void forward(){

Shoulder(120, 125, 60, 55);// 4, 13, 10, 7
delay(500); 

Elbows(110, 70, 70, 110); // 8 , 11 , 2 ,5 


for(int i = 0; i <1; i++){

//top right leg
Elbows(110, 70, 60, 110); // 8 , 11 , 2 ,5 
delay(200);
Shoulder(160, 110, 60, 70);// 4, 13, 10, 7
delay(200);
Elbows(110, 70, 70, 110); // 8 , 11 , 2 ,5 
delay(500);


//btm left leg
Elbows(110, 60, 70, 110); // 8 , 11 , 2 ,5   
delay(200); 
Shoulder(160, 100, 60, 70);// 4, 13, 10, 7
delay(200);
Elbows(110, 70, 70, 110); // 8 , 11 , 2 ,5  
delay(500);


//btm right leg

Elbows(110, 70, 70, 120); // 8 , 11 , 2 ,5  
delay(200); 
Shoulder(160, 100, 60, 110);// 4, 13, 10, 7
delay(200);
Elbows(110, 70, 70, 110); // 8 , 11 , 2 ,5  
delay(500); 


//top left leg
Elbows(120, 70, 70, 110); // 8 , 11 , 2 ,5  
delay(200);
Shoulder(160, 80, 20, 100);// 4, 13, 10, 7
delay(200);
Elbows(110, 70, 70, 110); // 8 , 11 , 2 ,5 
delay(500); 


//Move all forward
Shoulder(120, 125, 60, 55);// 4, 13, 10, 7
delay(500);





}

}


void Shoulder(int A, int B, int C ,int D){
  // Leg 4 and 13 movement - Shoulders
  pwm.setPWM(servo_channel[0][2], 0, angleToPulse(A));
  delay(50); 
  pwm.setPWM(servo_channel[3][2], 0, angleToPulse(B));
  delay(50);

  // Leg 10 and 7 movement - Shoulders
  pwm.setPWM(servo_channel[2][2], 0, angleToPulse(C));
  delay(50);
  pwm.setPWM(servo_channel[1][2], 0, angleToPulse(D));
  delay(50);
}

void Elbows(int A, int B, int C ,int D){
  // Leg 8 and 11 movement - Elbows
  pwm.setPWM(servo_channel[2][0], 0, angleToPulse(A));
  delay(50);
  pwm.setPWM(servo_channel[3][0], 0, angleToPulse(B));
  delay(50);

  

  // Leg 2 and 5 movement - Elbows
  pwm.setPWM(servo_channel[0][0], 0, angleToPulse(C));
  delay(50);
  pwm.setPWM(servo_channel[1][0], 0, angleToPulse(D));
  delay(50);

  }

void Hands(int A, int B, int C ,int D){
  // Leg 3 and 12 movement - Hands
  pwm.setPWM(servo_channel[0][1], 0, angleToPulse(A));
  delay(50);
  pwm.setPWM(servo_channel[3][1], 0, angleToPulse(B));
  delay(50);

  // Leg 6 and 9 movement - Hands
  pwm.setPWM(servo_channel[1][1], 0, angleToPulse(C));
  delay(50);
  pwm.setPWM(servo_channel[2][1], 0, angleToPulse(D));
  delay(50);

}



