#include <TimerOne.h>
// pin 40-47: A-F, DP
// pin 2-7: S0-S5
// 7-Segment를 이용해서 소수점 시계를 만드는 프로그램.
int cnt = 0;
int i1 = 0, i2 = 0, i3 = 0, i4 = 0, j;
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
int sel_pins[] =  {30, 31, 32, 33};
int number[4] = {0, 0, 0, 0};
void setup() {
  int i;
  for (i = 0; i < 8; i++) pinMode(seg_pins[i], OUTPUT);
  for (i = 0; i < 4; i++) pinMode(sel_pins[i], OUTPUT);
  for (i = 0; i < 8; i++) digitalWrite(seg_pins[i], LOW);
  for (i = 0; i < 4; i++) digitalWrite(sel_pins[i], HIGH);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(upNum);
}
void loop() {
  for (int k = 0 ; k < 4 ; k++) {
    digitalWrite(sel_pins[k], LOW);// 가장 오른쪽 세그먼트 켜기
    for (j = 0; j < 8; j++) {
      digitalWrite(seg_pins[j], seg[number[k]][j]); // 현재 시각에 해당하는 숫자 켜기
    }
    delay(2);
    digitalWrite(sel_pins[k], HIGH); // 가장 오른쪽 세그먼트 끄기
  }
}

void upNum() {
  number[0]++;
  if (number[0] == 10) {
    number[0] = 0;
    number[1]++;
  }
  if (number[1] == 10) {
    number[1] = 0;
    number[2]++;
  }
  if (number[2] == 10) {
    number[2] = 0;
    number[3]++;
  }
  if (number[3] == 6) {
    number[3] = 0;
  }
}

