//#include <LiquidCrystal.h>

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 7; //2
const int echoPin = 6; //3
int LED = 13;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  pinMode(11,OUTPUT);
 // lcd.begin(16, 2);
}
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;

  //lcd.setCursor(0, 0);
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  
 // lcd.print("Distance: ");
 // lcd.println(distance);
  
  if(distance<100){
    digitalWrite(11,HIGH);
  }
  else{
    digitalWrite(11,LOW);
  }
}
