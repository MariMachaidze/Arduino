#include <Servo.h>

int sensorPin = A0;
int servoPin  = 9;

int sensorValue = 0;
int servoGrad = 90;
int tolerance = 40;

Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode( sensorPin, INPUT);
  myservo.attach( servoPin );
  myservo.write( 0 );
  Serial.print(servoGrad);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if ( sensorValue < (512-tolerance) )
  {
    if (servoGrad < 180) servoGrad++;
  }

  if ( sensorValue > (512+tolerance) )
  {
    if (servoGrad > 0) servoGrad--;
  }

  myservo.write( servoGrad ); 

  Serial.print( servoGrad );
  Serial.print( " " );
  //myservo.write( 50 );

  delay(100);
}
