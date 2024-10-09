#define trigPin 4
#define echoPin 5
long lastDistance;

void setup() {
  Serial.begin(115200);
  //Trig sends the signal
  pinMode(trigPin, OUTPUT);
  //Echo recieves the reflected signal
  pinMode(echoPin, INPUT);
  lastDistance = 0;
}

void loop() {
  long distance = measureDistance();
  distance = (lastDistance  0.75) + (distance * 0.25);
  lastDistance = distance;
  
  if (distance > 200) {
    //Code for is something is far away
  } else if (distance < 200 && distance > 100) {
    //Code for is something is a medium distance away
  } else {
    //Code for is something is close
  }

  Serial.print("Distance: ");
  Serial.println(distance);
}
  
void measureDistance() {
  long duration, result;
  // Turns the trigPin off
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sesend the signal
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  //Turn off the signal
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  result = (duration/2) / 29.1;
  return result;
}