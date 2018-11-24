#include <ESP8266WiFi.h>
<<<<<<< HEAD
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

const char* ssid = "verschwoerhaus-legacy";
const char* password = "mitcodedieweltverbessern";
=======


>>>>>>> e9116c261b59730b98b4c70da8039c8775480b62
//const char* mqtt_server = "mqtt.stg.freifunk-iot.de";

WiFiClient espClient;

<<<<<<< HEAD
PubSubClient client(espClient);
=======
//PubSubClient client(espClient);
>>>>>>> e9116c261b59730b98b4c70da8039c8775480b62
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
  
  // put your main code here, to run repeatedly:

}
