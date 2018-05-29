/*==================全局变量==================*/
/* 输入端口定义 */
int forward = 4;//前进
int back = 5;//后退
int x_p = 6;//x正
int x_n = 7;//x负
int z_p = 8;//z正
int z_n = 9;//z负

/* 输出端口定义 */
int dir_x = 10;//x方向
int pulse_x = 15;//x脉冲
int dir_z = 14;//z方向
int pulse_z = 16;//z脉冲

/* 其他变量 */
int delaytime = 100;//一个脉冲的半周期时间，微妙
int x_length = 12800;//x脉冲数
int z_length = 12800;//z脉冲数
bool pos = 1;//初始位置标记，1为起点，0为终点
bool enable = 0;//暂停、继续的标记，1为暂停，0为继续

/*==================初始化==================*/
void setup() {
  for (int i = 4; i <= 9; i++) {
    pinMode(i, INPUT);
  }//输入按钮端口的初始化
  pinMode(dir_x, OUTPUT);//输出端口初始化
  pinMode(pulse_x, OUTPUT);
  pinMode(dir_z, OUTPUT);
  pinMode(pulse_z, OUTPUT);
  
  attachInterrupt(0, Continue, CHANGE);//继续，pin2（中断0）
  attachInterrupt(1, Pause, CHANGE);//暂停,pin3（中断1）

  Serial.begin(9600);//调试用串口初始化
}

