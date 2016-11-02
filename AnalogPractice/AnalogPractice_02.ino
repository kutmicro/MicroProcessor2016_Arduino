float t = 0;
int switch12flag = 1;
int switch13flag = 1;
// PWMPractice_02번 문제의 AnalogWrite 버전.
void setup() {
  pinMode(3, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
}

void loop() {
  //AnalogMode
  if (digitalRead(12) == LOW) {
    analogWrite(3, t);
    if (switch12flag == 1) {
      switch12flag = 0;
      if (t > 0) {
        t -= 25.5;
      }
    }
  }

  else if (digitalRead(12) == HIGH) {
    analogWrite(3, t);
    if (switch12flag == 0) {
      switch12flag = 1;
    }
  }

  if (digitalRead(13) == LOW) {
    analogWrite(3, t);
    if (switch13flag == 1) {
      switch13flag = 0;
      if ( t < 255) {
        t += 25.5;
      }
    }
  }
  else if (digitalRead(13) == HIGH) {
    analogWrite(3, t);
    if (switch13flag == 0) {
      switch13flag = 1;
    }
  }
}
