void setup() {
  pinMode(13,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {
  int t = 1000;
  digitalWrite(13,HIGH);
  delay(t);
  digitalWrite(13,LOW);
  delay(t);
  digitalWrite(10,HIGH);
  delay(t);
  digitalWrite(10,LOW);
  delay(t);
  digitalWrite(7,HIGH);
  delay(t);
  digitalWrite(7,LOW);
  delay(t);

}
