int t = 0;
int switch12flag = 1;
int switch13flag = 1;
//SwitchFlag : 스위치를 눌렀을 때만 동작하게 만듦.
void setup() {
  pinMode(3, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}
//12Pin Sw를 누르면 밝기 증가, 13Pin Sw를 누르면 밝기 감소
void loop() {
  digitalWrite(3, HIGH);
  delay(10 - t);
  digitalWrite(3, LOW);
  delay(t);
  //PWMMode
  if (digitalRead(12) == LOW) {
    if (switch12flag == 1) {
      switch12flag = 0;
      if (t > 0) {
        t--;
      }
    }
  }

  else if (digitalRead(12) == HIGH) {
    if (switch12flag == 0) {
      switch12flag = 1;
    }
  }

  if (digitalRead(13) == LOW) {
    if (switch13flag == 1) {
      switch13flag = 0;
      if ( t < 10) {
        t++;
      }
    }
  }
  else if (digitalRead(13) == HIGH) {
    if (switch13flag == 0) {
      switch13flag = 1;
    }
  }
}
