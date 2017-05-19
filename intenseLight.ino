//Light for any arduino with 13 output pins

void setup()
{
  pinMode(7,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop()
{
  int red = 11,grn = 10, blu = 9,btn = 7,btnCount=0,up=0,down=255,pin;
  pin = red;
  
  do{}while(digitalRead(btn) == LOW);
  if(digitalRead(btn) == HIGH){
    btnCount++;
  }
  //color switching
  if(btnCount > 255){
    if(btnCount > 255 && pin == grn){
      btnCount = 0;
      pin = blu;
    }
    else {
      btnCount = 0;
      pin = grn;
    }
  }
  
  analogWrite(pin,btnCount);
  if(pin == blu && btnCount >255){
    analogWrite(red,btnCount);
    analogWrite(grn,btnCount);
    analogWrite(blu,btnCount);
  }
}
