# 🌡️ Smart Environment Monitor

The Smart Environment Monitor demonstrates how to build a simple IoT system using an ESP32 microcontroller that monitors ambient temperature and humidity and provides real-time feedback to the user. The system reads data from a DHT11 sensor, processes it, and displays the results on a 0.96" OLED screen.

Based on predefined temperature thresholds, the system activates an audible alert using a buzzer when the environment becomes too warm. Additionally, a push button allows the user to temporarily mute the buzzer for 10 seconds, improving usability and preventing continuous noise.

This project highlights how embedded systems can integrate sensors, user interaction, and real-time feedback into a compact and efficient monitoring solution.

---

## 📸 Screenshots

*(Add images of your hardware setup and OLED display output here)*

---

## 🎥 Demo

*(Upload your demo video to Teams and link it here if needed)*

---

## 🔌 Schematics

*(Insert your schematic diagram created in Fritzing or CircuitCanvas here)*

---

## 📦 Pre-requisites

### Hardware
- ESP32 development board  
- DHT11 temperature and humidity sensor  
- 0.96" OLED display (SSD1306, I2C)  
- Active buzzer  
- Push button (4-pin tactile switch)  
- Breadboard  
- Jumper wires  

### Software
- Arduino IDE  
- ESP32 Board Package (Espressif Systems)  
- Required libraries:
  - Adafruit GFX  
  - Adafruit SSD1306  
  - DHT sensor library (Adafruit)  
  - Adafruit Unified Sensor  

---

## ⚙️ Setup and Build

To set up the project, follow the steps below:

### 1. Install ESP32 Support
- Open Arduino IDE  
- Go to **File → Preferences**  
- Add the following URL to *Additional Board Manager URLs*:
