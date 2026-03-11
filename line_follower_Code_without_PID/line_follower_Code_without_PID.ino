// ---------------- SENSOR PINS ----------------
#define S1 PA0
#define S2 PA1
#define S3 PA2
#define S4 PA3
#define S5 PA4

// ---------------- MOTOR PINS ----------------
#define ENA PA8
#define IN1 PB0
#define IN2 PB1

#define ENB PA9
#define IN3 PB5
#define IN4 PB6

int speed = 150;
int turnSpeed = 120;

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

  pinMode(PB12, OUPUT);
  digitalwrite(PB12, HIGH);
}

void loop() {

  int s1 = digitalRead(S1);
  int s2 = digitalRead(S2);
  int s3 = digitalRead(S3);
  int s4 = digitalRead(S4);
  int s5 = digitalRead(S5);

  // ---------- CENTER ----------
  if(s3 == LOW){
    forward();
  }

  // ---------- LEFT ----------
  else if(s2 == LOW){
    turnLeft();
  }

  else if(s1 == LOW){
    hardLeft();
  }

  // ---------- RIGHT ----------
  else if(s4 == LOW){
    turnRight();
  }

  else if(s5 == LOW){
    hardRight();
  }

  else{
    stopMotors();
  }

}

// ---------------- MOTOR FUNCTIONS ----------------

void forward(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, turnSpeed);
  analogWrite(ENB, speed);
}

void hardLeft(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnRight(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speed);
  analogWrite(ENB, turnSpeed);
}

void hardRight(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stopMotors(){
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
