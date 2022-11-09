#include <Arduino.h>
#include <mat.h>

float pi = 3.1415926535;
int count = 0;
float diavr = 0.25;
int rotation = 0;

//time 
int ctime = millis();
int interval = 10;
// Tracks the time since last event fired
unsigned long previousMillis = 0;

//sensor
int sensorVoor = (32);
int valA = 0;

void setup() {
  Serial.begin(115200);
}

int snelheid(int dis, int currentMillis) {
  int speed = (dis / currentMillis);
  return speed;
}

void loop() {

 int movement = analogRead(sensorVoor);
 int dis = rotation *(diavr * pi);
 // Get snapshot of time
 unsigned long currentMillis = millis();

 valA = analogRead(sensorVoor);
  if( valA > 1 ){
   valA = 1;}
  Serial.println(valA);

 if (valA > 1){
  count++;
 }

 if (count == 3){ 
  count = 0;
  rotation++;
 }

 int dis = rotation * (diavr * pi);

 // How much time has passed, accounting for rollover with subtraction!
 if ((unsigned long)(currentMillis - previousMillis) >= interval) { 
  previousMillis = currentMillis;
 
 }
}