#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "esp8266-19726-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "fyVJRpCqc7LzfQ5X5CIvnGK8NblE3BmEBg1v9naw"
#define WIFI_SSID "kitcha bsnl"
#define WIFI_PASSWORD "kitcha1234"

void setup() {
// Open serial communications and wait for port to open:
Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}


void loop() { // run over and over
if (Serial.available()) {
//Serial.write(Serial.read());
int value = Serial.read();
Serial.print("value : ");
Serial.println(value);  
//Firebase.setInt("status", 1);
  // handle error
  //if (Firebase.failed()) {
  //    Serial.print("setting /number failed:");
  //    Serial.println(Firebase.error());  
  //    return;
 // }
 // delay(1000);

  // get value 
  //Serial.print("status: ");
  //Serial.println(Firebase.getInt("status"));
  //delay(1000);
  Firebase.setInt("sensor_val", value);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
}
}
