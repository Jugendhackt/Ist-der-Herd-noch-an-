


























































#include <ESP8266WiFi.h>
<<<<<<< HEAD
#include "auth.h"
#include "ESP8266HTTPClient.h"
int id = 5;
=======
>>>>>>> 19eb06fd60acbf7d1214a455464b2989c4f29d96


//const char* mqtt_server = "mqtt.stg.freifunk-iot.de";

WiFiClient espClient;

//PubSubClient client(espClient);
int sensorpin = D3;
boolean state = false;
void setup() {
  pinMode(sensorpin,INPUT);
  Serial.begin(115200);
  Serial.println("ProgramStart");
  setup_wifi();
  // put your setup code here, to run once:

}

void setup_wifi() {

  delay(10);
  // Verbindung zu Freifunk aufbauen
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

 //only Station, no AP
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  state = digitalRead(sensorpin);
  Serial.println(state);
  delay(2000);
<<<<<<< HEAD
  state = !state;

    if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
       HTTPClient http;    //Declare object of class HTTPClient
     
       http.begin("http://http.stg.freifunk-iot.de/data/" + String(id));      //Specify request destination
       http.addHeader("Content-Type", "text/plain");  //Specify content-type header
     
       int httpCode = http.POST(String(state));   //Send the request
       String payload = http.getString();                  //Get the response payload
     
       Serial.println(httpCode);   //Print HTTP return code
       Serial.println(payload);    //Print request response payload

       http.end();

       http.begin("http://http.stg.freifunk-iot.de/data/" + String(id) + "?state=" + String(state));      //Specify request destination
       http.addHeader("Content-Type", "text/plain");  //Specify content-type header
     
       int httpCode2 = http.POST(String(state));   //Send the request
       String payload2 = http.getString();                  //Get the response payload
     
       Serial.println(httpCode2);   //Print HTTP return code
       Serial.println(payload2);    //Print request response payload
     
       http.end();  //Close connection
     
     }else{
     
        Serial.println("Error in WiFi connection");   
     
     }
=======

  // put your main code here, to run repeatedly:
>>>>>>> 19eb06fd60acbf7d1214a455464b2989c4f29d96

}
