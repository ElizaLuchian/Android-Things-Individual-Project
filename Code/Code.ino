#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define BUZZER_PIN 5
#define BUTTON_PIN 23  // D5

unsigned long muteUntil = 0;
unsigned long lastDHTRead = 0;

float temp = 0;
float hum = 0;

void setup() {
  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  dht.begin();
}

void loop() {

  // 🔘 CITIRE BUTON NON-STOP
  if (digitalRead(BUTTON_PIN) == LOW) {
    muteUntil = millis() + 10000;
    Serial.println("MUTE ACTIVAT");
  }

  bool isMuted = millis() < muteUntil;

  // 🌡️ CITIRE DHT (la 2 sec)
  if (millis() - lastDHTRead > 2000) {
  lastDHTRead = millis();

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (!isnan(t) && !isnan(h)) {
    temp = t;
    hum = h;

    // ✅ ADD THIS
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" C | Hum: ");
    Serial.print(hum);
    Serial.println(" %");
  } else {
    Serial.println("Failed to read from DHT");
  }
}

  // 🔔 BUZZER
  if (!isMuted && temp > 26) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // 🖥️ DISPLAY
  display.clearDisplay();
  display.setTextColor(WHITE);

  int barWidth = map((int)temp, 15, 35, 0, 128);
  barWidth = constrain(barWidth, 0, 128);

  display.drawRect(0, 2, 128, 10, WHITE);
  display.fillRect(0, 2, barWidth, 10, WHITE);

  display.setTextSize(2);
  display.setCursor(0, 30);

  if (temp < 18) display.println("FRIG");
  else if (temp < 26) display.println("OK");
  else display.println("CALD");

  display.setTextSize(1);
  display.setCursor(80, 30);
  display.print(temp);
  display.println("C");

  display.setCursor(80, 45);
  display.print(hum);
  display.println("%");

  if (isMuted) {
    display.setCursor(0, 55);
    display.println("MUTED");
  }

  display.display();
}