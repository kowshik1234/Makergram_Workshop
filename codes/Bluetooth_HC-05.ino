#include <SoftwareSerial.h>

int RX_pin = 3; //Digital Pin 3 as new RX Pin
int TX_pin = 2; //Digital Pin 2 as new TX Pin
SoftwareSerial BTserial(RX_pin, TX_pin); // 3 --> RX, 2 --> TX
 
String BT_data;//Data from the HC-05 module
String Arduino_data;//Data from the Arduino
 
void setup() 
{
    // start the serial communication with the computer
    Serial.begin(9600); 
    // start communication with the HC-05 using 9600
    BTserial.begin(9600);  
}
 
void loop()
{ 
    // Read from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {  
        BT_data = BTserial.readString(); //Read the data from bluetooth 
        Serial.println(BT_data);
    }
 
    // Read from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        Arduino_data =  Serial.readString();//Read the data from the arduino
        BTserial.println(Arduino_data);  
    }
}
