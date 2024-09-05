#define BLYNK_TEMPLATE_ID "TMPL3aN9Q9-CY"
#define BLYNK_TEMPLATE_NAME "SMOKE SENSOR"
#define BLYNK_AUTH_TOKEN "H_30Hz5KJ9pG-z914KpkchAtujLX_YO1"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;  //Enter your Blynk Auth token
char ssid[] = "indhu";  //Enter your WIFI SSID
char pass[] = "indhu1405";  //Enter your WIFI#define BLYNK_TEMPLATE_ID "TMPL3aN9Q9-CY"

#define MQ2 A0  // esp8266's pin connected to AO pin of the MQ2 sensor
BlynkTimer timer;
void setup() {
  // Initialize the Serial to communicate with the Serial Monitor.
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(MQ2,INPUT);
  timer.setInterval(100L, MQ2Sensor);
}
void loop() {
 
Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
void MQ2Sensor() {
  int gasValue = analogRead(MQ2);

  Serial.print("MQ2 sensor AO value: ");
  Blynk.virtualWrite(V2, gasValue);
  Serial.println(gasValue);
}
