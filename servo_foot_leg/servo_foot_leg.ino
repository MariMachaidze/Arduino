#include <Servo.h>

Servo legLeft; 
Servo legRight;
Servo footLeft;
Servo footRight;

void setup() {
  
  legLeft.attach(2);
  legRight.attach(3);
  footLeft.attach(4);
  footRight.attach(5);

}

void loop() {

  legRight.write(0);

  delay(1000);

  legRight.write(45);

  delay(1000);

  legRight.write(90);

  delay(1000);
  
  legRight.write(45);

  delay(1000);
}
