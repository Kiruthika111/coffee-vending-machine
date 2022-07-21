#define POWER_PIN  10
#define SIGNAL_PIN A0
#include "LCDIC2.h"
LCDIC2 lcd(0x27, 16, 2);

#define CW 3 //CW is defined as pin #7//
#define CCW 4 //CCW is defined as pin #8//

//flag
int cup_detected = 1;


//pins
const int trigPin = 7;
const int echoPin = 6;
const int LED_GREEN = 8;
const int LED_WHITE = 9;
const int buzzer = 11;
long duration;

//flag
int ultra_flag = 1;
int level_flag = 1;

//****variables*****
int distance;
int coffee_level = 500; // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  //waterlevel
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW); // turn the sensor OFF
if (lcd.begin()) lcd.print("WELCOME!");
  delay(2000);
//ultrasonic
  pinMode(trigPin, OUTPUT);    // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);     // Sets the echoPin as an Input
  pinMode(LED_GREEN, OUTPUT);
  pinMode(buzzer, OUTPUT);

//motor
  
  pinMode(CW, OUTPUT); //Set CW as an output//
  pinMode(CCW, OUTPUT); //Set CCW as an output//
}

void loop() {

  //level_sensor();
  level();
  if(coffee_level>150){
    ultra_sonic();
  }
  delay(2000);
}


void level() {
  coffee_level = coffee_level - 100;
  if(coffee_level < 150)
  {
     Serial.println(coffee_level);
     lcd.setCursor(0, 0);
     lcd.print("REFILL REQUIRED ");
     Serial.println("LCD PRINT 1");
     level_flag = 0;
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("_ _ _ _ _ _ _ _ _ _");
    Serial.println("LCD PRINT 2");
  }
}


void level_sensor() {
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  coffee_level = analogRead(SIGNAL_PIN); // read the analog value from waterlevel sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF
  Serial.print("Sensor value: ");
  Serial.println(coffee_level);
  if(coffee_level < 150)
  {
     Serial.println(coffee_level);
     lcd.setCursor(0, 0);
     lcd.print("REFILL REQUIRED ");
     lcd.setCursor(0, 1);
     lcd.print("_ _ _ _ _ _ _ _ ");
     digitalWrite(LED_WHITE, HIGH);
     level_flag = 0;
  }
  else{
    digitalWrite(LED_WHITE, LOW);
    lcd.setCursor(0, 0);
    lcd.print("_ _ _  _ _ _ _ _");
    lcd.setCursor(0, 1);
    lcd.print("_ _ _ _ _ _ _ _ ");
   
  }
}

void ultra_sonic() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if(distance <= 10)
  {
    Serial.println("Object detected");
    Serial.println(distance);
    digitalWrite(LED_GREEN, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("166228978123456 ");
    lcd.setCursor(0, 1);
    lcd.print("Order Processing");
    Serial.println("LCD PRINT 3");
    run_motor();
    delay(2000);
  }

  else
  {
    Serial.println("Object is far!");
    digitalWrite(LED_GREEN, LOW);
    lcd.setCursor(0, 0);
    lcd.print("_ _ _  _ _ _ _ _");
    lcd.setCursor(0, 1);
    lcd.print("Please Place Cup");
    Serial.println("LCD PRINT 4");
    delay(2000);
    motor_off();
  }
  ultra_flag = 0;
}

void run_motor() {
  
  digitalWrite(CW,HIGH); 
  delay(7000);
  digitalWrite(CW, LOW); 
  delay(3000);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void motor_off() {
  digitalWrite(CW, LOW); //Motor stops//
}
