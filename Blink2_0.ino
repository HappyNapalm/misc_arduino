/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 10;
int led1 = 9;
int led2 = 11;
int x = 0;
int y = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT); 
  Serial.begin(9600); 
}

// the loop routine runs over and over again forever:
void loop() {
  flip();
  colton();
  bastion();
  
  if (y==0)
  {
    kaiser();
  }
  else if(y==1)
  {
    imp();
  }
  else;
  {
    delay(1000);
  }
  
}

void colton()
{
  for(x=0;x<255;x++)
  {
    analogWrite(led2,x);
    delay(4);
  }
  
}

void james()
{
  for(x=0;x<255;x++)
  {
    analogWrite(led1,x);
    delay(4);
  }
}

void nathan()
{
  for(x=0;x<255;x++)
  {
    analogWrite(led,x);
    delay(4);
  }
  
}

void bastion()
{
  for(x=255;x>0;x--)
  {
    analogWrite(led2,x);
    delay(4);
  }
}

void kaiser()
{
  for(x=255;x>0;x--)
  {
    analogWrite(led1,x);
    delay(4);
  }
}

void imp()
{
  for(x=255;x>0;x--)
  {
    analogWrite(led,x);
    delay(4);
  }
}
void flip()
{
  y = random(2);
  Serial.println("flip");
  if (y==0)
  {
    james();
  }
  else if (y==1)
  {
    nathan();
  }
  else;
  { delay(1000);}
}

void oblivion()
{
  imp();
  bastion();
  kaiser();
}
