/**
 * Servo11 Robotics Library
 * Advanced 11-Servo Control System for Humanoid Robots and Robotic Arms
 * 
 * Created by: Geek Yaka Robotics
 * Version: 1.0.0
 * License: MIT
 * GitHub: https://github.com/geekyaka/Servo11-Robotics-Library
 * 
 * Features:
 * - Control up to 11 servos simultaneously
 * - Predefined humanoid robot configurations
 * - Smooth movement with adjustable speed
 * - Custom angle limits for each servo
 * - Real-time status monitoring
 * - Named servo presets for intuitive control
 */

#ifndef Servo11_h
#define Servo11_h

#include <Arduino.h>
#include <Servo.h>

class Servo11 {
  public:
    // Constructor
    Servo11();
    
    // Initialization methods
    void begin();
    void begin(uint8_t pins[11]);
    void begin(uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4, uint8_t pin5,
               uint8_t pin6, uint8_t pin7, uint8_t pin8, uint8_t pin9, uint8_t pin10,
               uint8_t pin11);
    
    // Servo control methods
    void moveServo(uint8_t servoNum, uint8_t angle);
    void moveServoSmooth(uint8_t servoNum, uint8_t angle, uint16_t delayTime = 20);
    void moveMultipleServos(uint8_t servoNums[], uint8_t angles[], uint8_t count);
    void setInitialPositions();
    void testAllServos();
    void stopAllServos();
    
    // Configuration methods
    void setServoRange(uint8_t servoNum, uint8_t minAngle, uint8_t maxAngle);
    void setServoInitial(uint8_t servoNum, uint8_t initialAngle);
    void setServoName(uint8_t servoNum, const String& name);
    void setServoInverted(uint8_t servoNum, bool inverted);
    
    // Status methods
    uint8_t getCurrentAngle(uint8_t servoNum);
    String getServoName(uint8_t servoNum);
    uint8_t getMinAngle(uint8_t servoNum);
    uint8_t getMaxAngle(uint8_t servoNum);
    bool isServoAttached(uint8_t servoNum);
    void printStatus();
    void printDebugInfo();
    
    // Preset configurations
    void setHumanoidConfiguration();
    void setRobotArmConfiguration();
    void setCustomConfiguration();
    
    // Named servo presets for intuitive access
    enum ServoPreset {
      // Oluwa Group (Upper Body)
      OLUWA_WATETA = 0,           // Servo 1 - Shoulder/Neck
      OLUWA_USSANA,               // Servo 2 - Upper Arm
      OLUWA_ISSARAHATA,           // Servo 3 - Elbow
      
      // Wam Group (Right Side)
      WAM_ATHA_KARAKAWANA,        // Servo 4 - Right Hip
      WAM_ATHA_ISSARAHATA_PASSATA,// Servo 5 - Right Thigh
      WAM_ATHA_EHATA_MEHATA,      // Servo 6 - Right Knee
      WAM_ATHE_ANGILI,            // Servo 7 - Right Ankle
      
      // Dakunu Group (Left Side)
      DAKUNU_ATHA_KARAKAWANA,     // Servo 8 - Left Hip
      DAKUNU_ATHA_ISSARAHATA_PASSATA, // Servo 9 - Left Thigh
      DAKUNU_ATHA_EHATA_MEHATA,   // Servo 10 - Left Knee
      DAKUNU_ATHE_ANGILI          // Servo 11 - Left Ankle
    };

    // Predefined movement sequences
    void walkingSequence();
    void dancingSequence();
    void greetingSequence();
    void resetPosition();

  private:
    Servo servos[11];
    uint8_t servoPins[11] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    uint8_t currentAngles[11];
    uint8_t minRanges[11];
    uint8_t maxRanges[11];
    uint8_t initialPositions[11];
    bool inverted[11];
    String servoNames[11];
    bool isInitialized = false;
    
    void initializeDefaults();
    bool isValidServo(uint8_t servoNum);
    uint8_t constrainAngle(uint8_t servoNum, uint8_t angle);
    uint8_t applyInversion(uint8_t servoNum, uint8_t angle);
};

#endif
