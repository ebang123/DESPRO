#include <RF24_config.h>
/*Transmitter Code*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>



RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

const int buttonPin = 6;     // the number of the pushbutton pin
const int led1 =  5;      // the number of the LED pin
const int led2 =  4;
const int led3 =  3;
int ledState = LOW;
boolean buttonState = LOW;
int pressed = 0;


void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (debounceButton(buttonState) == HIGH && buttonState == LOW){
    pressed++;
    buttonState = HIGH;
    }
    else if (debounceButton(buttonState) == LOW && buttonState == HIGH){
      buttonState = LOW;
      }
      if (pressed == 1){
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        const char text[] = "60 KPH";
        radio.write(&text, sizeof(text));
        delay(1000);
        
        }
      if (pressed == 2){
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        const char text[] = "70 KPH";
        radio.write(&text, sizeof(text));
        delay(1000);
        
        }
      if (pressed == 3){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        const char text[] = "80 KPH";
        radio.write(&text, sizeof(text));
        delay(1000);
        
        }
      if (pressed == 4){
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        const char text[] = "OFF";
        radio.write(&text, sizeof(text));
        delay(1000);
        pressed = 0;
        }
  }

  boolean debounceButton(boolean state){
    boolean stateNow = digitalRead(buttonPin);
    if(state!=stateNow){
      delay(10);
      stateNow = digitalRead(buttonPin);
      }
      return stateNow;
  }

