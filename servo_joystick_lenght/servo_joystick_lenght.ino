#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);
 
Servo myservo; 

int pos = 0;
int grad;    

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pos = 15;
  myservo.write(pos);
}

void loop() {

  for(pos = 10; pos < 180 ; pos++)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for(pos = 180; pos > 10; pos--)     // goes from 180 degrees to 0 degrees
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}
