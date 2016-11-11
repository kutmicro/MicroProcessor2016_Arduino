#include <TimerOne.h>
//ROWS : R1 ~ R8 <-> PIN 36 ~ 43
//COLS : C1 ~ C8 <-> PIN 46 ~ 49,9,8
// 윗방향 화살표를 올라가도록 하는 프로그램
int row_pin[] = {36, 37, 38, 39, 40, 41, 42, 43};
int col_pin[] = {46, 47, 48, 49, 6, 7, 9, 8};

int led[][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 1, 1, 1},
  {1, 1, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0}
};

int temp[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  int i;
  for (i = 0; i < 8; i++) pinMode(row_pin[i], OUTPUT);
  for (i = 0; i < 8; i++) pinMode(col_pin[i], OUTPUT);
  for (i = 0; i < 8; i++) digitalWrite(row_pin[i], LOW);
  for (i = 0; i < 8; i++) digitalWrite(col_pin[i], HIGH);
  Timer1.initialize(300000);
  Timer1.attachInterrupt(up);
}

void loop() {
  int i, j;
  for (i = 0; i < 8; i++) {
    digitalWrite(row_pin[i], HIGH);
    for (j = 0; j < 8; j++) {
      digitalWrite(col_pin[j], led[i][j]);
    }
    delay(2);
    digitalWrite(row_pin[i], LOW);
  }
}

void up() {
  for (int i = 1; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      temp[j] = led[i - 1][j];
      led[i - 1][j] = led[i][j];
      led[i][j] = temp[j];
    }
  }
}

