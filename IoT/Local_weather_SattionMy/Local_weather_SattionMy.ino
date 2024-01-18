// IP Address 192.168.4.1
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>

// Replace with your network credentials
const char* ssid = "Climatesha";
const char* password = "22222222";

// Create an instance of the DHT sensor
#define DHTPIN D4 // Pin where the DHT11 sensor is connected
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Create an instance of the web server
ESP8266WebServer server(80);

void setup() {
  // Initialize DHT sensor
  dht.begin();

  // Set the NodeMCU as an access point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  // Define server routes
  server.on("/", HTTP_GET, handleRoot);
  server.on("/data", HTTP_GET, handleData);

  // Start the server
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Local Weather Server</h1>";
  html += "<p><a href='/data'>Get Weather Data</a></p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    server.send(500, "text/plain", "Error reading DHT sensor data.");
  } else {
    String response = "Temperature: " + String(temperature) + " °C\n";
    response += "Humidity: " + String(humidity) + " %\n";
    server.send(200, "text/plain", response);
  }
}
