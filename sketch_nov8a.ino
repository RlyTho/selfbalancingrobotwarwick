
// Motor Control Pins
int motor1Pin1 = 8;  // Output 1 of L293D, controls direction of Motor 1
int motor1Pin2 = 2;  // Output 2 of L293D, controls direction of Motor 1
int enable1Pin = A2;  // Enable pin for Motor 1

int motor2Pin1 = 4;  // Output 3 of L293D, controls direction of Motor 2
int motor2Pin2 = 12;  // Output 4 of L293D, controls direction of Motor 2
int enable2Pin = 6; // Enable pin for Motor 2.

void setup() {
  // Define motor control pins as OUTPUT
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600); //Serial is an object that represents the serial communication interface in Arduino, serial.begin initializes the serial communication with a baud rate of 9600 bits per second. 
  // This specifies the speed at which data is transmitted over the serial communication interface.
  Serial.println("Motor Test"); // -  a function used to send data to the serial monitor, which is a tool within the Arduino IDE that allows you to view data and messages from your Arduino program.
}

void loop() {
  // Test Motor 1 (Forward, Stop, Reverse)
  Serial.println("Motor 1: Forward");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  analogWrite(enable1Pin, 255); // Full speed
  
  delay(2000); // Run forward for 2 seconds

  Serial.println("Motor 1: Stop");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  
  delay(1000); // Stop for 1 second

  Serial.println("Motor 1: Reverse");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  analogWrite(enable1Pin, 255); // Full speed

  delay(2000); // Run in reverse for 2 seconds

  // Stop Motor 1
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  
  // Test Motor 2 (Forward, Stop, Reverse)
  Serial.println("Motor 2: Forward");
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enable2Pin, 255); // Full speed
  
  delay(2000); // Run forward for 2 seconds

  Serial.println("Motor 2: Stop");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  
  delay(1000); // Stop for 1 second

  Serial.println("Motor 2: Reverse");
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(enable2Pin, 255); // Full speed

  delay(2000); // Run in reverse for 2 seconds

  // Stop Motor 2
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}
