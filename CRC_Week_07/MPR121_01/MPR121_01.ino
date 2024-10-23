// import our libraries
#include <Wire.h>
#include <Adafruit_MPR121.h>
#include <Servo.h>
 
#define shift 11 // used to convert from int to binary
 
Adafruit_MPR121 cap = Adafruit_MPR121(); // create our mpr121 object
Servo myservo;
 
int currtouched; // create integer to store our snapshot of touched pads
bool touchedPads[12] = { 0 }; // create an array of booleans, setting them all to 0
 
void setup() {
  Serial.begin(115200); // begin Serial
  myservo.attach(9); // attach our servo to pin 9
 
  // if the Arduino can't find the MPR121, tell us
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
 
  // tell us when it's ready
  Serial.println("MPR121 found!");
}
 
void loop() {
  checkTouched(); // take a snapshot of the currently touched pads
 
  // we use touchedPads[_] to check which pads are ON (1) or OFF (0)
  if (touchedPads[0] || touchedPads[11]) {
    // Servo animation 1 goes here:
    myservo.write(90);
    Serial.println("pad 11 or 0 touched");
  } else {
    // Servo "home" position goes here:
    myservo.write(0);
    Serial.println("no pads touched");
  }
  // put a delay so it isn't overwhelming
  delay(100);
}
 
void checkTouched() {
  currtouched = cap.touched(); // save our snapshot to the currtouched int variable
  for (int i = shift; i >= 0; i--) { // convert to binary!
    byte bit = bitRead(currtouched, i);
    touchedPads[i] = bit; // store it in our array
  }
}
 