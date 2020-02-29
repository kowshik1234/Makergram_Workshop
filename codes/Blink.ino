int led_pin = 5; //Initialize digital Pin 5 as LED pin

void setup() {
  pinMode(led_pin, OUTPUT); //If OUTPUT -> Writes Voltage
                            //If INPUT -> Reads Voltage
  Serial.begin(9600); // Begin Serial communication with speed of 9600 bits/sec
}

void loop() {
  digitalWrite(led_pin, HIGH); //Switching ON the LED
  Serial.println("LED is ON"); //Printing on Serial Monitor
  delay(1000); //LED will be ON for 1 second

  digitalWrite(led_pin, LOW); //Switching OFF the LED
  Serial.println("LED is OFF"); //Printing on Serial Monitor
  delay(1000); //LED will be OFF for 1 second
}
