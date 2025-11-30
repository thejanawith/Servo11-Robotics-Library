/**
 * Servo11 Robotics Library Implementation
 * Advanced 11-Servo Control System for Humanoid Robots
 * 
 * Created by: Geek Yaka Robotics
 * GitHub: https://github.com/geekyaka/Servo11-Robotics-Library
 */

#include "Servo11.h"

Servo11::Servo11() {
  initializeDefaults();
}

void Servo11::begin() {
  begin(servoPins);
}

void Servo11::begin(uint8_t pins[11]) {
  Serial.println("🤖 Servo11 Robotics Library Initializing...");
  Serial.println("📍 Setting up 11 servo controllers");
  
  for (uint8_t i = 0; i < 11; i++) {
    servoPins[i] = pins[i];
    if (servos[i].attach(servoPins[i])) {
      servos[i].write(initialPositions[i]);
      currentAngles[i] = initialPositions[i];
      Serial.print("  ✅ Servo ");
      Serial.print(i + 1);
      Serial.print(" (");
      Serial.print(servoNames[i]);
      Serial.println(") attached");
      delay(50);
    } else {
      Serial.print("  ❌ Servo ");
      Serial.print(i + 1);
      Serial.println(" failed to attach");
    }
  }
  isInitialized = true;
  Serial.println("🎉 Servo11 System Ready!");
  Serial.println("──────────────────────────────");
}

void Servo11::begin(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5,
                   uint8_t pin6, uint8_t pin7, uint8_t pin8, uint8_t pin9, uint8_t pin10,
                   uint8_t pin11) {
  uint8_t pins[11] = {pin1, pin2, pin3, pin4, pin5, pin6, pin7, pin8, pin9, pin10, pin11};
  begin(pins);
}

void Servo11::initializeDefaults() {
  // Default pin assignments for Arduino Mega
  uint8_t defaultPins[11] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  memcpy(servoPins, defaultPins, sizeof(defaultPins));
  
  // Default initial positions for humanoid robot
  uint8_t defaultInitials[11] = {59, 142, 90, 59, 73, 152, 52, 59, 66, 140, 40};
  memcpy(initialPositions, defaultInitials, sizeof(defaultInitials));
  
  // Default safety ranges for each servo
  uint8_t defaultMins[11] = {0, 142, 90, 0, 70, 140, 52, 24, 66, 140, 40};
  uint8_t defaultMaxs[11] = {180, 180, 135, 107, 180, 180, 180, 180, 180, 180, 180};
  memcpy(minRanges, defaultMins, sizeof(defaultMins));
  memcpy(maxRanges, defaultMaxs, sizeof(defaultMaxs));
  
  // Default servo inversion settings
  for (int i = 0; i < 11; i++) {
    inverted[i] = false;
  }
  
  // Default names with Sinhala/English descriptions
  String defaultNames[11] = {
    "Oluwa wateta (Upper Base)", 
    "Oluwa ussana (Upper Arm)", 
    "Oluwa Issarahata (Elbow)",
    "Wam atha karakawana (Right Hip)",
    "Wam atha Issarahata Passata (Right Thigh)", 
    "Wam atha Ehata mehata (Right Knee)",
    "Wam athe angili (Right Ankle)",
    "Dakunu atha karakawana (Left Hip)", 
    "Dakunu atha Issarahata Passata (Left Thigh)",
    "Dakunu atha Ehata mehata (Left Knee)", 
    "Dakunu athe angili (Left Ankle)"
  };
  for (int i = 0; i < 11; i++) {
    servoNames[i] = defaultNames[i];
  }
  
  // Initialize current angles
  memcpy(currentAngles, initialPositions, sizeof(initialPositions));
}

void Servo11::moveServo(uint8_t servoNum, uint8_t angle) {
  if (!isValidServo(servoNum)) return;
  
  uint8_t constrainedAngle = constrainAngle(servoNum, angle);
  uint8_t finalAngle = applyInversion(servoNum, constrainedAngle);
  
  servos[servoNum].write(finalAngle);
  currentAngles[servoNum] = constrainedAngle;
  
  Serial.print("🎯 Servo ");
  Serial.print(servoNum + 1);
  Serial.print(" (");
  Serial.print(servoNames[servoNum]);
  Serial.print(") → ");
  Serial.print(constrainedAngle);
  Serial.println("°");
}

void Servo11::moveServoSmooth(uint8_t servoNum, uint8_t angle, uint16_t delayTime) {
  if (!isValidServo(servoNum)) return;
  
  uint8_t constrainedAngle = constrainAngle(servoNum, angle);
  uint8_t current = currentAngles[servoNum];
  
  Serial.print("🔄 Smooth moving Servo ");
  Serial.print(servoNum + 1);
  Serial.print(" from ");
  Serial.print(current);
  Serial.print("° to ");
  Serial.print(constrainedAngle);
  Serial.println("°");
  
  if (current < constrainedAngle) {
    for (uint8_t pos = current; pos <= constrainedAngle; pos++) {
      uint8_t finalPos = applyInversion(servoNum, pos);
      servos[servoNum].write(finalPos);
      delay(delayTime);
    }
  } else {
    for (uint8_t pos = current; pos >= constrainedAngle; pos--) {
      uint8_t finalPos = applyInversion(servoNum, pos);
      servos[servoNum].write(finalPos);
      delay(delayTime);
    }
  }
  currentAngles[servoNum] = constrainedAngle;
}

void Servo11::moveMultipleServos(uint8_t servoNums[], uint8_t angles[], uint8_t count) {
  Serial.print("🤝 Moving ");
  Serial.print(count);
  Serial.println(" servos simultaneously");
  
  for (uint8_t i = 0; i < count; i++) {
    if (isValidServo(servoNums[i])) {
      moveServo(servoNums[i], angles[i]);
    }
  }
}

void Servo11::setInitialPositions() {
  Serial.println("🏠 Returning all servos to initial positions");
  for (uint8_t i = 0; i < 11; i++) {
    moveServoSmooth(i, initialPositions[i], 15);
    delay(100);
  }
  Serial.println("✅ All servos in initial positions");
}

void Servo11::testAllServos() {
  Serial.println("🧪 Starting comprehensive servo test");
  Serial.println("====================================");
  
  for (uint8_t i = 0; i < 11; i++) {
    Serial.println();
    Serial.print("🔧 Testing Servo ");
    Serial.print(i + 1);
    Serial.print(" (");
    Serial.print(servoNames[i]);
    Serial.println(")");
    Serial.print("   Range: ");
    Serial.print(minRanges[i]);
    Serial.print("° - ");
    Serial.print(maxRanges[i]);
    Serial.print("° | Initial: ");
    Serial.print(initialPositions[i]);
    Serial.println("°");
    
    // Test minimum range
    Serial.print("   Testing min (");
    Serial.print(minRanges[i]);
    Serial.println("°)...");
    moveServoSmooth(i, minRanges[i], 10);
    delay(500);
    
    // Test maximum range
    Serial.print("   Testing max (");
    Serial.print(maxRanges[i]);
    Serial.println("°)...");
    moveServoSmooth(i, maxRanges[i], 10);
    delay(500);
    
    // Return to initial
    Serial.print("   Returning to initial (");
    Serial.print(initialPositions[i]);
    Serial.println("°)...");
    moveServoSmooth(i, initialPositions[i], 10);
    delay(500);
    
    Serial.println("   ✅ Servo test complete");
  }
  Serial.println("====================================");
  Serial.println("🎉 All servos tested successfully!");
}

void Servo11::stopAllServos() {
  Serial.println("🛑 Stopping all servos");
  for (uint8_t i = 0; i < 11; i++) {
    if (servos[i].attached()) {
      servos[i].detach();
    }
  }
  isInitialized = false;
}

void Servo11::setServoRange(uint8_t servoNum, uint8_t minAngle, uint8_t maxAngle) {
  if (!isValidServo(servoNum)) return;
  minRanges[servoNum] = minAngle;
  maxRanges[servoNum] = maxAngle;
  Serial.print("📏 Servo ");
  Serial.print(servoNum + 1);
  Serial.print(" range set to ");
  Serial.print(minAngle);
  Serial.print("° - ");
  Serial.print(maxAngle);
  Serial.println("°");
}

void Servo11::setServoInitial(uint8_t servoNum, uint8_t initialAngle) {
  if (!isValidServo(servoNum)) return;
  initialPositions[servoNum] = constrainAngle(servoNum, initialAngle);
  Serial.print("🎯 Servo ");
  Serial.print(servoNum + 1);
  Serial.print(" initial position set to ");
  Serial.print(initialAngle);
  Serial.println("°");
}

void Servo11::setServoName(uint8_t servoNum, const String& name) {
  if (!isValidServo(servoNum)) return;
  servoNames[servoNum] = name;
  Serial.print("🏷️ Servo ");
  Serial.print(servoNum + 1);
  Serial.print(" renamed to: ");
  Serial.println(name);
}

void Servo11::setServoInverted(uint8_t servoNum, bool inverted) {
  if (!isValidServo(servoNum)) return;
  this->inverted[servoNum] = inverted;
  Serial.print("🔄 Servo ");
  Serial.print(servoNum + 1);
  Serial.println(inverted ? " set to inverted" : " set to normal");
}

uint8_t Servo11::getCurrentAngle(uint8_t servoNum) {
  if (!isValidServo(servoNum)) return 0;
  return currentAngles[servoNum];
}

String Servo11::getServoName(uint8_t servoNum) {
  if (!isValidServo(servoNum)) return "Invalid Servo";
  return servoNames[servoNum];
}

uint8_t Servo11::getMinAngle(uint8_t servoNum) {
  if (!isValidServo(servoNum)) return 0;
  return minRanges[servoNum];
}

uint8_t Servo11::getMaxAngle(uint8_t servoNum) {
  if (!isValidServo(servoNum)) return 0;
  return maxRanges[servoNum];
}

bool Servo11::isServoAttached(uint8_t servoNum) {
  if (!isValidServo(servoNum)) return false;
  return servos[servoNum].attached();
}

void Servo11::printStatus() {
  Serial.println();
  Serial.println("🤖 SERVO11 ROBOTICS SYSTEM STATUS");
  Serial.println("=================================");
  for (uint8_t i = 0; i < 11; i++) {
    Serial.print("Servo ");
    if (i < 9) Serial.print(" ");
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.print(servoNames[i]);
    Serial.print(" | Angle: ");
    if (currentAngles[i] < 100) Serial.print(" ");
    Serial.print(currentAngles[i]);
    Serial.print("° | Range: ");
    if (minRanges[i] < 100) Serial.print(" ");
    Serial.print(minRanges[i]);
    Serial.print("-");
    Serial.print(maxRanges[i]);
    Serial.print("° | ");
    Serial.println(servos[i].attached() ? "✅ Attached" : "❌ Detached");
  }
  Serial.println("=================================");
}

void Servo11::printDebugInfo() {
  Serial.println();
  Serial.println("🐛 SERVO11 DEBUG INFORMATION");
  Serial.println("============================");
  Serial.print("Library Version: 1.0.0\n");
  Serial.print("Initialized: ");
  Serial.println(isInitialized ? "Yes" : "No");
  Serial.print("Active Servos: ");
  uint8_t activeCount = 0;
  for (uint8_t i = 0; i < 11; i++) {
    if (servos[i].attached()) activeCount++;
  }
  Serial.println(activeCount);
  Serial.println("============================");
}

void Servo11::setHumanoidConfiguration() {
  Serial.println("👤 Setting Humanoid Robot Configuration");
  setOluwaConfiguration();
  setWamConfiguration();
  setDakunuConfiguration();
}

void Servo11::setRobotArmConfiguration() {
  Serial.println("🦾 Setting Robot Arm Configuration");
  // Different ranges for robot arm applications
  for (uint8_t i = 0; i < 11; i++) {
    setServoRange(i, 0, 180);
    setServoInitial(i, 90);
  }
}

void Servo11::setCustomConfiguration() {
  Serial.println("⚙️ Setting Custom Configuration");
  // Reset to defaults for custom setup
  initializeDefaults();
}

void Servo11::walkingSequence() {
  Serial.println("🚶 Playing Walking Sequence");
  // Simplified walking sequence
  moveServoSmooth(DAKUNU_ATHE_ANGILI, 60, 10);
  moveServoSmooth(WAM_ATHE_ANGILI, 120, 10);
  delay(500);
  setInitialPositions();
}

void Servo11::dancingSequence() {
  Serial.println("💃 Playing Dancing Sequence");
  for (int i = 0; i < 3; i++) {
    moveServoSmooth(OLUWA_WATETA, 30, 5);
    moveServoSmooth(WAM_ATHA_ISSARAHATA_PASSATA, 120, 5);
    moveServoSmooth(DAKUNU_ATHA_ISSARAHATA_PASSATA, 120, 5);
    delay(300);
    moveServoSmooth(OLUWA_WATETA, 100, 5);
    moveServoSmooth(WAM_ATHA_ISSARAHATA_PASSATA, 70, 5);
    moveServoSmooth(DAKUNU_ATHA_ISSARAHATA_PASSATA, 70, 5);
    delay(300);
  }
  setInitialPositions();
}

void Servo11::greetingSequence() {
  Serial.println("👋 Playing Greeting Sequence");
  moveServoSmooth(OLUWA_USSANA, 160, 10);
  moveServoSmooth(OLUWA_ISSARAHATA, 120, 10);
  delay(1000);
  // Wave motion
  for (int i = 0; i < 2; i++) {
    moveServoSmooth(OLUWA_ISSARAHATA, 100, 5);
    delay(200);
    moveServoSmooth(OLUWA_ISSARAHATA, 120, 5);
    delay(200);
  }
  setInitialPositions();
}

void Servo11::resetPosition() {
  setInitialPositions();
}

bool Servo11::isValidServo(uint8_t servoNum) {
  if (servoNum < 0 || servoNum > 10) {
    Serial.println("❌ Error: Invalid servo number. Must be 0-10 (Servo 1-11).");
    return false;
  }
  return true;
}

uint8_t Servo11::constrainAngle(uint8_t servoNum, uint8_t angle) {
  return constrain(angle, minRanges[servoNum], maxRanges[servoNum]);
}

uint8_t Servo11::applyInversion(uint8_t servoNum, uint8_t angle) {
  if (inverted[servoNum]) {
    return 180 - angle;
  }
  return angle;
}

// Private configuration methods for preset groups
void Servo11::setOluwaConfiguration() {
  // Oluwa group - Upper body servos
  setServoName(OLUWA_WATETA, "Oluwa wateta (Upper Base)");
  setServoName(OLUWA_USSANA, "Oluwa ussana (Upper Arm)");
  setServoName(OLUWA_ISSARAHATA, "Oluwa Issarahata (Elbow)");
  
  setServoRange(OLUWA_WATETA, 0, 180);
  setServoRange(OLUWA_USSANA, 142, 180);
  setServoRange(OLUWA_ISSARAHATA, 90, 135);
  
  setServoInitial(OLUWA_WATETA, 59);
  setServoInitial(OLUWA_USSANA, 142);
  setServoInitial(OLUWA_ISSARAHATA, 90);
}

void Servo11::setWamConfiguration() {
  // Wam group - Right side servos
  setServoName(WAM_ATHA_KARAKAWANA, "Wam atha karakawana (Right Hip)");
  setServoName(WAM_ATHA_ISSARAHATA_PASSATA, "Wam atha Issarahata Passata (Right Thigh)");
  setServoName(WAM_ATHA_EHATA_MEHATA, "Wam atha Ehata mehata (Right Knee)");
  setServoName(WAM_ATHE_ANGILI, "Wam athe angili (Right Ankle)");
  
  setServoRange(WAM_ATHA_KARAKAWANA, 0, 107);
  setServoRange(WAM_ATHA_ISSARAHATA_PASSATA, 70, 180);
  setServoRange(WAM_ATHA_EHATA_MEHATA, 140, 180);
  setServoRange(WAM_ATHE_ANGILI, 52, 180);
  
  setServoInitial(WAM_ATHA_KARAKAWANA, 59);
  setServoInitial(WAM_ATHA_ISSARAHATA_PASSATA, 73);
  setServoInitial(WAM_ATHA_EHATA_MEHATA, 152);
  setServoInitial(WAM_ATHE_ANGILI, 52);
}

void Servo11::setDakunuConfiguration() {
  // Dakunu group - Left side servos
  setServoName(DAKUNU_ATHA_KARAKAWANA, "Dakunu atha karakawana (Left Hip)");
  setServoName(DAKUNU_ATHA_ISSARAHATA_PASSATA, "Dakunu atha Issarahata Passata (Left Thigh)");
  setServoName(DAKUNU_ATHA_EHATA_MEHATA, "Dakunu atha Ehata mehata (Left Knee)");
  setServoName(DAKUNU_ATHE_ANGILI, "Dakunu athe angili (Left Ankle)");
  
  setServoRange(DAKUNU_ATHA_KARAKAWANA, 24, 180);
  setServoRange(DAKUNU_ATHA_ISSARAHATA_PASSATA, 66, 180);
  setServoRange(DAKUNU_ATHA_EHATA_MEHATA, 140, 180);
  setServoRange(DAKUNU_ATHE_ANGILI, 40, 180);
  
  setServoInitial(DAKUNU_ATHA_KARAKAWANA, 59);
  setServoInitial(DAKUNU_ATHA_ISSARAHATA_PASSATA, 66);
  setServoInitial(DAKUNU_ATHA_EHATA_MEHATA, 140);
  setServoInitial(DAKUNU_ATHE_ANGILI, 40);
}
