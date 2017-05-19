void setup(){
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}

void loop(){
 int x = 0, y = 0; 
 x = analogRead(A0);
 delay(2200);
 y = analogRead(A0);
 Serial.println(x*0.00489);
 if (x*0.00489 <= 0.05)
 {
   digitalWrite(8,LOW);
   digitalWrite(7,HIGH);
 }
 else
 {
 if(x-y<x*0.04){
   digitalWrite(8,HIGH);
   digitalWrite(7,LOW);
 }
 else
 {
   digitalWrite(8,LOW);
   digitalWrite(7,HIGH);
 }
 }
  delay(100);
}
