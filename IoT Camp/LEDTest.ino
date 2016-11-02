#include <SoftwareSerial.h>
#include <U8glib.h>
#include "pitches.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE); 

SoftwareSerial BT(3, 2); //Tx, Rx
int ledPin[9] = {4, 5, 6, 7, 8, 9, 10, 11, 12}; // LEDPIN 설정
int ans_cnt[5] = {1, 1, 1, 1, 1};
char inChar; // inChar는 휴대전화에서 입력을 받아오는 것.
int index[2] = {0,random(0,9)};
int levelflag = 1;
int scoremax = 0;
int score = 0;
int switchInput = 13;
int stage = 0;
int temp = 10;
int cnt = 0;
int start = 0;
const int delayConst = 1000;

void setup() {
  pinMode(switchInput,INPUT_PULLUP);
  u8g.setFont(u8g_font_unifont);
  randomSeed(analogRead(0));
  int i = 0;
  for(i = 0 ; i < 9 ; i++) ledSet(i);
  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(start == 0) {
    startGame();
    start++;
  }
  index[2] = random(0,9);
  index[2] = ledOn(index[2]);
  inChar = BT.read();
  if(inChar == index[1] + '0')  {
    melody_button();
    delay(500);
    ledOff(index[2]);
    score = score + 5 + levelflag * 5;
  }
  levelUp();
  printScore();
  gameOver();
  SerialPrint(inChar);
  if (inChar != index[1] + '0') ledOff(index[2]);
  index[1] = index[2];
}

void ledSet(int i){
  pinMode(ledPin[i],OUTPUT);
}

int ledOn(int i){
  if( index[1] == i) {
    i += random(0,9) + random(0,9);
    i %= 9;
  }
  digitalWrite(ledPin[i],HIGH);
  return i;
}

void ledOff(int i){
 digitalWrite(ledPin[i],LOW); 
}

void SerialPrint(char inChar){
  Serial.print(index[1]);
  Serial.print("\t");
  Serial.print(inChar);
  Serial.print("\t");
  if(inChar == index[1] + '0') {
    ans(1);
    Serial.println("O");
  }
  else {
    ans(0);
    Serial.println("X");
  }
  delay(delayConst - 50 * levelflag);
}

void startGame() {
  for(int i = 0 ; i < 6 ; i++){
    if(i == 1){
      backGround();
      while(1){
         if(digitalRead(switchInput) == LOW)
         break;
      }
    } 
    u8g.firstPage();
    do{
     draw(i);
     }while(u8g.nextPage());
    delay(1000);
  }
}  

void draw(int state) {
  switch(state) {
    case 0:
      u8g.setPrintPos(30,25);
      u8g.print("Ready?");
      break;
    case 1:
      u8g.setPrintPos(30,15);
      u8g.print("Game Start!");
      break;
    case 2:
      u8g.setPrintPos(63,30);
      u8g.print("3");
      break;
    case 3:
      u8g.setPrintPos(63,45);
      u8g.print("2");
      break;
    case 4:
      u8g.setPrintPos(63,60);
      u8g.print("1");
      break;
    case 5:
      u8g.setPrintPos(61, 35);
      u8g.print("Go!");
      break;
  }
}
void printScore() {
  u8g.firstPage();
  do {
    drawScore();
  }while(u8g.nextPage());
}
void drawScore() {
  u8g.setPrintPos(0, 10);
  u8g.print("level : ");
  u8g.setPrintPos(60, 10);
  u8g.print(levelflag);

  u8g.setPrintPos(0, 30);
  u8g.print("score : ");
  u8g.setPrintPos(60, 30);
  u8g.print(score);
}

void levelUp() {
  if(score >= levelflag * levelflag * 100) {
    melody_clear();
    delay(2000);
    levelflag++;
  }
}

void ans(int n) {
  ans_cnt[0] = ans_cnt[1];
  ans_cnt[1] = ans_cnt[2];
  ans_cnt[2] = ans_cnt[3];
  ans_cnt[3] = ans_cnt[4];
  ans_cnt[4] = n;
}

void gameOver() {
  int sum = 0;
  for(int i = 0; i < 5; ++i) {
    sum += ans_cnt[i];
  }
  if(sum == 0) {
    while(1) {
      u8g.firstPage();
      do {
        u8g.setPrintPos(0, 10);
        u8g.print("score : ");
        u8g.setPrintPos(60, 10);
        u8g.print(score);
  
        u8g.setPrintPos(40, 40);
        u8g.print("Game Over");
      }while(u8g.nextPage());
      melody_end();
      while(1) {
        if(digitalRead(switchInput) == LOW){
          ans_cnt[0] = 1;
          ans_cnt[1] = 1;
          ans_cnt[2] = 1;
          ans_cnt[3] = 1;
          ans_cnt[4] = 1;
          score = 0;
          start = 0;
          return;
      }
    }
  }
}
}

void stageDelay(int stage){
    if(ledPin[index[2]]%3 == 0){ // 노란색 핀
      delay(1000 - (50*stage));
      if (inChar == char(index)){
        score++;
      }
     }
     else if(ledPin[index[2]]%3 == 1){//빨간색 핀
      delay(1000 - (100*stage));
      if (inChar == char(index)){
        score += 2;
      }
     }
     else if (ledPin[index[2]]%3 == 2){//초록색 핀
      delay(1000 - (150*stage));
      if(inChar == char(index)){
        score += 3;
      }
     }
}


void melody_start(){
  int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
  for (int thisNote = 7; thisNote > 0; thisNote--) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(15, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(15);
   }
  }

void melody_end() {
 int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(15, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(15);
  }
}

void melody_button() {
  tone(15,2000,200);
  delay(50);
  tone(15,1500,100);
}
void backGround() {
  int melody[] = {
    NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
    NOTE_G4, NOTE_C5, NOTE_AS4, NOTE_A4,                   
    NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
    NOTE_C4, NOTE_D4,0,                                 
  
    NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_A4,
    NOTE_G4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4,      //29               //8
    NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_DS4, NOTE_D4,
    NOTE_C4, NOTE_D4,0,                                       
  
    NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
    NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5,
    NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_D5, NOTE_C5,
    NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_AS4,             //58
  
    NOTE_D4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_DS5, NOTE_D5,
    NOTE_C5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_C5, NOTE_G4,
    NOTE_A4, 0, NOTE_AS4, NOTE_A4, 0, NOTE_G4,
    NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, 0
  
};

// note durations: 8 = quarter note, 4 = 8th note, etc.
int noteDurations[] = {       //duration of the notes
  8,4,8,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,16,4,
  
  8,4,8,4,
  4,2,1,1,2,1,1,12,
  4,4,4,4,4,4,
  4,16,4,
  
  4,4,4,4,4,4,
  4,4,4,12,
  4,4,4,4,4,4,
  4,4,4,12,
  
  4,4,4,4,4,4,
  2,1,1,2,1,1,4,8,4,
  2,6,4,2,6,4,
  2,1,1,16,4
};

int speed=90;  //higher value, slower notes
;
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(int); thisNote++) {

    int noteDuration = speed*noteDurations[thisNote];

    if(digitalRead(switchInput) == LOW) return;
    
    tone(15, melody[thisNote],noteDuration*1.3);

    delay(1.3*noteDuration);

    noTone(15);
  }
}

void melody_clear(){
  int melody[] = {
  NOTE_G4,NOTE_C4,NOTE_E4,NOTE_G4,NOTE_D4,NOTE_G4
};

int noteDurations[] = {
  10,10,5,5,10,5
};
for( int thisNote = 0;thisNote<6;thisNote++){
  int noteDuration = 1000/ noteDurations[thisNote];
  tone(15,melody[thisNote],noteDuration);

  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
  noTone(15);
 }
}




