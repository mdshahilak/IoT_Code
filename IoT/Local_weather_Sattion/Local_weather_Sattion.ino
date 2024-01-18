#include ESP8266WiFi.h
#include ESP8266WebServer.h
#include DHT.h

 Replace with your network credentials
const char ssid = Your_AP_SSID;
const char password = Your_AP_PASSWORD;

 Create an instance of the DHT sensor
#define DHTPIN D4  Pin where the DHT11 sensor is connected
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

 Create an instance of the web server
ESP8266WebServer server(80);

void setup() {
   Initialize DHT sensor
  dht.begin();

   Set the NodeMCU as an access point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

   Define server routes
  server.on(, HTTP_GET, handleRoot);
  server.on(data, HTTP_GET, handleData);

   Start the server
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = htmlbody;
  html += h1Local Weather Serverh1;
  html += pa href='data'Get Weather Dataap;
  html += bodyhtml;
  server.send(200, texthtml, html);
}

void handleData() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature)  isnan(humidity)) {
    server.send(500, textplain, Error reading DHT sensor data.);
  } else {
    String response = Temperature  + String(temperature) +  °Cn;
    response += Humidity  + String(humidity) +  %n;
    server.send(200, textplain, response);
  }
}
