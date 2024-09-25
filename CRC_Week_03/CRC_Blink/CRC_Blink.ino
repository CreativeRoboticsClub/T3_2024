int LEDPin = 13;

void setup() {
  // Tell the Arduino what we need to use
  pinMode(LEDPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);                      
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW); 
  // wait for a second  
  delay(1000); 
