//Arduino lazer tag setup, Created by Meep3454
// See github below for instructions on how to build
// 
// https://github.com/meep3454/Arduino-Lazer-Tag
// Please let me know if you liked my project!


// TEAM GREEN GUN 1, GEEN LED ON BOARD 
#include <IRremote.h>

const int buttonPin = 2;    
const int ledPin =  13;      
int RECV_PIN = 11; 
IRrecv irrecv(RECV_PIN);
decode_results results;
int redPin = 5;
int greenPin = 6;
int bluePin = 7;
int lazer = 9;
int piezo = 8;
IRsend irsend;
int buttonState = 0;    

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(lazer, OUTPUT);
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  

  setColor(125, 255, 0);

  irrecv.enableIRIn(); 
  
// Startup sound
digitalWrite(piezo, LOW);
delay(100);
digitalWrite(piezo, HIGH);
delay(200);
digitalWrite(piezo, LOW);
delay(250);
digitalWrite(piezo, HIGH);
delay(200);
digitalWrite(piezo, LOW);
delay(100);
digitalWrite(piezo, HIGH);
delay(250);
digitalWrite(piezo, LOW);
   
}

// Custom made function for activating the RGB LED 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red); 
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(0xa7889, 12);
        delay(40);
        digitalWrite(lazer, HIGH);
        delay(9);
        digitalWrite(piezo, HIGH);
        delay(5);
        digitalWrite(piezo, LOW);
        delay(100);
        digitalWrite(lazer,LOW);
        delay(100);
    
          }  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(lazer, LOW);
  }
 
  if (irrecv.decode(&results)) { 
      
     if (results.value == 0xA90) { 
          setColor(0, 0, 0);  
          setColor(255,0,0);
          delay(200); 

            digitalWrite(piezo, LOW);
            delay(100);
            digitalWrite(piezo, HIGH);
            delay(40);
            digitalWrite(piezo, LOW);
            delay(100);
            digitalWrite(piezo, HIGH);
            delay(40);
            digitalWrite(piezo, LOW);
            delay(100);
            digitalWrite(piezo, HIGH);
            delay(40);
            digitalWrite(piezo, LOW);
            delay(100);
            digitalWrite(piezo,HIGH);
            delay(40);
            digitalWrite(piezo , LOW);

            delay(1000); 
             
      setColor(150,150,0);
      delay(1000);
      setColor(0,255,0);
      delay(100);

      
      digitalWrite(piezo, LOW);
      delay(5);
      digitalWrite(piezo, HIGH);
      delay(5);
      digitalWrite(piezo, LOW);
      }

      
    irrecv.resume(); 
  }
  delay(100);
}
