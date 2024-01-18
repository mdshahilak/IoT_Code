#define BLYNK_TEMPLATE_ID "TMPL3McYTEIsA"
#define BLYNK_TEMPLATE_NAME "LED ON OFF"
#define BLYNK_AUTH_TOKEN "XXZxnNyswSgENsBIOJy_uGk-cPAnYr1i"


#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>


char ssid[] = "Redmi sha";
char pass[] = "123456789";

int ledpin = D3;


void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  Blynk.run();
}
BLYNK_WRITE(V1){
  int ledValue = param.asInt();
  if (ledValue == 1){
    digitalWrite(ledpin,HIGH);
    }
    else{
      digitalWrite(ledpin,LOW);
      }
  }
