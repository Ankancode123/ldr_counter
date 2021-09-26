#include <TM1637Display.h>

int F = A0;
int B = A1;
int count = 0;
int fan = 13;
int light = 12;

#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000


TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  pinMode(F,INPUT);
  pinMode(B,INPUT);
  pinMode(fan,OUTPUT);
  pinMode(light,OUTPUT);// put your setup code here, to run once:

}

void loop() {

  display.setBrightness(0x0f);
  Serial.print("f = ");
    Serial.println(analogRead(F));
  Serial.print("b = ");
    Serial.println(analogRead(B));
    
    if(analogRead(F)>1010)
    {
      for(int i=0;i<300;i++)
       {
          if(analogRead(B)>1010)
            {
              count++;
              Serial.println(count);
              break;
            }
        delay(1);
       }
    }

  else if(analogRead(B)>1010)
    {
      for(int i=0;i<300;i++)
       {
          if(analogRead(F)>1010)
            {
              count--;
              Serial.println(count);
              break;
            }
        delay(1);
       }
    }

    display.showNumberDec(count);
if(count>0)
    digitalWrite(light,HIGH);
else
  digitalWrite(light,LOW);


if(count<3)
      digitalWrite(fan,LOW);
    
else
      digitalWrite(fan,HIGH);
  // put your main code here, to run repeatedly:
}