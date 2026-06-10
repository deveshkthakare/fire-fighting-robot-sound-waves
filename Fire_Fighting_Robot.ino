// 🔥 Fire Fighting Robot using Sound Waves (Final Code)

// -------- Pin Definitions --------
#define flamePin 7

#define trigPin 9
#define echoPin 10

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

#define speakerPin 6   // PAM8403 input

long duration;
int distance;

// -------- Setup --------
void setup() {

  pinMode(flamePin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);
}

// -------- Main Loop --------
void loop() {

  int flame = digitalRead(flamePin);

  // 🔥 FIRE DETECTED
  if (flame == LOW) {
    stopMotors();
    playSound();
  }
  else {
    stopSound();

    int dist = getDistance();

    if (dist > 0 && dist < 20) {
      stopMotors();
      delay(300);
      turnRight();
    } 
    else {
      moveForward();
    }
  }
}

// -------- FUNCTIONS --------

// 📡 Ultrasonic Distance Function
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

// 🚗 Move Forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// 🛑 Stop Motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// ↩️ Turn Right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);
}

// 🔊 Play Low Frequency Sound
void playSound() {
  tone(speakerPin, 40); // 40 Hz (30–60 Hz works best)
}

// 🔇 Stop Sound
void stopSound() {
  noTone(speakerPin);
}

How to post this code ?
