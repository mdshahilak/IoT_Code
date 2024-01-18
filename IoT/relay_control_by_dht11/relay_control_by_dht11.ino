/*************************************************************

  This example shows how value can be pushed from Arduino to
  the Blynk App.

  WARNING :
  For this example you'll need Adafruit DHT sensor libraries:
    https://github.com/adafruit/Adafruit_Sensor
    https://github.com/adafruit/DHT-sensor-library

  App dashboard setup:
    Value Display widget attached to V5
    Value Display widget attached to V6
    Button widget attached to V7 (for controlling the relay)
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID           "TMPL3_SoIW_LC"
#define BLYNK_TEMPLATE_NAME         "weather station"
#define BLYNK_AUTH_TOKEN            "aS73W1P6qvpKymQt4iSMCFZtYm9Ds_vx"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Redmi sha";
char pass[] = "123456789";

#define DHTPIN 14 // D5         // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

// Define the relay pin
const int relayPin = 12; // D6    Change to the pin you are using

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more than 10 values per second.
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);

  // Check if the temperature is greater than 30 degrees Celsius
  if (t > 34.0) {
    // Turn off the relay (assuming LOW is off and HIGH is on)
    digitalWrite(relayPin, HIGH);
  } else {
    // Turn on the relay
    digitalWrite(relayPin, LOW);
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);

  // Initialize the relay pin as an OUTPUT
  pinMode(relayPin, OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
}
