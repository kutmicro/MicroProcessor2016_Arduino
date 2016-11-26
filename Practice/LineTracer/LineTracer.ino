const int sensor_pin[4] = {46,47,48,49};  //적외선 센서 핀번호
const int LMOTOR = 2;   //왼쪽 모터 핀번호
const int M1 = 3;
const int RMOTOR = 4;   //오른쪽 모터 핀번호
const int M2 = 5;
  
  
void setup()
{
  pinMode(M1,OUTPUT);   //LEFT MOTOR핀 출력으로 설정
  pinMode(M2,OUTPUT);   //RIGHT MOTOR핀 출력으로 설정  
  for(int i=0 ; i<4 ; i++)
    pinMode(led_pin[i],INPUT);
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);   
  analogWrite(LMOTOR,0);    //LMOTOR 정지
  analogWrite(RMOTOR,0);    //RMOTOR 정지
      
  delay(1000);  // 1초 정지
}
  
void loop()
{    
  // 알고리즘 시작
  if(digitalRead(sensor_pin[1]) == LOW && digitalRead(sensor_pin[2]) == LOW )  //중간 2개의 센서에 라인이 감지된 경우
  {
    analogWrite(LMOTOR,90);
    analogWrite(RMOTOR,120);  
  }
  else if(digitalRead(sensor_pin[3]) == LOW)  // 맨 오른쪽 센서에 라인이 감지된 경우
  {
    analogWrite(LMOTOR,15);
    analogWrite(RMOTOR,120);    
  }
  else if(digitalRead(sensor_pin[0]) == LOW)  // 맨 왼쪽 센서에 라인이 감지된 경우
  {
    analogWrite(LMOTOR,120);
    analogWrite(RMOTOR,15);
  }
  else if(digitalRead(sensor_pin[2]) == LOW && digitalRead(sensor_pin[3]) == LOW)  // 오른쪽의 두 센서에 라인이 감지된 경우
  {
    analogWrite(LMOTOR,37);
    analogWrite(RMOTOR,110);    
  }
  else if(digitalRead(sensor_pin[0]) == LOW && digitalRead(sensor_pin[1]) == LOW)  // 왼쪽의 두 센서에 라인이 감지된 경우
  {
    analogWrite(LMOTOR,110);
    analogWrite(RMOTOR,37);
  }
  else if(digitalRead(sensor_pin[2]) == LOW) // 오른쪽에서 두 번째 센서에 라인이 감지된 경우
  {    
    analogWrite(LMOTOR,56);
    analogWrite(RMOTOR,100);
  }
  else if(digitalRead(sensor_pin[1]) == LOW)  // 왼쪽에서 두 번째 센서에 라인이 감지된 경우
  {
    analogWrite(LMOTOR,100);
    analogWrite(RMOTOR,56);
  }
  else                                    // 라인이 감지가 되지 않는다면 멈춤
  {
    analogWrite(LMOTOR,0);
    analogWrite(RMOTOR,0);
  }
  //알고리즘 끝
   
  delay(30);
}
