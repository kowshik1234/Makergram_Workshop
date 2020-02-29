int LDR = A0; // select the input pin for LDR
int LDRValue = 0; // variable to store the input value
int indication = 7; //Pin that shows indication
void setup()
{
  Serial.begin(9600); //Begins the Serial Communication
  pinMode(LDR, INPUT); //Set A2 as Input Port for receiving LDR values
  pinMode(indication,OUTPUT);//Set the indication light to high
}

void loop()
{
  LDRValue = analogRead(LDR); // Reads the value from the sensor
  Serial.println(LDRValue); // Prints the value on serial monitor

  if (LDRValue < 700) //Tune this value according to surroundings. 
  {
    digitalWrite(indication, HIGH); //Glow the light if sufficient light is not present
  }
  else
  {
    digitalWrite(indication, LOW);
  }
  delay(50); //Delay to stabilize

}
