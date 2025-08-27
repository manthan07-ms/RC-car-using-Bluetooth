// Pin connections
#define ENA 9     // Enable A (PWM for speed control)
#define IN1 8     // Motor A
#define IN2 7
#define ENB 10    // Enable B (PWM for speed control)
#define IN3 6     // Motor B
#define IN4 5

// Ultrasonic Sensor pins
#define TRIG 3
#define ECHO 2

long duration;
int distance;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

// Function to move forward
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150); // Speed (0-255)
  analogWrite(ENB, 150);
}

// Function to stop
void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function to turn left
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

// Function to turn right
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
}

// Function to measure distance
int getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2; // in cm
  return distance;
}

void loop() {
  int dist = getDistance();
  Serial.print("Distance: ");
  Serial.println(dist);

  if (dist > 20) {
    forward();   // Move forward if path is clear
  } else {
    stopCar();   // Stop when obstacle is near
    delay(200);

    left();      // Try turning left
    delay(400);

    stopCar();   // Stop and check again
    delay(200);
  }
}
