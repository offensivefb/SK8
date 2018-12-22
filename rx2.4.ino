#include <Servo.h>    //the library which helps us to control the servo motor
#include <SPI.h>      //the communication interface with the modem
#include <RF24.h>    //the library which helps us to control the radio modem

Servo myServo;        //define the servo name

RF24 radio(9,10);     /*This object represents a modem connected to the Arduino. 
                      Arguments 5 and 10 are a digital pin numbers to which signals 
                      CE and CSN are connected.*/

const uint64_t pipe = 0xE8E8F0F0E1LL; //the address of the modem,that will receive data from the Arduino.

int msg;
int ferma=1500;

void setup(){
   Serial.begin(9600);
  myServo.attach(3);//3 is a digital pin to which servo signal connected.
 // myServo.write(avvio);
  delay(1000);
  radio.begin();                    //it activates the modem.
  radio.openReadingPipe(1, pipe);   //determines the address of our modem which receive data.
  radio.startListening();   //enable receiving data via modem

  }
 

void loop(){
       if (radio.available ()) {
  radio.read (&msg, sizeof (msg));
  Serial.print(msg);
  Serial.print("\n");;
  delay(1);
  myServo.write(msg);
  delay(1);
       }  
 
  }

  
   
  
     
      
    
  

       
       
       
       
       
       
    
  

