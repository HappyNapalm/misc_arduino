int time = 0;
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
int sixnote = tempo/16;

void playfor(int note, int sustain) {
  tone(9, note);
  time = time+sustain;
  delay(sustain); 
  Serial.println(time);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
  do{}
  while(digitalRead(2) == 0);
 
}
void loop() {
  // put your main code here, to run repeatedly:
  //VOICE
  playfor(Gnote3 ,eight);
  
  playfor(Fnote3s ,eight);
  playfor(Enote3 ,eight - 20);
  noTone(9);
  delay(20);
  time+=20;
  playfor(Enote3 ,eight);
  
  playfor(Fnote3s ,2*quarter);
  noTone(9);
  delay(4 * quarter - eight);
  time += (4 * quarter - eight);
  
  playfor(Anote2 ,eight); //pick up
  
  playfor(Gnote3 ,eight);
  playfor(Fnote3s ,eight);
  playfor(Enote3 ,3* eight);
  
  
  playfor(Fnote3s ,3*eight);
  
  playfor(Dnote3 ,2* eight);
  playfor(Enote3 ,eight);
  playfor(Anote2 ,quarter + eight);
  noTone(9);
  delay(2 * quarter + 2*eight);
  time += (2 * quarter + 2*eight);
  
  playfor(Enote3 ,quarter);
  playfor(Fnote3s ,eight);
  playfor(Gnote3 ,quarter + eight);
  playfor(Enote3 ,eight);
  playfor(Cnote3s ,quarter);
  playfor(Dnote3 ,3* eight);
  
  playfor(Enote3 ,2* eight);
  playfor(Anote2 ,3* eight);
  
  playfor(Fnote3s ,eight + 3 *quarter);
  noTone(9);
  delay(2* quarter);
  time += (2* quarter);
  Serial.println(time);
  
  do{}
  while(digitalRead(2) == 0);
  
  
  
//  playfor(Gnote3 ,eight);
//  playfor(Fnote3s ,eight);
//  playfor(Enote3 ,eight *2);
//  playfor(Fnote3s ,4*eight);
//  noTone(9);
//  delay(7* eight);
  
  //delay(2000);
}
