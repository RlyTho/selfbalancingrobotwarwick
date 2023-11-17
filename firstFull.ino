// Motor Control Pins
int motor1Pin1 = 8;  // Output 1 of L293D, controls direction of Motor 1
int motor1Pin2 = 2;  // Output 2 of L293D, controls direction of Motor 1
int enable1Pin = 10;  // Enable pin for Motor 1

int motor2Pin1 = 4;  // Output 3 of L293D, controls direction of Motor 2
int motor2Pin2 = 12;  // Output 4 of L293D, controls direction of Motor 2
int enable2Pin = 6; // Enable pin for Motor 2
int gyroAnglePin = A0;

int setPoint = 520;

int lastError = 0;

int interval = 1;

float Kp = 100.0;
float Kd = 0.0;
float Ki = 0.0;

void setup() {
  // Define motor control pins as OUTPUT
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600); //Serial is an object that represents the serial communication interface in Arduino
  Serial.println("Motor Test");
}

void loop() {

  int angle = analogRead(gyroAnglePin);

  int error = setPoint - angle;

  int correction = Kp * error + Ki * (error + lastError) * interval - Kd * (error - lastError) / interval;

  lastError = error;

  int wheelSpeed = abs(correction);// / (512 * Kp) * 255;

  int upperDeadZone = 40;
  int lowerDeadZone = -40;

  //Serial.println(error);
  //Serial.println(wheelSpeed);
  //Serial.println(angle);
  Serial.println(wheelSpeed);

  // Test Motor 1 (Forward, Stop, Reverse)
  if (error < lowerDeadZone){
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    
    analogWrite(enable1Pin, wheelSpeed); // speed
    analogWrite(enable2Pin, wheelSpeed); // speed

  }

  if (error < lowerDeadZone){
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    
    analogWrite(enable1Pin, wheelSpeed); // speed
    analogWrite(enable2Pin, wheelSpeed); // speed

  }

  if (error >= lowerDeadZone && error <= upperDeadZone){
    //Serial.println(angle);
    analogWrite(enable1Pin, 0); // speed
    analogWrite(enable2Pin, 0);
  }
  
  delay(interval);
}

