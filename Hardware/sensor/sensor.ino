#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

const char* ssid = "verschwoerhaus-legacy";
const char* password = "mitcodedieweltverbessern";
//const char* mqtt_server = "mqtt.stg.freifunk-iot.de";

WiFiClient espClient;

PubSubClient client(espClient);
int sensorpin = D3;
boolean state = false;
void setup() {
  pinMode(sensorpin,INPUT);
  Serial.begin(115200);
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
  
  // put your main code here, to run repeatedly:

}
