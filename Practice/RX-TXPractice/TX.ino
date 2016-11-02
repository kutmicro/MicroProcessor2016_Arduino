// TX
#include <LiquidCrystal.h>
LiquidCrystal lcd {8, 9, 4, 5, 6, 7};
int view = 0;
int sum = 0;
int ave = 0;
int cnt = 0;
double volt = 0;
int flag = 0;
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
  Serial.begin(9600);
  Serial1.begin(9600);
}
void loop() {
  if (Serial1.available() > 5) {
    lcd.clear();
    flag = Serial1.read();
    lcd.setCursor(0, 0);
    if ( flag == 1 ) lcd.print("Photo transistor");
    else if (flag == 2)lcd.print("Cds");
    for (int i = 0 ; i < 5 ; i++) {
      sum += Serial1.read();
    }
    ave = sum / 5;
    volt = (ave / 1024.0) * 5;
    lcd.setCursor(0, 1);
    lcd.print(ave);
    lcd.setCursor(5, 1);
    lcd.print(volt);
    lcd.print('V');

  }
  sum = 0;
}
