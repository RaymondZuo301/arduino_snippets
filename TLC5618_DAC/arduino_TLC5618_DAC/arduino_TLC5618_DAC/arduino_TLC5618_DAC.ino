//mega2560
#define uint unsigned int
#define uchar unsigned char
int CS = 2; //pian xuan
int SCLK = 3;//shi zhong shu ru
int DI = 4;//shu ju

void setup()
{
  pinMode(CS, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(DI, OUTPUT);
//  Serial.begin(9600);
} 
void TLC5618(uint n){//mo ni shu chu
  uint Temp = 0;
  uchar i = 0;
//  Serial.println(0xfff&n);
  digitalWrite(SCLK,HIGH);
  digitalWrite(CS,LOW); 
  for(i=0;i<16;i++){
    Temp = n&0x8000;
    if(Temp){
      digitalWrite(DI,HIGH);
//      Serial.print(1);      
    }
    else{
      digitalWrite(DI,LOW);
//      Serial.print(0);
    }
    digitalWrite(SCLK,LOW);
    n<<=1;
    digitalWrite(SCLK,HIGH);
  }
  digitalWrite(SCLK,HIGH);
  digitalWrite(CS,HIGH);
//  Serial.println("end");
}

void loop()
{
  TLC5618(0x8000|(0x0fff&0));
  uint v;
  delay(5000);
  for(v=0;v<=500;v++)
  {
    TLC5618(0x8000|(0x0fff&v));//B tong dao gai cheng 0x0000   0x8000|(0x0fff&v)
    delay(10);
  }
  delay(5000);
  TLC5618(0x8000|(0x0fff&0));
  delay(10000);
}

