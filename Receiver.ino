#include <RF24_config.h>
/*Receiver Code*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int led1 = 13;
int led2 = 12;
int led3 = 11;


RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop() {
  if (radio.available()) {
    char text[32] = "";
    while (radio.available()){
     radio.read(&text, sizeof(text));
       Serial.println(text);
      }
      
    if (strcmp(text,"60 KPH") == 0){
      delay(10);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    }
    
    else if (strcmp(text,"70 KPH") == 0){
      delay(10);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    }
    
    else if (strcmp(text,"80 KPH") == 0){
      delay(10);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    }
    else if (strcmp(text,"OFF") == 0){
      delay(10);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    }
  }

}

