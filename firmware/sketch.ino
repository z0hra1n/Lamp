#include <WiFi.h>
#include "time.h"

const char* ssid = "d2dh";
const char* password = "Ihazzz@123";

const int ledPin = 5;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);

  configTime(0, 0, "pool.ntp.org");

  ledcSetup(0, 5000, 8);
  ledcAttachPin(ledPin, 0);
}

void loop() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) return;

  int hour = timeinfo.tm_hour;

  if (hour >= 18 && hour < 23) {
    ledcWrite(0, 180);
  } else {
    ledcWrite(0, 0);
  }

  delay(10000);
}
