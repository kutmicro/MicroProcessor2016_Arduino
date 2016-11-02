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
int seg_pins[] =  {8, 9, 10, 11, 12, 13, 14, 15};
int sel_pins[] =  {2, 3, 4, 5, 6, 7};
void setup() {
  int i;
  for (i = 0; i < 8; i++) pinMode(seg_pins[i], OUTPUT);
  for (i = 0; i < 6; i++) pinMode(sel_pins[i], OUTPUT);
  for (i = 0; i < 8; i++) digitalWrite(seg_pins[i], LOW);
  for (i = 0; i < 6; i++) digitalWrite(sel_pins[i], HIGH);
}
void loop() {
  digitalWrite(sel_pins[0], LOW);// 가장 오른쪽 세그먼트 켜기
  for (j = 0; j < 8; j++) {
    digitalWrite(seg_pins[j], seg[i1][j]); // 현재 시각에 해당하는 숫자 켜기
  }
  delay(2);
  digitalWrite(sel_pins[0], HIGH); // 가장 오른쪽 세그먼트 끄기
  digitalWrite(sel_pins[1], LOW); // 오른쪽 2번째 세그먼트 켜기
  for (j = 0; j < 8; j++) {
    digitalWrite(seg_pins[j], seg[i2][j]); // 현재 시각에 해당하는 숫자 켜기
  }
  delay(2);
  digitalWrite(sel_pins[1], HIGH); // 오른쪽 2번째 세그먼트 끄기
  digitalWrite(sel_pins[2], LOW); // 오른쪽 3번째 세그먼트 켜기
  for (j = 0; j < 7; j++) {
    digitalWrite(seg_pins[j], seg[i3][j]); // 해당 숫자 출력
  }
  digitalWrite(seg_pins[7], HIGH ); // DP 켜기 ( 소수점 )
  delay(2);
  digitalWrite(sel_pins[2], HIGH); // 오른쪽 3번째 세그먼트 끄기
  digitalWrite(sel_pins[3], LOW); // 가장 왼쪽 세그먼트 켜기
  for (j = 0; j < 8; j++) {
    digitalWrite(seg_pins[j], seg[i4][j]); // 해당 숫자 출력
  }
  delay(2);
  digitalWrite(sel_pins[3], HIGH); // 가장 왼쪽 세그먼트 끄기
  delay(2);
  i1 = (i1 + 1) % 10; // 소수점 시간 조정
  cnt++;
  if (cnt % 10 == 0) {
    i2 = (i2 + 1) % 10; // 소수점 1자리 시간 조정
  }
  if (cnt % 100 == 0) {
    i3 = (i3 + 1) % 10; // 초 단위 시간 조정
  }
  if (cnt % 1000 == 0) {
    i4 = (i4 + 1) % 6; // 10초 단위 시간 조정
    cnt = 0;
  }
}
