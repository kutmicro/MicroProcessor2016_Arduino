//pin 22~29 : A-F,DP
//pin 30~31 : S0~S1
int seg[][8] = {
  {1, 1, 1, 1, 1, 1, 0, 0},   // 0
  {0, 1, 1, 0, 0, 0, 0, 0},   // 1
  {1, 1, 0, 1, 1, 0, 1, 0},   // 2
  {1, 1, 1, 1, 0, 0, 1, 0},   // 3
  {0, 1, 1, 0, 0, 1, 1, 0},   // 4
  {1, 0, 1, 1, 0, 1, 1, 0},   // 5
  {1, 0, 1, 1, 1, 1, 1, 0},   // 6
  {1, 1, 1, 0, 0, 0, 0, 0},   // 7
  {1, 1, 1, 1, 1, 1, 1, 0},   // 8
  {1, 1, 1, 1, 0, 1, 1, 0}    // 9
};
int seg_pins[] =  {22, 23, 24, 25, 26, 27, 28, 29};
int sel_pins[] =  {30, 31};
int firstNumber= 0; // 십의 자리
int secondNumber = 0; // 일의 자리
int index = 0;
void setup() {
  pinMode(2,INPUT);
  for(int i = 0 ; i < 8 ; i++) pinMode(seg_pins[i],OUTPUT);
  for(int i = 0 ; i < 2 ; i++) pinMode(sel_pins[i],OUTPUT);
  for(int i = 0 ; i < 8 ; i++) digitalWrite(seg_pins[i],LOW);
  for(int i = 0 ; i < 2 ; i++) digitalWrite(sel_pins[i],HIGH);
  attachInterrupt(0,upNum,FALLING);
}

void loop() {
  digitalWrite(sel_pins[0],LOW);
  for(index = 0 ; index < 8 ; index++){
    digitalWrite(seg_pins[index], seg[secondNumber][index]);
  }
  delay(2);
  digitalWrite(sel_pins[0],HIGH);
  digitalWrite(sel_pins[1],LOW);
  for(index = 0 ; index < 8 ; index++){
    digitalWrite(seg_pins[index], seg[firstNumber][index]);
  }
  delay(2);
  digitalWrite(sel_pins[1],HIGH);
}

void upNum(){
  secondNumber++;
  if(secondNumber == 10){
    secondNumber = 0;
    firstNumber++;
  }
  if(firstNumber == 10){
    firstNumber = 0;
  }
}

