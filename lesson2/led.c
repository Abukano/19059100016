/*
代码规范：
1.全部英文半角符号
2.大小写敏感
*/

void setup()
{
  int i=1;
  for (i=1;i<8;i++)
       {
         pinMode(i, OUTPUT);
       }
}

void loop()
{
  int i;
  for (i=0;i<8;i++)
  {
    digitalWrite(i%8, HIGH);
    digitalWrite((i+1)&8, HIGH);
    digitalWrite((i+2)%8, HIGH);
    digitalWrite((i+3)%8, HIGH);
    delay(200);
    if(i==1)
    {
      digitalWrite(7,LOW);
    }
    else
    {
    digitalWrite((i-1)%8,LOW);
    }
  }
}

