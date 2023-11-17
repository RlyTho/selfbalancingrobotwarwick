

void setup()
{
   Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop()
{
  int current_angle = analogRead(A0);
  Serial.println(current_angle);
  delay(10);
}

