/*==================主程序==================*/
void loop() {
  /* 前进按钮，位置1生效 */
  if (digitalRead(forward) == LOW && pos == 1) {
    Serial.println("forward");
    Move(pos);
    pos = 0;//到达位置0
    Serial.println("forward_over");
  }
  
  /* 后退按钮，位置0生效 */
  if (digitalRead(back) == LOW && pos == 0) {
    Serial.println("back");
    Move(pos);
    pos = 1;//到达位置1
    Serial.println("back_over");
  }
  
  /* x正和z正 */
  if (digitalRead(x_p) == LOW || digitalRead(z_p) == LOW ) {
    digitalWrite(dir_x, HIGH);
    digitalWrite(dir_z, HIGH);
    while (digitalRead(x_p) == LOW) {
      Jog(pulse_x);
      Serial.println("x_p_moving");
    }
    while (digitalRead(z_p) == LOW) {
      Jog(pulse_z);
      Serial.println("z_p_moving");
    }
  }
  
  /* x负和z负 */
  if (digitalRead(x_n) == LOW || digitalRead(z_n) == LOW) {
    digitalWrite(dir_x, LOW);
    digitalWrite(dir_z, LOW);
    while (digitalRead(x_n) == LOW) {
      Jog(pulse_x);
      Serial.println("x_n_moving");
    }
    while (digitalRead(z_n) == LOW) {
      Jog(pulse_z);
      Serial.println("z_n_moving");
    }
  }
}
