int sole1 = 9;
int sole2 = 10;
int sole3 = 7;
int capanna = 2;
int pompa = 12;
int fuoco = 5;

void setup() {
  pinMode(sole1, OUTPUT);
  pinMode(sole2, OUTPUT);
  pinMode(sole3, OUTPUT);
  pinMode(capanna, OUTPUT);
  pinMode(pompa, OUTPUT);
  pinMode(fuoco, OUTPUT);
}

void loop() {
  digitalWrite(pompa, LOW);
  
  for (int ValorePWM = 0; ValorePWM <= 255; ValorePWM++) {
    analogWrite(sole1, ValorePWM);
    analogWrite(sole2, ValorePWM);
    delay(150);
  
    if(ValorePWM == 100) {
      digitalWrite(capanna, LOW);
    }
    else if(ValorePWM == 50) {
      digitalWrite(fuoco, LOW);
    }
  }
  
  digitalWrite(sole3, HIGH);
  delay(10000);
  digitalWrite(fuoco, HIGH);
  delay(10000);
  digitalWrite(fuoco, LOW);
  delay(10000);
  digitalWrite(sole3, LOW);
  
  for(int ValorePWM = 255; ValorePWM >= 0; ValorePWM--) {
    analogWrite(sole1, ValorePWM);
    analogWrite(sole2, ValorePWM);
    delay(150);
    
    if(ValorePWM == 100) {
      digitalWrite(capanna, HIGH);
    }
    else if(ValorePWM == 50) {
      digitalWrite(fuoco, HIGH);
    }
  }

  digitalWrite(pompa, HIGH);
 
  delay(30000); 
} 
