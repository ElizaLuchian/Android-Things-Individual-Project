# 🌡️ Smart Environment Monitor

The Smart Environment Monitor demonstrates how to build a simple IoT system using an ESP32 microcontroller that monitors ambient temperature and humidity and provides real-time feedback to the user. The system reads data from a DHT11 sensor, processes it, and displays the results on a 0.96" OLED screen.

Based on predefined temperature thresholds, the system activates an audible alert using a buzzer when the environment becomes too warm. Additionally, a push button allows the user to temporarily mute the buzzer for 10 seconds, improving usability and preventing continuous alerts.

This project highlights how embedded systems can integrate sensors, user interaction, and real-time feedback into a compact and efficient monitoring solution.


## 🎥 Demo

*(Upload your demo video to Teams and link it here if needed)*

---

## 🔌 Schematics

<img width="1600" height="796" alt="Schematics" src="https://github.com/user-attachments/assets/52099aaf-dee7-4bad-b768-69abeca72877" />


---

## 📦 Pre-requisites

### Hardware Components
The link for the devkit I bought containing some of my components, the others I borrowed:
https://www.emag.ro/kit-de-baza-pentru-incepatori-esp32-esp-32s-wifi-potrivit-pentru-invatarea-proiectelor-arduino-set-de-95-de-piese-cu-ambalaj-et000030/pd/DZMDW83BM/?utm_campaign=share_product&utm_source=mobile_dynamic_share&utm_medium=android

- **ESP32 Development Board (ESP-32S WiFi)**  
  https://www.espressif.com/en/products/socs/esp32

- **DHT11 Temperature and Humidity Sensor Module**  
  https://arduinogetstarted.com/tutorials/arduino-dht11
  
- **0.96" OLED Display SSD1306 (I2C, 128x64)**  
  https://controllerstech.com/arduino-ssd1306-oled-display-tutorial/
  
- **Active Buzzer**  
 https://www.net4web.de/downloads/datasheets/datasheet_active_buzzer_5v_english_190523.pdf

- **Tactile Push Button (4-pin switch)**  
  https://docs.arduino.cc/built-in-examples/digital/Button/

- **Breadboard (830 tie-points)**  
  https://busboard.com/BB830T

- **Jumper Wires (Male-Male / Male-Female)**  
  https://iotzone.in/blog/jumper-wire-types-uses-pin-configuration-and-complete-guide-for-electronics-projects

---

### Software Components

- **Arduino IDE**  
  https://www.arduino.cc/en/software/

- **ESP32 Board Package (Espressif Systems)**  
  https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html

- **Adafruit GFX Library**  
  https://github.com/adafruit/Adafruit-GFX-Library

- **Adafruit SSD1306 Library**  
  https://docs.arduino.cc/libraries/adafruit-ssd1306/

- **DHT Sensor Library (Adafruit)**  
  https://www.arduinolibraries.info/libraries/dht-sensor-library

- **Adafruit Unified Sensor Library**  
  https://docs.arduino.cc/libraries/adafruit-unified-sensor/

---

## ⚙️ Setup and Build

To set up the project, follow the steps below:

### 1. Install ESP32 Support
- Open Arduino IDE  
- Go to **File → Preferences**  
- Add the following URL: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
- Go to **Tools → Board → Boards Manager**  
- Install **ESP32 by Espressif Systems**

---

### 2. Install Required Libraries
- Open **Library Manager**
- Install:
- Adafruit GFX  
- Adafruit SSD1306  
- DHT sensor library  
- Adafruit Unified Sensor  

---

### 3. Hardware Connections

### ⚡ Power Rails
- ESP32 3.3V -> Breadboard + rail
- ESP32 GND -> Breadboard - rail

### 🌡️ DHT11 Temperature & Humidity Sensor
- VCC -> + rail
- GND -> - rail
- DATA -> GPIO 4

### 🔔 Buzzer
- GND -> - rail
- SIG -> GPIO 5

### 🖥️ OLED Display (I2C)
- VCC -> ESP32 3.3V
- GND -> ESP32 GND
- SDA -> GPIO 21
- SCL -> GPIO 22

### 🔘 Button
- Pin 1 -> ESP32 GND
- Opposite diagonal pin -> GPIO 23

---

### 4. Upload the Code
- Select **ESP32 Dev Module**  
- Select the correct COM port  
- Click **Upload**  
- If needed, press the **BOOT** button  

---

## ▶️ Running

To run the system, follow these steps:

1. Connect the ESP32 to your computer using a USB cable.

2. Open the Arduino IDE and ensure the correct board and port are selected:
 - Board: **ESP32 Dev Module**
 - Port: (your COM port)

3. Upload the code to the ESP32.

4. After upload, the system starts automatically.

5. Observe the OLED display:
 - A progress bar shows the temperature level
 - A message is displayed:
   - **FRIG**
   - **OK**
   - **CALD**

6. Monitor the buzzer:
 - Activates when temperature > 26°C
 - Stops automatically otherwise

7. Press the push button:
 - The buzzer is muted for 10 seconds
 - The display shows **"MUTED"**

8. (Optional) Open Serial Monitor:
 - Baud rate: **115200**
 - View live sensor values

---

## 📊 Project Features

- Real-time temperature and humidity monitoring  
- OLED graphical interface (bar + status text)  
- Threshold-based alert system  
- User interaction via button  
- Non-blocking logic using `millis()`  

---

## 🎯 Project Results

The system successfully demonstrates:
- Integration of multiple hardware components  
- Real-time sensor data processing  
- Interactive control via user input  
- Efficient embedded system design  

---


---

## 🚀 Future Improvements

- Mobile app integration (IoT Cloud / Blynk)  
- RGB LED indicators  
- Cloud data logging  
- Use of a more accurate sensor (DHT22)  
