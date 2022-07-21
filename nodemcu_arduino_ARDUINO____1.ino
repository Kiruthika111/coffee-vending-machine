#include <SoftwareSerial.h>
//#define DHTPIN 10

int led = 13; 
SoftwareSerial espSerial(5, 6);

String str;

int state = LOW;
int val = 0;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  espSerial.begin(115200);
  //pinMode(DHTPIN, INPUT);

  delay(2000);
  
}
void loop()
{
 
int sta;
sta = 23;
espSerial.write(sta);
delay(1000);


}
