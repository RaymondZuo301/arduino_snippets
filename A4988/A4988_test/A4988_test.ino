int STEP = 3;
int DIR = 2;
void setup(){
  pinMode(STEP,OUTPUT);
  pinMode(DIR,OUTPUT);
  Serial.begin(9600);
}
void PWM(int n,int s,int d){
  digitalWrite(DIR,d);
  Serial.println(d);
  for(int i=0;i<=n;i++){
    digitalWrite(STEP,1);
    delayMicroseconds(s);
    digitalWrite(STEP,0);
    delayMicroseconds(s);
  }
}  
void loop(){
  PWM(60,800,1);
  delay(1000);
  PWM(60,800,0);
  delay(1000);
}

