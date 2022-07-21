#include <SoftwareSerial.h>
//#define DHTPIN 10

int led = 13; 
SoftwareSerial espSerial(5, 6); 

String str;
int sta;
int state = LOW;
int val;
int read_value;

void setup(){
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  espSerial.begin(115200);
  //pinMode(DHTPIN, INPUT);

  //delay(2000);

  
//nodemcu - arduino
  while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}

}
void loop()
{
if (espSerial.available()) {
//Serial.write(Serial.read());
read_value = Serial.read();
//str = Serial.read();
//str =String("coming from ESP8266: ")+String("H= ")+String(h)+String("T= ")+String(t);

 Serial.println(read_value);
 delay(10000);
 //delay(1000);
}


val = HIGH;  // read sensor value

sta = sta+1;

//espSerial.println(sta);
espSerial.write(sta);
delay(10000);
//delay(1000);


}
