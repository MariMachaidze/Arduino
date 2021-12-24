#include <SoftwareSerial.h>

//Bluetooth uses serial communication. So, we use many serial functions 
//in this sketch. 
const int LED = 13;
char switchstate;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  while(Serial.available()>0){ 
    switchstate = Serial.read();
    Serial.println(switchstate);
    delay(15);
    if(switchstate == '1'){
      digitalWrite(LED, HIGH);
    }
    else 
    if(switchstate == '0'){
      digitalWrite(LED, LOW);
    }
  }
}
