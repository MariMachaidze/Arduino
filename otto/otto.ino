#include <Otto9.h>
Otto9 Otto;

#define PIN_Trigger  8
#define PIN_Echo     9
#define PIN_Buzzer  13

void setup() {
  Serial.begin(9600);
  Otto.init(2, 3, 4, 5, true, A6, PIN_Buzzer, PIN_Trigger, PIN_Echo);
  Otto.home();

  pinMode(PIN_Trigger, OUTPUT);
  pinMode(PIN_Echo, INPUT);
  
}

void ultra(){
  digitalWrite(PIN_Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_Trigger, LOW);

  int duration = pulseIn(PIN_Echo, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.println(distance);
}

void loop() {
  
  ultra();
  Otto.walk(10,1000,-1);
  Otto.home();
  delay(500);
  
  ultra();
  Otto.turn(10,500,1);
  Otto.home();
  delay(500);
  
  ultra();
  Otto.bend(10,1000,-1);
  Otto.home();
  delay(500);
  Otto.shakeLeg(3,500,1);
  Otto.shakeLeg(3,500,-1);
  Otto.home();
  delay(500);
  Otto.jump(3,1000);
  Otto.home();
  delay(500);
}
