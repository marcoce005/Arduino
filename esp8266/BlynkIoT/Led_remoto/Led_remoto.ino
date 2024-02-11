/*New blynk app project
   Home Page
*/

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "hdhdhhdhdhbdbbdbdbbd" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ciro-wifi";//Enter your WIFI name
char pass[] = "*********";//Enter your WIFI password

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(5, param.asInt());
}

BLYNK_WRITE(V1) {
  digitalWrite(BUILTIN_LED, !param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, LOW);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
