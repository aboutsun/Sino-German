//===========================
// 智能小车黑线
//#include <Servo.h>
#include <wiringPi.h>
#include <iostream>
#include <IRSensor.h>

#define SensorRight 4 //右循迹红外传感器(P3.2 OUT1)
#define SensorLeft 5 //左循迹红外传感器(P3.3 OUT2)

void setup()
{
    pinMode(SensorRight, INPUT); //定义右循迹红外传感器为输入
    pinMode(SensorLeft, INPUT); //定义左循迹红外传感器为输入
}
//=======================智能小车的基本动作=========================
//void run(int time) // 前进
void run()
{
    digitalWrite(RM_VOR,HIGH); // 右电机前进
    digitalWrite(RM_ZUR,LOW);
    analogWrite(RM_VOR,150);//PWM比例0~255调速，左右轮差异略增减
    analogWrite(RM_ZUR,0);
    digitalWrite(LM_VOR,HIGH); // 左电机前进
    digitalWrite(LM_ZUR,LOW);
    analogWrite(LM_VOR,150);//PWM比例0~255调速，左右轮差异略增减
    analogWrite(LM_ZUR,0);
//delay(time * 100); //执行时间，可以调整
}
//void brake(int time) //刹车，停车
void brake()
{
    digitalWrite(RM_VOR,LOW);
    digitalWrite(RM_ZUR,LOW);
    digitalWrite(LM_VOR,LOW);
    digitalWrite(LM_ZUR,LOW);
//delay(time * 100);//执行时间，可以调整
}
//void left(int time) //左转(左轮不动，右轮前进)
void left()
{
    digitalWrite(RM_VOR,HIGH);// 右电机前进
    digitalWrite(RM_ZUR,LOW);
    analogWrite(RM_VOR,150);
    analogWrite(RM_ZUR,0);//PWM比例0~255调速
    digitalWrite(LM_VOR,LOW); //左轮后退
    digitalWrite(LM_ZUR,LOW);
    analogWrite(LM_VOR,0);
    analogWrite(LM_ZUR,0);//PWM比例0~255调速
//delay(time * 100); //执行时间，可以调整
}
void spin_left(int time) //左转(左轮后退，右轮前进)
{
    digitalWrite(RM_VOR,HIGH);// 右电机前进
    digitalWrite(RM_ZUR,LOW);
    analogWrite(RM_VOR,200);
    analogWrite(RM_ZUR,0);//PWM比例0~255调速
    digitalWrite(LM_VOR,LOW); //左轮后退
    digitalWrite(LM_ZUR,HIGH);
    analogWrite(LM_VOR,0);
    analogWrite(LM_ZUR,200);//PWM比例0~255调速
    delay(time * 100); //执行时间，可以调整
}
//void right(int time) //右转(右轮不动，左轮前进)
void right()
{
    digitalWrite(RM_VOR,LOW); //右电机后退
    digitalWrite(RM_ZUR,LOW);
    analogWrite(RM_VOR,0);
    analogWrite(RM_ZUR,0);//PWM比例0~255调速
    digitalWrite(LM_VOR,HIGH);//左电机前进
    digitalWrite(LM_ZUR,LOW);
    analogWrite(LM_VOR,150);
    analogWrite(LM_ZUR,0);//PWM比例0~255调速
//delay(time * 100); //执行时间，可以调整
}
void spin_right(int time) //右转(右轮后退，左轮前进)
{
    digitalWrite(RM_VOR,LOW); //右电机后退
    digitalWrite(RM_ZUR,HIGH);
    analogWrite(RM_VOR,0);
    analogWrite(RM_ZUR,200);//PWM比例0~255调速
    digitalWrite(LM_VOR,HIGH);//左电机前进
    digitalWrite(LM_ZUR,LOW);
    analogWrite(LM_VOR,200);
    analogWrite(LM_ZUR,0);//PWM比例0~255调速
    delay(time * 100); //执行时间，可以调整
}
//void back(int time) //后退
void back(int time)
{
    digitalWrite(RM_VOR,LOW); //右轮后退
    digitalWrite(RM_ZUR,HIGH);
    analogWrite(RM_VOR,0);
    analogWrite(RM_ZUR,150);//PWM比例0~255调速
    digitalWrite(LM_VOR,LOW); //左轮后退
    digitalWrite(LM_ZUR,HIGH);
    analogWrite(LM_VOR,0);
    analogWrite(LM_ZUR,150);//PWM比例0~255调速
    delay(time * 100); //执行时间，可以调整
}





