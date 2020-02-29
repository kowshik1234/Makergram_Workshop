#include <SoftwareSerial.h>

int RX_pin = 4; //Digital Pin 4 as new RX Pin
int TX_pin = 2; //Digital Pin 2 as new TX Pin
SoftwareSerial BTserial(RX_pin, TX_pin); // 4 --> RX, 2 --> TX
int indicator = 8; //Indication light

String BT_data;//Data from the HC-05 module
String Arduino_data;//Data from the Arduino
 
void setup() 
{
    // start the serial communication with the computer
    Serial.begin(9600); 
    // start communication with the HC-05 using 9600
    BTserial.begin(9600);  
    pinMode(indicator,OUTPUT);
}
 
void loop()
{ 
    // Read from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        BT_data = BTserial.readString(); //Read the data from bluetooth 
        if(BT_data == "ON")
        {
         digitalWrite(indicator,HIGH);   
        }
        else if(BT_data == "OFF")
        {
          digitalWrite(indicator,LOW);
        }
        else
        {
          Serial.println("Enter Valid Command");
        }
    }
}
