#include <Servo.h>

Servo servo;

void setup() {
  //Tell Ardino which pin the Servo is connected to
  servo.attach(9);
  //Move the Servo to a starting position (0-180);
  servo.write(90);
  //Wait a second, so the Servo can move
  delay(1000);
}

void loop() {
  //Move the servo
  servo.write(0);
  //Give the servo time to move
  delay(1000);
  //Move the servo
  servo.write(180);
  //Give the servo time to move
  delay(1000);

}
