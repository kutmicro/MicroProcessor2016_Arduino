float t2 = 0;
int flag = 0;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  //AnalogMode
  if (flag == 0) {
    analogWrite(6, t2);
    analogWrite(5, t2);
    analogWrite(3, t2);
    delay(100);
    if ( t2 < 255) {
      t2 += 25.5;
      if (t2 > 240) flag = 1;
    }
  }
  
  else if (flag == 1) {
    analogWrite(6, t2);
    analogWrite(5, t2);
    analogWrite(3, t2);
    delay(100);
    if ( t2 > 0) {
      t2 -= 25.5;
      if (t2 < 20) flag = 0;
    }
  }
  //LED의 밝기를 밝게 했다가 어둡게 하는 프로그램.
}
