//INA ~ IND : 8 ~ 11
//1-2상 방식으로 돌린 모터.
void setup() {
  int i;
  for (i = 8 ; i < 12 ; i++) pinMode(i, OUTPUT);
  for (i = 8 ; i < 12 ; i++) digitalWrite(i, LOW);
}
int flag = 0;
int i;
void loop() {
  for (i = 1 ; i < 5 ; i++) {
    delay(5);
    digitalWrite(((i + 1) % 4) + 8, HIGH);
    delay(5);
    digitalWrite((i % 4) + 8, LOW);
  }
}
