int flag_FrontBack = 0; // 0 : Front , 1 : Back
int swFlag = 0; // 0 -> 1 : SW On
int led_Init[8] = {3, 4, 5, 6, 7, 8, 9, 10};
int led_Index = 0;

void setup() {
  pinMode(2, INPUT);
  for (int i = 0 ; i < 8 ; i++) pinMode(led_Init[i], OUTPUT);
  attachInterrupt(0, changeWay, FALLING);
}

void loop() {
  digitalWrite(led_Init[led_Index], HIGH);
  delay(200);
  digitalWrite(led_Init[led_Index], LOW);
  if (flag_FrontBack == 0) {
    led_Index = led_Index + 1;
    if(led_Index == 8) led_Index = 0;
  }
  else if (flag_FrontBack == 1) {
    led_Index = led_Index - 1;
    if(led_Index == -1) led_Index = 7;
  }
}

void changeWay() {
  if (flag_FrontBack == 0) flag_FrontBack = 1;
  else flag_FrontBack = 0;
}

