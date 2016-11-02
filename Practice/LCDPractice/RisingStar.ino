#include <LiquidCrystal.h>
//0.5초마다 별이 하나씩 늘어나게 하는 프로그램.(MAX에 도달하면 1로)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16 , 2);
  lcd.clear();
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);
}

int MAX_STARS = 1;
int i;

void loop() {
  lcd.setCursor(0, 0);
  lcd.clear();
  for (i = 0 ; i < MAX_STARS ; i++) {
    lcd.print("*");
  }
  if (MAX_STARS != 16) MAX_STARS ++;
  else if (MAX_STARS == 16) MAX_STARS = 1;
  lcd.setCursor(0, 1);
  for (i = 0 ; i < MAX_STARS ; i++) {
    lcd.print("*");
  }
  delay(500);
}
