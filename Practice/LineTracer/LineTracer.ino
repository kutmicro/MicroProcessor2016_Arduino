const int sensor_pin[4] = {46, 47, 48, 49}; //적외선 센서 핀번호
const int LMOTOR = 2;   //왼쪽 모터 핀번호
const int M1 = 3;
const int RMOTOR = 4;   //오른쪽 모터 핀번호
const int M2 = 5;
const int SW_Pin = 18;
int sw_flag = 0;
void setup()
{
  pinMode(M1, OUTPUT);  //LEFT MOTOR핀 출력으로 설정
  pinMode(M2, OUTPUT);  //RIGHT MOTOR핀 출력으로 설정
  pinMode(SW_Pin, INPUT);
  for (int i = 0 ; i < 4 ; i++)
    pinMode(sensor_pin[i], INPUT);
  analogWrite(LMOTOR, 0);   //LMOTOR 정지
  analogWrite(RMOTOR, 0);   //RMOTOR 정지
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  while (1) {
    if (digitalRead(SW_Pin) == LOW) break;
  }
}
void loop()
{

  if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) // O X X X
  {
    analogWrite(LMOTOR, 69);
    analogWrite(RMOTOR, 0);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) // X X X O
  {
    analogWrite(LMOTOR, 0);
    analogWrite(RMOTOR, 92);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) // O X X O
  {
    analogWrite(LMOTOR, 60);
    analogWrite(RMOTOR, 80);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) { // O O X X
    analogWrite(LMOTOR, 69);
    analogWrite(RMOTOR, 0);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) { // X X O O
    analogWrite(LMOTOR, 0);
    analogWrite(RMOTOR, 92);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == LOW) { // O X O X
    analogWrite(LMOTOR, 69);
    analogWrite(RMOTOR, 0);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) { // X O X O
    analogWrite(LMOTOR, 0);
    analogWrite(RMOTOR, 92);
  }
  else if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) // X O O O
  {
    analogWrite(LMOTOR, 0);
    analogWrite(RMOTOR, 92);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) // O X O O
  {
    analogWrite(LMOTOR, 0);
    analogWrite(RMOTOR, 92);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == HIGH) // O O X O
  {
    analogWrite(LMOTOR, 69);
    analogWrite(RMOTOR, 0);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == LOW) // O O O X
  {
    analogWrite(LMOTOR, 69);
    analogWrite(RMOTOR, 0);
  }
  else if (digitalRead(sensor_pin[0]) == HIGH && digitalRead(sensor_pin[1]) == HIGH && digitalRead(sensor_pin[2]) == HIGH && digitalRead(sensor_pin[3]) == HIGH) // O O O O
  {
    analogWrite(LMOTOR, 60);
    analogWrite(RMOTOR, 80);
  }
  if (digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW) // X X X X
  {
    analogWrite(LMOTOR, 0);
    analogWrite(RMOTOR, 0);
  }
  //알고리즘 끝

}

