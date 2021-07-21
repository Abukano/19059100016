#include <MsTimer2.h>
#define in1 8
#define in2 5
#define in3 6
#define in4 7
#define S1 4
#define S2 3
#define pinInterrupt 2
int num2 =0;
int num1 =0;

void light(int n)
{
    digitalWrite(in1,n&0x1);
    digitalWrite(in2,(n>>1)&0x1);
    digitalWrite(in3,(n>>2)&0x1);
    digitalWrite(in4,(n>>3)&0x1);
}
void onChange()
{
  num1 =0;
  num2 =0;
  digitalWrite(S1,LOW);//s1有效
  digitalWrite(S2,LOW);//S2有效
  light(0);
  digitalWrite(S1,HIGH);//s1锁存
  digitalWrite(S2,HIGH);//S2锁存
  MsTimer2::start(); 
}
void onTimer()
{
  if(num1<9)
  {
    num1++;
  }
  else
  {
    num1=0;
    num2++;
    if(num2>9)
    {num2=0;}
  }
  digitalWrite(S2,LOW);//s2有效
  light(num1);
  digitalWrite(S2,HIGH);//s2锁存
  digitalWrite(S1,LOW);//s1有效
  light(num2);
  digitalWrite(S1,HIGH);//s1锁存
}
void setup()
{
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(pinInterrupt, INPUT);
  digitalWrite(S1,HIGH);//s1有效
  digitalWrite(S2,HIGH);//S2锁存
  MsTimer2::set(1000, onTimer);
  MsTimer2::start(); 
}

void loop()
{
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
}