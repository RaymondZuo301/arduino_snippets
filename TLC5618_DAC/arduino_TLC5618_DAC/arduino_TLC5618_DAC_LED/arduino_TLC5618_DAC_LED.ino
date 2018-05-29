//mega2560
#define uint unsigned int
#define uchar unsigned char
int CS = 2; //pian xuan
int SCLK = 3;//shi zhong shu ru
int DI = 4;//shu ju
int High = 13;
int Read = 0;
int switch1 = 5;
int switch2 = 6;
int button = 7;
void setup()
{
  pinMode(CS, OUTPUT);
  pinMode(SCLK, OUTPUT);
  pinMode(DI, OUTPUT);
  pinMode(High,OUTPUT);
  for(int i=31;i<=37;i++){
    pinMode(i, OUTPUT); 
  }
  pinMode(switch1,INPUT);
  pinMode(switch2,INPUT);
  pinMode(button,INPUT);
  digitalWrite(High,1);
  Serial.begin(9600);
//  attachInterrupt(2, DA1, RISING);
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
byte LED[10][7] = { //设置0-9数字所对应数组
{ 0,0,0,0,1,0,0 }, // = 0
{ 0,0,1,1,1,1,1 }, // = 1
{ 1,0,0,1,0,0,0 }, // = 2
{ 0,0,0,1,0,1,0 }, // = 3
{ 0,0,1,0,0,1,1 }, // = 4
{ 0,1,0,0,0,1,0 }, // = 5
{ 0,1,0,0,0,0,0 }, // = 6
{ 0,0,0,1,1,1,1 }, // = 7
{ 0,0,0,0,0,0,0 }, // = 8
{ 0,0,0,0,0,1,0 } // = 9
};

void Led(int k){//shu chu shu zi
    uint pin = 31;
    for (int s = 0; s < 7; s++){
      digitalWrite(pin, LED[k][s]);
      pin++;
    }
}

void loop(){
  int V = analogRead(Read);
  Led(V%10);
  TLC5618(0x8000|(0x0fff&V));
//  Serial.println(V);
//  delay(200);
}

/*
void loop(){
  int V = analogRead(Read);
  Led(V%10);
  TLC5618(0x8000|(0x0fff&V));
  Serial.println(V);
  delay(200);
}
*/
/*
void loop()
{
  if(digitalRead(button==1)){
    uint v;
    delay(5000);
    for(v=0;v<=500;v++)
    {
      TLC5618(0x8000|(0x0fff&v));//B tong dao gai cheng 0x0000   0x8000|(0x0fff&v)
      delay(10);
      Serial.println(v);
    }
    delay(5000);
    TLC5618(0x8000|(0x0fff&0));
    delay(100000);
  }
}
*/
