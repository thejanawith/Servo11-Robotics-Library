/**
 * Advanced Control Example for Servo11 Robotics Library
 * 
 * Created by: Geek Yaka Robotics
 * GitHub: https://github.com/geekyaka/Servo11-Robotics-Library
 * 
 * Demonstrates advanced features including:
 * - Complex movement sequences
 * - Multiple servo coordination
 * - Predefined animations
 * - Custom configurations
 */

#include <Servo11.h>

Servo11 robot;

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("==============================================");
  Serial.println("🤖 Servo11 Robotics Library - Advanced Demo");
  Serial.println("📍 Created by: Geek Yaka Robotics");
  Serial.println("🌐 GitHub: github.com/geekyaka");
  Serial.println("==============================================");
  
  // Initialize with custom pins
  robot.begin(2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
  
  // Set humanoid configuration
  robot.setHumanoidConfiguration();
  
  // Move to initial positions
  robot.setInitialPositions();
  delay(1000);
  
  // Print debug information
  robot.printDebugInfo();
  robot.printStatus();
  
  Serial.println("🎮 Advanced Demo Ready!");
  Serial.println();
}

void loop() {
  // Demo various movement sequences
  walkingSequence();
  delay(3000);
  
  dancingSequence();
  delay(3000);
  
  greetingSequence();
  delay(3000);
  
  waveMotion();
  delay(3000);
  
  bowSequence();
  delay(3000);
}

void walkingSequence() {
  Serial.println("🚶 WALKING SEQUENCE");
  Serial.println("───────────────────");
  
  for (int step = 0; step < 4; step++) {
    Serial.print("Step ");
    Serial.println(step + 1);
    
    // Right leg forward
    robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 100, 8);
    robot.moveServoSmooth(Servo11::WAM_ATHE_ANGILI, 70, 8);
    
    // Left leg back
    robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 50, 8);
    robot.moveServoSmooth(Servo11::DAKUNU_ATHE_ANGILI, 60, 8);
    
    delay(500);
    
    // Return to neutral
    robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 73, 8);
    robot.moveServoSmooth(Servo11::WAM_ATHE_ANGILI, 52, 8);
    robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 66, 8);
    robot.moveServoSmooth(Servo11::DAKUNU_ATHE_ANGILI, 40, 8);
    
    delay(300);
    
    // Left leg forward
    robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 100, 8);
    robot.moveServoSmooth(Servo11::DAKUNU_ATHE_ANGILI, 70, 8);
    
    // Right leg back
    robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 50, 8);
    robot.moveServoSmooth(Servo11::WAM_ATHE_ANGILI, 60, 8);
    
    delay(500);
    
    // Return to neutral
    robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 66, 8);
    robot.moveServoSmooth(Servo11::DAKUNU_ATHE_ANGILI, 40, 8);
    robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 73, 8);
    robot.moveServoSmooth(Servo11::WAM_ATHE_ANGILI, 52, 8);
    
    delay(300);
  }
  
  Serial.println("✅ Walking sequence complete");
  Serial.println();
}

void dancingSequence() {
  Serial.println("💃 DANCING SEQUENCE");
  Serial.println("───────────────────");
  
  // Dance move 1: Arm waves
  for (int i = 0; i < 3; i++) {
    robot.moveServoSmooth(Servo11::OLUWA_USSANA, 160, 5);
    robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 110, 5);
    delay(200);
    robot.moveServoSmooth(Servo11::OLUWA_USSANA, 142, 5);
    robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 90, 5);
    delay(200);
  }
  
  // Dance move 2: Leg kicks
  robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 120, 10);
  robot.moveServoSmooth(Servo11::WAM_ATHA_EHATA_MEHATA, 160, 10);
  delay(500);
  robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 73, 10);
  robot.moveServoSmooth(Servo11::WAM_ATHA_EHATA_MEHATA, 152, 10);
  delay(300);
  
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 120, 10);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_EHATA_MEHATA, 160, 10);
  delay(500);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 66, 10);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_EHATA_MEHATA, 140, 10);
  delay(300);
  
  // Dance move 3: Body sway
  for (int i = 0; i < 2; i++) {
    robot.moveServoSmooth(Servo11::OLUWA_WATETA, 30, 8);
    robot.moveServoSmooth(Servo11::WAM_ATHA_KARAKAWANA, 40, 8);
    robot.moveServoSmooth(Servo11::DAKUNU_ATHA_KARAKAWANA, 80, 8);
    delay(400);
    
    robot.moveServoSmooth(Servo11::OLUWA_WATETA, 100, 8);
    robot.moveServoSmooth(Servo11::WAM_ATHA_KARAKAWANA, 80, 8);
    robot.moveServoSmooth(Servo11::DAKUNU_ATHA_KARAKAWANA, 40, 8);
    delay(400);
  }
  
  // Return to initial positions
  robot.setInitialPositions();
  Serial.println("✅ Dancing sequence complete");
  Serial.println();
}

void greetingSequence() {
  Serial.println("👋 GREETING SEQUENCE");
  Serial.println("────────────────────");
  
  // Raise arm for greeting
  robot.moveServoSmooth(Servo11::OLUWA_USSANA, 160, 10);
  robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 120, 10);
  delay(1000);
  
  // Wave hand
  for (int i = 0; i < 3; i++) {
    robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 100, 5);
    delay(250);
    robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 120, 5);
    delay(250);
  }
  
  // Lower arm
  robot.moveServoSmooth(Servo11::OLUWA_USSANA, 142, 10);
  robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 90, 10);
  delay(500);
  
  // Nod head (using base)
  robot.moveServoSmooth(Servo11::OLUWA_WATETA, 80, 8);
  delay(300);
  robot.moveServoSmooth(Servo11::OLUWA_WATETA, 40, 8);
  delay(300);
  robot.moveServoSmooth(Servo11::OLUWA_WATETA, 59, 8);
  
  Serial.println("✅ Greeting sequence complete");
  Serial.println();
}

void waveMotion() {
  Serial.println("🌊 WAVE MOTION SEQUENCE");
  Serial.println("───────────────────────");
  
  // Create wave-like motion through all servos
  uint8_t wavePositions[11] = {80, 150, 100, 70, 100, 160, 80, 70, 100, 160, 80};
  
  // Move to wave positions
  for (int i = 0; i < 11; i++) {
    robot.moveServoSmooth(i, wavePositions[i], 10);
    delay(150);
  }
  
  delay(1000);
  
  // Return to initial positions in reverse order
  for (int i = 10; i >= 0; i--) {
    robot.moveServoSmooth(i, robot.getCurrentAngle(i), 10);
    delay(150);
  }
  
  robot.setInitialPositions();
  Serial.println("✅ Wave motion complete");
  Serial.println();
}

void bowSequence() {
  Serial.println("🙇 BOWING SEQUENCE");
  Serial.println("──────────────────");
  
  // Lean forward for bow
  robot.moveServoSmooth(Servo11::OLUWA_WATETA, 100, 10);
  robot.moveServoSmooth(Servo11::WAM_ATHA_KARAKAWANA, 40, 10);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_KARAKAWANA, 40, 10);
  robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 50, 10);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 50, 10);
  
  delay(1000);
  
  // Return to upright position
  robot.setInitialPositions();
  delay(500);
  
  Serial.println("✅ Bowing sequence complete");
  Serial.println();
}
