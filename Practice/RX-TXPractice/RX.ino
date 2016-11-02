//RX
// A0 : PD_OUT - SW1 , A1 : CDS_OUT - SW2
// Note : J3
// Switch 1 - pin 8(PD_OUT) , Switch 2 - pin 9(CDS_OUT)
int switch08_Flag = 0;
int switch09_Flag = 0;
int pd_Data;
int cds_Data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(8,  INPUT);
  pinMode(9,  INPUT);
}
void loop() {
  //if (Serial.available() > 0) {
    if (digitalRead(8) == LOW) {
      if (switch08_Flag == 0) {
        
        Serial1.write(1);
        Serial.println(1);
        for (int i = 0 ; i < 5 ; i++) {
          pd_Data = analogRead(A0);
          Serial1.write(pd_Data);
          Serial.println(pd_Data);
          delay(200);
        }
        switch08_Flag = 1;
      }
    }
    else if (digitalRead(8) == HIGH)  if (switch08_Flag == 1) switch08_Flag = 0;
    if (digitalRead(9) == LOW) {
      if (switch09_Flag == 0) {
        
        Serial1.write(2);
        Serial.println(2);
        for (int i = 0 ; i < 5 ; i++) {
          cds_Data = analogRead(A0);
          Serial1.write(cds_Data);
          Serial.println(cds_Data);
          delay(200);
        }
        switch09_Flag = 1;
      }
    }
    else if (digitalRead(9) == HIGH)  if (switch09_Flag == 1) switch09_Flag = 0;
  //}
}
