#define BLYNK_TEMPLATE_ID "TMPL3McYTEIsA"
#define BLYNK_TEMPLATE_NAME "LED ON OFF"
#define BLYNK_AUTH_TOKEN "XXZxnNyswSgENsBIOJy_uGk-cPAnYr1i"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


const int redled = 14;//D5
const int greenled = 12;//D6
const int blueled = 13;//D7


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Redmi sha"; //your hotspot name
char pass[] = "123456789"; //your hotspot password name



BLYNK_WRITE(V0)

{
 int pinValue_R = param.asInt(); // assigning incoming value from pin V0 to a variable

  analogWrite(redled,pinValue_R);

}
BLYNK_WRITE(V1)

{
 int pinValue_G = param.asInt(); // assigning incoming value from pin V1 to a variable

  analogWrite(greenled,pinValue_G);
}
BLYNK_WRITE(V2)

{
 int pinValue_B = param.asInt(); // assigning incoming value from pin V2 to a variable

  analogWrite(blueled,pinValue_B);
}

void setup()
{
 Serial.begin(9600);
 delay(100);
 Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}
