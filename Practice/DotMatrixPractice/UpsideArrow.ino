// R1-R8 : 22-29
// C1-C8 : 32-39
// 윗방향 화살표를 올라가도록 하는 프로그램
int row_pin[] = {22, 23, 24, 25, 26, 27, 28, 29};
int col_pin[] = {32, 33, 34, 35, 36, 37, 38, 39};

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
int DelayCount = 0;
int count = 0;

void setup() {
  int i;
  for (i = 0; i < 8; i++) pinMode(row_pin[i], OUTPUT);
  for (i = 0; i < 8; i++) pinMode(col_pin[i], OUTPUT);
  for (i = 0; i < 8; i++) digitalWrite(row_pin[i], LOW);
  for (i = 0; i < 8; i++) digitalWrite(col_pin[i], HIGH);
}

void loop() {
  int i, j;
  if (count == 0) {
    // DelayCount = 0;
    while (1) {
      for (i = 0; i < 8; i++) {
        digitalWrite(row_pin[i], HIGH);
        for (j = 0; j < 8; j++) {
          digitalWrite(col_pin[j], led[i][j]);
        }
        delay(2);
        digitalWrite(row_pin[i], LOW);
      }

      if (DelayCount == 100) {
        DelayCount = 0;
        count++;
        break;
      }
      else
        DelayCount++;
    }
  }

  if (count > 0) {
    // DelayCount = 0;
    for (int i = 1; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        temp[j] = led[i - 1][j];
        led[i - 1][j] = led[i][j];
        led[i][j] = temp[j];
      }
    }
    while (1) {

      for (i = 0; i < 8; i++) {
        digitalWrite(row_pin[i], HIGH);
        for (j = 0; j < 8; j++) {
          digitalWrite(col_pin[j], led[i][j]);
        }
        delay(2);
        digitalWrite(row_pin[i], LOW);
      }

      if (DelayCount == 100) {
        DelayCount = 0;
        if (count == 7) count = 0;
        else count++;
        break;
      }
      else
        DelayCount++;
    }
  }
}
