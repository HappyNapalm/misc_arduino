long time=0;
int Cnote0 = 66;
int Cnote0s = 69;
int Dnote0 = 73;
int Dnote0s =78;
int Enote0 = 83;
int Fnote0 =86;
int Fnote0s = 91;
int Gnote0 = 97;
int Gnote0s = 104;
int Anote0 = 111;
int Anote0s = 144;
int Bnote0 = 123;
int Cnote1 = 131;
int Cnote1s = 140;
int Dnote1 = 147;
int Dnote1s = 156;
int Enote1 = 166;
int Fnote1 = 175;
int Fnote1s = 183;
int Gnote1 = 196;
int Gnote1s = 208;
int Anote1 = 221;
int Anote1s = 234;
int Bnote1 = 249;
int Cnote2 = 260;
int Cnote2s = 277;
int Dnote2 = 292;
int Dnote2s = 308;
int Enote2 = 326;
int Fnote2 = 350;
int Fnote2s = 370;
int Gnote2 = 394;
int Gnote2s = 412;
int Anote2 = 442;
int Anote2s = 462;
int Bnote2 = 493;
int Cnote3 = 529;
int Cnote3s = 554;
int Dnote3 = 584;
int Dnote3s = 618;
int Enote3 = 660;
int Fnote3 = 702;
int Fnote3s = 743;
int Gnote3 = 784;
int Gnote3s = 830;
int Anote3 = 882;
int Anote3s = 936;
int Bnote3 = 982;
int Cnote4 = 1053;
int Cnote4s = 1094;
int Dnote4 = 1165;
int Dnote4s = 1239;
int Enote4 = 1306;
int Fnote4 = 1398;
int Fnote4s = 1472;
int Gnote4 = 1530;
int Gnote4s = 1662;
int Anote4 = 1761;
int Anote4s = 1855;
int Bnote4 = 1955;
int Cnote5 = 2100;

int tempo = 2700;
int quarter = tempo/4;
int eight = tempo/8;
int sixtEnoten = tempo/16;

void playfor(int note, int sustain) {
  tone(9, note);
  delay(sustain); 
  time = time+sustain;
  Serial.println(time);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
  do{}
  while(digitalRead(2) == 0);
  
  Serial.println(time);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //BASS PART
  delay(2 * quarter);
  time+=(2 * quarter);
  for (int i = 0; i < 4; i++)
  {
  playfor(Anote0,eight);
  playfor(Dnote1,eight);
  playfor(Fnote1s,eight);
  playfor(Dnote1,eight);
  
  playfor(Bnote0,eight);
  playfor(Dnote1,eight);
  playfor(Fnote1s,eight);
  playfor(Dnote1,eight);
  }
  
  playfor(Bnote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Enote1, eight);
  
  playfor(Bnote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Enote1, eight);
  
  playfor(Anote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Cnote1s, eight);
  
  playfor(Anote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Cnote0s, eight); 
  
  for (int i = 0; i < 6; i++)
  {
  playfor(Anote0,eight);
  playfor(Dnote1,eight);
  playfor(Fnote1s,eight);
  playfor(Dnote1,eight);
  
  playfor(Bnote0,eight);
  playfor(Dnote1,eight);
  playfor(Fnote1s,eight);
  playfor(Dnote1,eight);
  }
  
  playfor(Bnote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Enote1, eight);
  
  playfor(Bnote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Enote1, eight);
  
  playfor(Anote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Cnote1s, eight);
  
  playfor(Anote0, eight);
  playfor(Enote1, eight);
  playfor(Gnote1, eight);
  playfor(Cnote1s, eight); 
  
  //break after this
  playfor(Anote0s, eight);
  playfor(Dnote1, eight);
  playfor(Fnote1, eight);
  playfor(Anote1, eight);
  tone (9, 0);
  
  tone (9, 0);
  Serial.println(time);
  delay(3000);
  do{}
  while(digitalRead(2) == 0);
}
