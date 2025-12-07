void setup() {
  Serial.begin(9600);
}

void loop() {
  int f0 = analogRead(A0);
  int f1 = analogRead(A1);
  int f2 = analogRead(A2);
  int f3 = analogRead(A3);
  int f4 = analogRead(A4);

  // Send as CSV format: f0,f1,f2,f3,f4\n
  Serial.print(f0); Serial.print(",");
  Serial.print(f1); Serial.print(",");
  Serial.print(f2); Serial.print(",");
  Serial.print(f3); Serial.print(",");
  Serial.println(f4);   // last value ends with newline

  delay(2000);  // delay for readability
}
