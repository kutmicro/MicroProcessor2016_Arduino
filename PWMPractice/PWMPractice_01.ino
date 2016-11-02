int t2 = 0;
int oncnt2 = 0;
int offcnt2 = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(12, INPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  delay(10 - t2);
  digitalWrite(2, LOW);
  delay(t2);
  //PWM Mode , Light Lv 0 ~ 10
  if (digitalRead(12) == LOW) { //Switch ON : LightLevel++
    oncnt2++;
    if (oncnt2 == 10) {
      oncnt2 = 0;
      if (t2 < 10) {
        t2 += 1;
      }
    }
  }

  if (digitalRead(12) == HIGH) { //Switch OFF : LightLevel--
    offcnt2++;
    if (offcnt2 == 10) {
      offcnt2 = 0;
      if (t2 > 0) {
        t2 -= 1;
      }
    }
  }
}
