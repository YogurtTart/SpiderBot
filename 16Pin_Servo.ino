// Locate the initial position of legs 
// Modified for PCA9685 - 2025-01-17

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the servo parameters
const int servoMin = 150; // Minimum pulse length
const int servoMax = 600; // Maximum pulse length

// Define servos' channels on PCA9685
const int servo_channel[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };

// Map angles to PCA9685 pulse lengths
int angleToPulse(int angle) {
  return map(angle, 0, 180, servoMin, servoMax);
}

void setup() {
  // Initialize the PCA9685 driver
  pwm.begin();
  pwm.setPWMFreq(60); // Set frequency to 60 Hz
  
  // Move all servos to their initial position
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pwm.setPWM(servo_channel[i][j], 0, angleToPulse(90));
      delay(20);
    }
  }
}

void loop() {

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      pwm.setPWM(servo_channel[i][j], 0, angleToPulse(90));
      delay(500);
    }
  }

}