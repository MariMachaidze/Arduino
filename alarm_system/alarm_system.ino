
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 2, 3}; //connect to the column pinouts of the keypad

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


const int buzzer = 8; //buzzer to arduino pin 8
const int buttonPin = 2;
const int trigPin = 7; //2
const int echoPin = 6; //3
const int LED = 13;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600); 
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance= duration*0.034/2;

  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance<80){
   // while(digitalRead(buttonPin) == LOW){
      while(keypad.getKey() != '5'){
      digitalWrite(LED,HIGH);
          

      //buzzer part
                  
        tone(buzzer, 1000); // Send 1KHz sound signal...
    //    delay(30000);        // ...for 30 sec
      //  noTone(buzzer);     // Stop sound...
     //   delay(1000);        // ...for 1sec
      

    /*  //button part
          int buttonState = digitalRead(buttonPin);
          Serial.println(buttonState);
           if (buttonState == HIGH) {
              // turn LED on:
              digitalWrite(LED, HIGH);
              noTone(buzzer);     // Stop sound...
            }*/
    }  // }

    digitalWrite(LED,LOW);
    noTone(buzzer);     // Stop sound...

   // delay(60000); // 1 minute // 60 second
    for (int t = 0; t < 60; t++) {
       Serial.print("Cooldown Time: ");
       Serial.println( 60 - t );
       delay(1000);
    }
    
   }
  else{
    digitalWrite(LED,LOW);
    noTone(buzzer);     // Stop sound...

   //buz delay(60000); // 1 minute // 60 second
    
  }
}
