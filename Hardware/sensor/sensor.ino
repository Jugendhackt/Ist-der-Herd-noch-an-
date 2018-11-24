int sensorpin = D3;
boolean state = false;
void setup() {
  pinMode(sensorpin,INPUT);
  Serial.begin(115200);
  
  // put your setup code here, to run once:

}

void loop() {
  state = digitalRead(sensorpin);
  Serial.println(state);
  delay(2000);
  
  // put your main code here, to run repeatedly:

}
