# Servo11 Robotics Library 🤖

![Version](https://img.shields.io/badge/version-1.0.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Platform](https://img.shields.io/badge/platform-Arduino%20%7C%20ESP32-orange)

Advanced Arduino library for controlling 11 servos with named configurations, smooth movement, and preset patterns for robotics projects.

## ✨ Features

- 🎯 **11-Servo Control** - Simultaneous control of 11 servos
- 🏷️ **Named Configurations** - Predefined servo groups (Oluwa, Wam, Dakunu)
- 📏 **Custom Ranges** - Individual angle limits for each servo
- 🚀 **Smooth Movements** - Adjustable speed smooth servo motion
- 🔧 **Easy Setup** - Simple initialization and configuration
- 📊 **Status Monitoring** - Real-time servo status tracking
- 🎭 **Preset Patterns** - Built-in movement sequences
- 🔌 **Multi-Platform** - Works with Arduino Mega, ESP32, and more

## 🛠️ Installation

### Arduino IDE
1. Click **Code → Download ZIP**
2. In Arduino IDE: **Sketch → Include Library → Add .ZIP Library**
3. Select the downloaded ZIP file

### PlatformIO
Add to your `platformio.ini`:
```ini
lib_deps = 
    https://github.com/yourusername/Servo11-Robotics-Library.git
