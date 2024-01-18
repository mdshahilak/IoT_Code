#define BLYNK_TEMPLATE_ID "TMPL3jmSkreE3"
#define BLYNK_TEMPLATE_NAME "LED ON OFF"
#define BLYNK_AUTH_TOKEN "8F__8skJZTkNYX2hpzH81kROcJTEDzEc"


#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>


char ssid[] = "PiBOTS MakerHub";
char pass[] = "00000000";

int relay = D3;


void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relay, OUTPUT);
}

void loop() {
  Blynk.run();
}
BLYNK_WRITE(V1){
  int relayval = param.asInt();
  if (relayval == 1){
    digitalWrite(relay,LOW);
    }
    else{
      digitalWrite(relay,HIGH);
      }
  }
