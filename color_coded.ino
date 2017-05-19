int red=8,green=9,blue=10,x;
int red_1 = 7, green_1 =6, blue_1=5;
int red_2 = 4, green_2 = 3, blue_2=2;
int tempo = 2700;

void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(22,INPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  do{}
  while(digitalRead(22)==0);
}

void loop()
{
  orange(0);
  red_on(0);
    bluePortal_1(tempo/8);
  green_on(0);
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
  red_off(0);
  bluePortal_1((tempo/8)-20);
    blue_on(20);
  orange_1(0);
  green_off(0);
    bluePortal(tempo/8);
  orange(0);
  red_on(0);
    bluePortal_1(tempo/8); //next is a double pass
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);//seven
  orange_1(0);
  blue_off(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
  green_on(0);
    bluePortal_1(tempo/8);//end of seven
  orange_1(0);
  red_off(0);
    bluePortal(tempo/8);//pick up
  orange(0);
  blue_on(0);
    bluePortal_1(tempo/8);
  orange_1(0);
  green_off(0);
    bluePortal(tempo/8);
  orange(0);
  red_on(0);
    bluePortal_1(tempo/8);//3time
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);
  blue_off(0);
    bluePortal(tempo/8);//3times
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);//2times
  green_on(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);
  red_off(0);
    bluePortal(tempo/8);
  orange(0);
  blue_on(0);
    bluePortal_1(tempo/8);//3
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);
  green_off(0);
    bluePortal(tempo/8);//6
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
    bluePortal_1(tempo/8);
  orange_1(0);
    bluePortal(tempo/8);
  orange(0);
  white_on(0);
    bluePortal_1(tempo/8);
  cyan_off(0);    
  
  
}

void orange(int t)
{
  analogWrite(red,240);
  analogWrite(green,100);
  analogWrite(blue,0);
  delay(t);
}

void orange_1(int t)
{
  analogWrite(red_1,240);
  analogWrite(green_1,100);
  analogWrite(blue_1,0);
  delay(t);
}

void bluePortal(int t)
{
  analogWrite(red,80);
  analogWrite(green,180);
  analogWrite(blue,238);
  delay(t);
}

void bluePortal_1(int t)
{
  analogWrite(red_1,80);
  analogWrite(green_1,180);
  analogWrite(blue_1,238);
  delay(t);
}


void red_up(int t)
{
  for(x=0;x<255;x++)
  {
    analogWrite(red,x);
    delay(t);
  }
}

void green_up(int t)
{
  for(x=0;x<255;x++)
  {
    analogWrite(green,x);
    delay(t);
  }
}

void blue_up(int t)
{
  for(x=0;x<255;x++)
  {
    analogWrite(blue,x);
    delay(t);
  }
}

void red_down(int t)
{
  for(x=255;x>0;x--)
  {
    analogWrite(red,x);
    delay(t);
  }
}

void green_down(int t)
{
  for(x=255;x>0;x--)
  {
    analogWrite(green,x);
    delay(t);
  }
}

void blue_down(int t)
{
  for(x=255;x>0;x--)
  {
    analogWrite(blue,x);
    delay(t);
  }
}

void yellow_up(int t)
{
  for(x=0;x<255;x++)
  {
    analogWrite(red,x);
    analogWrite(green,x);
    delay(t);
  }
}

void yellow_down(int t)
{
  for(x=255;x>0;x--)
  {
    analogWrite(red,x);
    analogWrite(green,x);
    delay(t);
  }
}

void magenta_up(int t)
{
  for(x=0;x<255;x++)
  {
    analogWrite(red,x);
    analogWrite(blue,x);
    delay(t);
  }
}

void magenta_down(int t)
{
  for(x=255;x>0;x--)
  {
    analogWrite(red,x);
    analogWrite(blue,x);
    delay(t);
  }
}

void cyan_up(int t)
{
  for(x=0;x<255;x++)
  {
    analogWrite(blue,x);
    analogWrite(green,x);
    delay(t);
  }
}

void cyan_down(int t)
{
  for(x=255;x>0;x--)
  {
    analogWrite(blue,x);
    analogWrite(green,x);
    delay(t);
  }
}

void white_up(int t)
{
  for(x=0;x<255;x++)
  {
    analogWrite(red,x);
    analogWrite(blue,x);
    analogWrite(green,x);
    delay(t);
  }
}

void white_down(int t)
{
  for(x=255;x>0;x--)
  {
    analogWrite(red,x);
    analogWrite(blue,x);
    analogWrite(green,x);
    delay(t);
  }
}

void red_on(int t)
{
  digitalWrite(red_2,HIGH);
  delay(t);
}

void red_off(int t)
{
  digitalWrite(red_2,LOW);
  delay(t);
}

void green_on(int t)
{
  digitalWrite(green_2,HIGH);
  delay(t);
}

void green_off(int t)
{
  digitalWrite(green_2,LOW);
  delay(t);
}

void blue_on(int t)
{
  digitalWrite(blue_2,HIGH);
  delay(t);
}

void blue_off(int t)
{
  digitalWrite(blue_2,LOW);
  delay(t);
}

void yellow_on(int t)
{
  digitalWrite(green_2,HIGH);
  digitalWrite(red_2,HIGH);
  delay(t);
}

void yellow_off(int t)
{
  digitalWrite(green_2,LOW);
  digitalWrite(red_2,LOW);
  delay(t);
}

void magenta_on(int t)
{
  digitalWrite(blue_2,HIGH);
  digitalWrite(red_2,HIGH);
  delay(t);
}

void magenta_off(int t)
{
  digitalWrite(blue_2,LOW);
  digitalWrite(red_2,LOW);
  delay(t);
}

void cyan_on(int t)
{
  digitalWrite(blue_2,HIGH);
  digitalWrite(green_2,HIGH);
  delay(t);
}

void cyan_off(int t)
{
  digitalWrite(blue_2,LOW);
  digitalWrite(green_2,LOW);
  delay(t);
}

void white_on(int t)
{
  digitalWrite(blue_2,HIGH);
  digitalWrite(red_2,HIGH);
  digitalWrite(green_2,HIGH);
  delay(t);
}

void white_off(int t)
{
  digitalWrite(blue_2,LOW);
  digitalWrite(red_2,LOW);
  digitalWrite(green_2,LOW);
  delay(t);
}
