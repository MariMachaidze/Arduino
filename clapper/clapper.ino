
int led = 13;
int normalMin = 200;
int normalMax = 300;
bool B = true;

void setup() {
  Serial.begin(9600);
 // pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  if(sensorValue >= normalMax && B == true){
    digitalWrite(led, HIGH);
    B = false;
    delay(10000);
  }
  else
  if(sensorValue >= normalMax && B == false){
    digitalWrite(led, LOW);
    B = true;
    delay(10000);
  }
  Serial.println(sensorValue);
  
}
