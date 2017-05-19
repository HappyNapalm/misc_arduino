int red=11,green=10,blue=9,x,dice,y;

void setup()
{
  pinMode(11,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  //do{}
  //while(digitalRead(2)==0);
  
}

void loop()
{
  digitalWrite(2,HIGH);
  white_up(8);
  white_down(8);
  delay(1000);

  dice = 1+random(6);
  switch(dice)
  {
    case 1:
      red_up(4);
      red_down(4);
    break;
    case 2:
      green_up(4);
      green_down(4);
    break;
    case 3:
      blue_up(4);
      blue_down(4);
    break;
    case 4:
      yellow_up(4);
      yellow_down(4);
    break;
    case 5:
      magenta_up(4);
      magenta_down(4);
    break;
    case 6:
      cyan_up(4);
      cyan_down(4);
    break;
    case 7:
      red_up(4);
      green_up(4);
      blue_up(4);
      cyan_down(4);
      red_down(4);
    break;
    default:
      for(y=0;y<5;y++)
      {
        red_on(500);
        red_off(500);
      }
    break;
  }
  digitalWrite(2,LOW);
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
  digitalWrite(red,HIGH);
  delay(t);
}

void red_off(int t)
{
  digitalWrite(red,LOW);
  delay(t);
}

void green_on(int t)
{
  digitalWrite(green,HIGH);
  delay(t);
}

void green_off(int t)
{
  digitalWrite(green,LOW);
  delay(t);
}

void blue_on(int t)
{
  digitalWrite(blue,HIGH);
  delay(t);
}

void blue_off(int t)
{
  digitalWrite(blue,LOW);
  delay(t);
}

void yellow_on(int t)
{
  digitalWrite(green,HIGH);
  digitalWrite(red,HIGH);
  delay(t);
}

void yellow_off(int t)
{
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
  delay(t);
}

void magenta_on(int t)
{
  digitalWrite(blue,HIGH);
  digitalWrite(red,HIGH);
  delay(t);
}

void magenta_off(int t)
{
  digitalWrite(blue,LOW);
  digitalWrite(red,LOW);
  delay(t);
}

void cyan_on(int t)
{
  digitalWrite(blue,HIGH);
  digitalWrite(green,HIGH);
  delay(t);
}

void cyan_off(int t)
{
  digitalWrite(blue,LOW);
  digitalWrite(green,LOW);
  delay(t);
}

void white_on(int t)
{
  digitalWrite(blue,HIGH);
  digitalWrite(red,HIGH);
  digitalWrite(green,HIGH);
  delay(t);
}

void white_off(int t)
{
  digitalWrite(blue,LOW);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  delay(t);
}
