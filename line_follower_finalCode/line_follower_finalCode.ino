// ---------------- SENSOR PINS ----------------
#define S1 PA0
#define S2 PA1
#define S3 PA2
#define S4 PA3
#define S5 PA4

// ---------------- MOTOR PINS ----------------
#define ENA PA8
#define IN1 PB4
#define IN2 PB3

#define ENB PA9
#define IN3 PB5
#define IN4 PB6

// ---------------- PID CONSTANTS ----------------
float Kp = 25;
float Ki = 0;
float Kd = 15;

int baseSpeed = 140;

float error = 0;
float previousError = 0;
float integral = 0;
float derivative = 0;

void setup() {

  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  // ----------- SENSOR READ -----------
  int s1 = digitalRead(S1) == LOW ? 1 : 0;
  int s2 = digitalRead(S2) == LOW ? 1 : 0;
  int s3 = digitalRead(S3) == LOW ? 1 : 0;
  int s4 = digitalRead(S4) == LOW ? 1 : 0;
  int s5 = digitalRead(S5) == LOW ? 1 : 0;

  // ----------- ERROR CALCULATION -----------
  error = (-2*s1) + (-1*s2) + (0*s3) + (1*s4) + (2*s5);

  // ----------- PID -----------
  integral += error;
  derivative = error - previousError;

  float correction = (Kp * error) + (Ki * integral) + (Kd * derivative);

  previousError = error;

  // ----------- MOTOR SPEED -----------
  int leftSpeed = baseSpeed - correction;
  int rightSpeed = baseSpeed + correction;

  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  setMotor(leftSpeed, rightSpeed);
}

// ---------------- MOTOR CONTROL ----------------

void setMotor(int leftSpeed, int rightSpeed) {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, leftSpeed);
  analogWrite(ENB, rightSpeed);
}