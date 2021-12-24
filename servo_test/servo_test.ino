#include <Servo.h>

int servoPinOne  = 3;
//int servoPinTwo  = 4;

Servo myservo1,myservo2;

void setup() {
  Serial.begin(9600);
  myservo1.attach( servoPinOne );
  //myservo2.attach( servoPinTwo );
  myservo1.write( 0 );
  //myservo2.write( 0 );
}

void loop() {

  for(int i=0;i<=180;i++){
    myservo1.write( i ); 
   // myservo2.write( i ); 

    Serial.print( i );
    Serial.print( " " );
  }
  for(int i=180;i>=0;i--){
     myservo1.write( i ); 
    // myservo2.write( i ); 

    Serial.print( i );
    Serial.print( " " );
  }
  delay(100);
}
