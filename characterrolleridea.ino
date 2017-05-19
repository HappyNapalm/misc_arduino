 int a = 0;
 int b = 0;
 int c = 0;
 int d = 0;
 int e = 0;
 
void setup()
{Serial.begin(9600);
}

void loop()
{
  a =random(1,7);
  b =random(1,7);
  c =random(1,7);
  d =random(1,7);
  attribute();
  
}

void attribute()
{
  if (a < b,c,d)
  {
    e = b + c + d;
    Serial.print(e);
  }
  else if (b < a,c,d)
  {
    e = a + c + d;
    Serial.print(e);
  }
  else if (c < b,a,d)
  {
    e= b + a + d;
    Serial.print(e);
  }
  else if (d < b,c,a)
  {
    e= b + c + a;
    Serial.print(e);
  }
  else ;
  {
    Serial.print(e);
  }
}
