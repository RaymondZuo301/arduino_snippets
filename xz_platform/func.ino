/*==================函数==================*/
/* 前进和后退函数，dir前进为1，后退为0 */
void Move(bool dir) {
  Serial.println("moving");
  //z正行程
  digitalWrite(dir_z, HIGH);
  int temp = z_length;
  while(temp > 0) {
    while(enable){
      delay(10);
      Serial.println("pausing");
    }
    Serial.println("moving");
    digitalWrite(pulse_z, HIGH);
    delayMicroseconds(delaytime);
    digitalWrite(pulse_z, LOW);
    delayMicroseconds(delaytime);
    temp--;
  }
  //x行程
  digitalWrite(dir_x, dir);
  temp = x_length;
  while(temp > 0) {
    while(enable){
      delay(10);
      Serial.println("pausing");  
    }
    Serial.println("moving");
    digitalWrite(pulse_x, HIGH);
    delayMicroseconds(delaytime);
    digitalWrite(pulse_x, LOW);
    delayMicroseconds(delaytime);
    temp--;
  }
  //z负行程
  digitalWrite(dir_z, LOW);
  temp = z_length;
  while(temp > 0) {
    while(enable){
      delay(10);
      Serial.println("pausing");
    }
    Serial.println("moving");
    digitalWrite(pulse_z, HIGH);
    delayMicroseconds(delaytime);
    digitalWrite(pulse_z, LOW);
    delayMicroseconds(delaytime);
    temp--;
  }
}

/* 点动函数 */
void Jog(int pin){
    digitalWrite(pin, HIGH);
    delayMicroseconds(delaytime);
    digitalWrite(pin, LOW);
    delayMicroseconds(delaytime);
}

/* 暂停（中断1） */
void Pause() {
  delay(50);
  enable = 1;
}

/* 继续（中断0） */
void Continue() {
  delay(50);
  enable = 0;
  Serial.println("contiue");
}
