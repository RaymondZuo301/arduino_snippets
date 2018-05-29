int pin = 3; //0~13
int pin2 = 2;
void setup()
{
  pinMode(pin, OUTPUT);
  pinMode(pin2, INPUT);
  Serial.begin(9600);

} 
void loop()
{
      delay(5000);
      int i=0;
      while(i<24)
        {
          analogWrite(pin, i++);
          Serial.println(i);
          delay(200);  
        }
      delay(15000);
      i=0;
}

