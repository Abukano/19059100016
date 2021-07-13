
#define in1 7
#define in2 4
#define in3 5
#define in4 6
int num =0;

void setup()
{
  Serial.begin(9600);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop()
{
  if(Serial.available()>0)
  {
    byte income =0;
    income=Serial.read();
    income=income-'0';
    digitalWrite(in1,income&0x1);
    digitalWrite(in2,(income>>1)&0x1);
    digitalWrite(in3,(income>>2)&0x1);
    digitalWrite(in4,(income>>3)&0x1);
  }
}