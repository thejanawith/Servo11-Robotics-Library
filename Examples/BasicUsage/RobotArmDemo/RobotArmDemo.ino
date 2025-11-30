/**
 * Robot Arm Demo for Servo11 Robotics Library
 * 
 * Created by: Geek Yaka Robotics
 * GitHub: https://github.com/geekyaka/Servo11-Robotics-Library
 * 
 * Demonstrates using Servo11 library for robot arm applications.
 * This example shows how to reconfigure servos for robotic arm control.
 */

#include <Servo11.h>

Servo11 robot;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("===========================================");
  Serial.println("🦾 Servo11 Robotics Library - Robot Arm Demo");
  Serial.println("📍 Created by: Geek Yaka Robotics");
  Serial.println("🌐 GitHub: github.com/geekyaka");
  Serial.println("===========================================");
  
  // Initialize servos
  robot.begin();
  
  // Set robot arm configuration (different ranges and initial positions)
  robot.setRobotArmConfiguration();
  
  // Custom names for robot arm application
  robot.setServoName(0, "Base Rotation");
  robot.setServoName(1, "Shoulder Joint");
  robot.setServoName(2, "Elbow Joint");
  robot.setServoName(3, "Wrist Pitch");
  robot.setServoName(4, "Wrist Roll");
  robot.setServoName(5, "Gripper");
  // Remaining servos can be used for additional joints
  
  // Move to arm-ready position
  uint8_t armReady[11] = {90, 45, 135, 90, 90, 90, 90, 90, 90, 90, 90};
  for (int i = 0; i < 11; i++) {
    robot.moveServoSmooth(i, armReady[i], 15);
    delay(200);
  }
  
  robot.printStatus();
  Serial.println("🎮 Robot Arm Demo Ready!");
  Serial.println();
}

void loop() {
  pickAndPlaceSequence();
  delay(3000);
  
  scanningSequence();
  delay(3000);
  
  wavingSequence();
  delay(3000);
}

void pickAndPlaceSequence() {
  Serial.println("📦 PICK AND PLACE SEQUENCE");
  Serial.println("──────────────────────────");
  
  // Move to pick position
  Serial.println("Moving to pick position...");
  robot.moveServoSmooth(1, 30, 10);  // Shoulder down
  robot.moveServoSmooth(2, 150, 10); // Elbow extended
  robot.moveServoSmooth(5, 180, 10); // Gripper open
  delay(1000);
  
  // Close gripper (pick object)
  Serial.println("Picking object...");
  robot.moveServoSmooth(5, 0, 5);    // Gripper close
  delay(1000);
  
  // Lift object
  Serial.println("Lifting object...");
  robot.moveServoSmooth(1, 90, 10);  // Shoulder up
  robot.moveServoSmooth(2, 90, 10);  // Elbow bent
  delay(1000);
  
  // Move to place position
  Serial.println("Moving to place position...");
  robot.moveServoSmooth(0, 135, 10); // Base rotate
  delay(1000);
  
  // Place object
  Serial.println("Placing object...");
  robot.moveServoSmooth(1, 30, 10);  // Shoulder down
  robot.moveServoSmooth(2, 150, 10); // Elbow extended
  delay(1000);
  robot.moveServoSmooth(5, 180, 5);  // Gripper open
  delay(1000);
  
  // Return to ready position
  Serial.println("Returning to ready position...");
  robot.moveServoSmooth(0, 90, 10);
  robot.moveServoSmooth(1, 45, 10);
  robot.moveServoSmooth(2, 135, 10);
  robot.moveServoSmooth(5, 90, 10);
  delay(1000);
  
  Serial.println("✅ Pick and place complete");
  Serial.println();
}

void scanningSequence() {
  Serial.println("🔍 SCANNING SEQUENCE");
  Serial.println("────────────────────");
  
  // Base rotation scan
  Serial.println("Scanning area...");
  for (int pos = 30; pos <= 150; pos += 10) {
    robot.moveServo(0, pos);
    delay(200);
  }
  
  for (int pos = 150; pos >= 30; pos -= 10) {
    robot.moveServo(0, pos);
    delay(200);
  }
  
  // Return to center
  robot.moveServoSmooth(0, 90, 10);
  
  // Vertical scan
  for (int pos = 30; pos <= 120; pos += 10) {
    robot.moveServoSmooth(1, pos, 5);
    delay(200);
  }
  
  for (int pos = 120; pos >= 30; pos -= 10) {
    robot.moveServoSmooth(1, pos, 5);
    delay(200);
  }
  
  // Return to ready position
  robot.moveServoSmooth(1, 45, 10);
  
  Serial.println("✅ Scanning complete");
  Serial.println();
}

void wavingSequence() {
  Serial.println("👋 ROBOT ARM WAVE");
  Serial.println("─────────────────");
  
  // Wave with robot arm
  for (int i = 0; i < 3; i++) {
    // Wave up
    robot.moveServoSmooth(1, 60, 8);
    robot.moveServoSmooth(2, 120, 8);
    robot.moveServoSmooth(3, 60, 8);
    delay(300);
    
    // Wave down
    robot.moveServoSmooth(1, 30, 8);
    robot.moveServoSmooth(2, 150, 8);
    robot.moveServoSmooth(3, 120, 8);
    delay(300);
  }
  
  // Return to ready position
  robot.moveServoSmooth(1, 45, 10);
  robot.moveServoSmooth(2, 135, 10);
  robot.moveServoSmooth(3, 90, 10);
  
  Serial.println("✅ Waving complete");
  Serial.println();
}
