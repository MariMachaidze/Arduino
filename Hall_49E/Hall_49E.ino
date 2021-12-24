#define Hall_Sensor_Pin A2

void setup() {
  pinMode(Hall_Sensor_Pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  float voltage;
  voltage = analogRead(Hall_Sensor_Pin);
  Serial.println(voltage);
  delay(50);
}
