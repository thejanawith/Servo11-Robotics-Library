/**
 * Basic Usage Example for Servo11 Robotics Library
 * 
 * Created by: Geek Yaka Robotics
 * GitHub: https://github.com/geekyaka/Servo11-Robotics-Library
 * 
 * Demonstrates basic servo control functionality with the Servo11 library.
 * This example shows how to initialize the system and control individual servos.
 */

#include <Servo11.h>

Servo11 robot;  // Create Servo11 object

void setup() {
  Serial.begin(115200);
  delay(1000);  // Wait for Serial to initialize
  
  Serial.println("==========================================");
  Serial.println("🤖 Servo11 Robotics Library - Basic Demo");
  Serial.println("📍 Created by: Geek Yaka Robotics");
  Serial.println("🌐 GitHub: github.com/geekyaka");
  Serial.println("==========================================");
  
  // Initialize servos with default pins (2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12)
  robot.begin();
  
  // Set humanoid robot configuration with named servos
  robot.setHumanoidConfiguration();
  
  // Move all servos to their initial positions
  robot.setInitialPositions();
  delay(1000);
  
  // Print system status
  robot.printStatus();
  
  Serial.println("🎮 Basic Demo Ready - Servo control starting...");
  Serial.println();
}

void loop() {
  // Demo sequence for Oluwa group (Upper Body)
  demoOluwaGroup();
  delay(2000);
  
  // Demo sequence for Wam group (Right Side)
  demoWamGroup();
  delay(2000);
  
  // Demo sequence for Dakunu group (Left Side)
  demoDakunuGroup();
  delay(2000);
  
  // Test all servos
  robot.testAllServos();
  delay(5000);
}

void demoOluwaGroup() {
  Serial.println("👤 DEMO: Oluwa Group (Upper Body)");
  Serial.println("──────────────────────────────────");
  
  // Control Oluwa wateta (Servo 1 - Upper Base)
  Serial.println("Moving Oluwa wateta (Upper Base)...");
  robot.moveServoSmooth(Servo11::OLUWA_WATETA, 100, 15);
  delay(1000);
  robot.moveServoSmooth(Servo11::OLUWA_WATETA, 59, 15);
  delay(1000);
  
  // Control Oluwa ussana (Servo 2 - Upper Arm)
  Serial.println("Moving Oluwa ussana (Upper Arm)...");
  robot.moveServoSmooth(Servo11::OLUWA_USSANA, 160, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::OLUWA_USSANA, 142, 10);
  delay(1000);
  
  // Control Oluwa Issarahata (Servo 3 - Elbow)
  Serial.println("Moving Oluwa Issarahata (Elbow)...");
  robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 120, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::OLUWA_ISSARAHATA, 90, 10);
  delay(1000);
  
  Serial.println("✅ Oluwa Group Demo Complete");
  Serial.println();
}

void demoWamGroup() {
  Serial.println("➡️ DEMO: Wam Group (Right Side)");
  Serial.println("────────────────────────────────");
  
  // Control Wam atha karakawana (Servo 4 - Right Hip)
  Serial.println("Moving Wam atha karakawana (Right Hip)...");
  robot.moveServoSmooth(Servo11::WAM_ATHA_KARAKAWANA, 80, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::WAM_ATHA_KARAKAWANA, 59, 10);
  delay(1000);
  
  // Control Wam atha Issarahata Passata (Servo 5 - Right Thigh)
  Serial.println("Moving Wam atha Issarahata Passata (Right Thigh)...");
  robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 120, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::WAM_ATHA_ISSARAHATA_PASSATA, 73, 10);
  delay(1000);
  
  // Control Wam atha Ehata mehata (Servo 6 - Right Knee)
  Serial.println("Moving Wam atha Ehata mehata (Right Knee)...");
  robot.moveServoSmooth(Servo11::WAM_ATHA_EHATA_MEHATA, 160, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::WAM_ATHA_EHATA_MEHATA, 152, 10);
  delay(1000);
  
  // Control Wam athe angili (Servo 7 - Right Ankle)
  Serial.println("Moving Wam athe angili (Right Ankle)...");
  robot.moveServoSmooth(Servo11::WAM_ATHE_ANGILI, 100, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::WAM_ATHE_ANGILI, 52, 10);
  delay(1000);
  
  Serial.println("✅ Wam Group Demo Complete");
  Serial.println();
}

void demoDakunuGroup() {
  Serial.println("⬅️ DEMO: Dakunu Group (Left Side)");
  Serial.println("──────────────────────────────────");
  
  // Control Dakunu atha karakawana (Servo 8 - Left Hip)
  Serial.println("Moving Dakunu atha karakawana (Left Hip)...");
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_KARAKAWANA, 100, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_KARAKAWANA, 59, 10);
  delay(1000);
  
  // Control Dakunu atha Issarahata Passata (Servo 9 - Left Thigh)
  Serial.println("Moving Dakunu atha Issarahata Passata (Left Thigh)...");
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 120, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_ISSARAHATA_PASSATA, 66, 10);
  delay(1000);
  
  // Control Dakunu atha Ehata mehata (Servo 10 - Left Knee)
  Serial.println("Moving Dakunu atha Ehata mehata (Left Knee)...");
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_EHATA_MEHATA, 160, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHA_EHATA_MEHATA, 140, 10);
  delay(1000);
  
  // Control Dakunu athe angili (Servo 11 - Left Ankle)
  Serial.println("Moving Dakunu athe angili (Left Ankle)...");
  robot.moveServoSmooth(Servo11::DAKUNU_ATHE_ANGILI, 80, 10);
  delay(1000);
  robot.moveServoSmooth(Servo11::DAKUNU_ATHE_ANGILI, 40, 10);
  delay(1000);
  
  Serial.println("✅ Dakunu Group Demo Complete");
  Serial.println();
}
