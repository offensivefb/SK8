
#include <SPI.h>                      //the communication interface with the modem
#include <RF24.h>                     //the library which helps us to control the radio modem

int msg;

RF24 radio(9,10);                     //5 and 10 are a digital pin numbers to which signals CE and CSN are connected.
                                      
const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem, that will receive data from Arduino.


void setup(void){
  Serial.begin(9600);
  radio.begin(); //it activates the modem.
  radio.openWritingPipe(pipe);
  radio.startListening ();
 
}

void loop(void){

  msg =  map (analogRead(A1), 478,1023,1500,2000);
  Serial.print(msg);
  Serial.print("\n");;
  delay(1);
  
radio.stopListening ();

  radio.write(&msg, sizeof(msg));
  
  radio.startListening ();
  }
