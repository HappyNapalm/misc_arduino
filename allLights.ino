//Light for any arduino with 13 output pins

void setup()
{
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Serial.println("Iskra is online");
}

void loop()
{
  light_up_single(11,0,10);
  light_down_single(9,255,10);
  light_up_single(10,0,10);
  light_down_single(11,255,10);
  light_up_single(9,0,10);
  light_down_single(10,255,10);
}

void turn_on(int pin,int t)
{
  digitalWrite(pin,HIGH);
  delay(t);
}

void turn_off(int pin,int t)
{
  digitalWrite(pin,LOW);
  delay(t);
}

void light_up_single(int pin,int power,int t)
{
  for (int x =power;x<255;x++)
  {
    analogWrite(pin,x);
    delay(t);
  }
}

void light_down_single(int pin, int power,int t)
{
  for (int x =power;x>0;x--)
  {
    analogWrite(pin,x);
    delay(t);
  }
}

void light_up_double(int pin1,int pin2,int power,int t)
{
  for (int x =power;x<255;x++)
  {
    analogWrite(pin1,x);
    analogWrite(pin2,x);
    delay(t);
  }
}

void light_down_double(int pin1,int pin2,int power,int t)
{
  for (int x =power;x>0;x--)
  {
    analogWrite(pin1,x);
    analogWrite(pin2,x);
    delay(t);
  }
}

void light_up_triple(int pin1,int pin2,int pin3,int power,int t)
{
  for (int x =power;x<255;x++)
  {
    analogWrite(pin1,x);
    analogWrite(pin2,x);
    analogWrite(pin3,x);
    delay(t);
  }
}

void light_down_triple(int pin1,int pin2,int pin3,int power,int t)
{
  for (int x =power;x>0;x--)
  {
    analogWrite(pin1,x);
    analogWrite(pin2,x);
    analogWrite(pin3,x);
    delay(t);
  }
}
