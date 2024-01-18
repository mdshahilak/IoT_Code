#define BLYNK_TEMPLATE_ID "TMPL3hH8pHgtG"
#define BLYNK_TEMPLATE_NAME "Soil Moisture"
#define BLYNK_AUTH_TOKEN "OiP9j80WPp-pYwdioDuI4rlXUpQmWZAT"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "PiBOTS MakerHub";
char pass[] = "00000000";

int moistureSensorPin = A0;
int relayPin = D1;
int moistureThreshold = 15;

BlynkTimer timer;

void sendMoistureData() {
  int moistureLevel = analogRead(moistureSensorPin);
  Blynk.virtualWrite(V1, moistureLevel);
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);

  // Send moisture data every 5 seconds
  timer.setInterval(500, sendMoistureData);
}

void loop() {
  Blynk.run();
  timer.run();

  int moistureLevel = analogRead(moistureSensorPin);
  Serial.println(moistureLevel);

  if (moistureLevel < moistureThreshold) {
    digitalWrite(relayPin, HIGH);
  } 
  else {
    digitalWrite(relayPin, LOW);
  }
}
