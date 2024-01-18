
 
#include <ESP8266WiFi.h>

const char AP_NameChar[] = "Ignites";      // Set Name for WiFi // YOU MUST CHANGE THE NAME
const char WiFiPassword[] = "11111111";       // Set Password for WiFi (Leave "" For Open WiFi)
 
WiFiServer server(80);
 
String header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
String html_1 = "<!DOCTYPE html><html><head><title>LED Control</title></head><body><div id='main'><h2>LED Control</h2>";
String html_2 = "<form id='F1' action='LEDON'><input class='button' type='submit' value='LED ON' ></form><br>";
String html_3 = "<form id='F2' action='LEDOFF'><input class='button' type='submit' value='LED OFF' ></form><br>";
String html_4 = "<form id='F2' action='LED1ON'><input class='button' type='submit' value='LED1 ON' ></form><br>";
String html_5 = "<form id='F2' action='LED1OFF'><input class='button' type='submit' value='LED1 OFF' ></form><br>";
String html_6 = "</div></body></html>";
 
String request = "";
int LED_Pin = D1;
int LED_Pin2 = D2;
 
void setup() 
{
    pinMode(LED_Pin, OUTPUT);
    pinMode(LED_Pin2, OUTPUT); 
 
    boolean conn = WiFi.softAP(AP_NameChar, WiFiPassword);
    server.begin();
 
} // void setup()
 
 
void loop() 
{
 
    // Check if a client has connected
    WiFiClient client = server.available();
    if (!client)  {  return;  }
 
    // Read the first line of the request
    request = client.readStringUntil('\r');
 
    if       ( request.indexOf("LEDON") > 0 )  { digitalWrite(LED_Pin, HIGH);  }
    else if  ( request.indexOf("LEDOFF") > 0 ) { digitalWrite(LED_Pin, LOW);   }
    
    else if  ( request.indexOf("LED1ON") > 0 ) { digitalWrite(LED_Pin2, HIGH);   }
    else if  ( request.indexOf("LED1OFF") > 0 ) { digitalWrite(LED_Pin2, LOW);   }
    client.flush();
 
    client.print( header );
    client.print( html_1 );
    client.print( html_2 );
    client.print( html_3 );
    client.print( html_4 );
    client.print( html_5 );
    client.print( html_6 );
 
    delay(5);
  // The client will actually be disconnected when the function returns and 'client' object is detroyed
 
} 
