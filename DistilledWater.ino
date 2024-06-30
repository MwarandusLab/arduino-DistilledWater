const int trigPin = 9;
const int echoPin = 10;
int Buzzer = 8;

void setup() {
  Serial.begin(9600); // Start the serial communication
  pinMode(trigPin, OUTPUT); // Set the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);  // Set the echoPin as an INPUT
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin and calculate the duration of the pulse:
  duration = pulseIn(echoPin, HIGH);

  // Check if the duration is valid
  if (duration > 0) {
    // Calculate the distance:
    distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  } else {
    // If the duration is invalid, set distance to -1 to indicate an error
    distance = -1;
  }

  // Print the distance on the Serial Monitor:
  if (distance > 10){
    digitalWrite(Buzzer, HIGH);
  } else {
    digitalWrite(Buzzer, LOW);
  }

  delay(1000); // Wait for a second before the next loop
}
