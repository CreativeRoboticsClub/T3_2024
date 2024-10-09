#define trigPin 4
#define echoPin 5

void setup() {
  Serial.begin(115200);
  //Trig sends the signal
  pinMode(trigPin, OUTPUT);
  //Echo recieves the reflected signal
  pinMode(echoPin, INPUT);
}

void loop() {
  long distance = measureDistance();
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