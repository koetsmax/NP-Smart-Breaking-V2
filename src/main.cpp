#include <Arduino.h>
#include <mat.h>

// creeer constant variables
float pi = 3.1415926535;
int count = 0;
float diavr = 0.25;
int rotation = 0;

// creer constant interval voor de tijd
int interval = 10;
// Tracks the time for how long the program has been running for
unsigned long previousMillis = 0;

// Datapin waar de voorsensor is aangesloten (channel A)
int sensorVoorChannelA = 32;
int sensorVoorChannelB = 25;
// De huidige waarde van de sensor (channel A)
int valSensorVoor = 0;

void setup()
{
    Serial.begin(115200);
}

int snelheid(int distance, int currentMillis)
{
    int speed = (distance / currentMillis);
    return speed;
}

void loop()
{
    // int checkValueA = analogRead(sensorVoorChannelA);
    int checkValueB = analogRead(sensorVoorChannelB);

    if (checkValueB > 1)
    {
        Serial.println(checkValueB);
        delay(50);
    }
    else
    {
        Serial.println("Het is nul");
        delay(50);
    }
    // int distance = rotation * (diavr * pi);
    // // Get snapshot of time
    // // unsigned long currentMillis = millis();

    // valSensorVoor = analogRead(sensorVoor);
    // // zet de waardevan de voor sensor naar 1 als de waarde groter is dan 1
    // if (valSensorVoor > 1)
    // {
    //     Serial.println("waarde is hoger dan " + String(valSensorVoor));
    //     // valSensorVoor = 1;
    //     count++;
    // }
    // // Serial.println(valSensorVoor);

    // // als de count groter is dan 3
    // if (count == 3)
    // {
    //     count = 0;
    //     rotation++;
    //     // Serial.println("rotation");
    // }

    // // How much time has passed, accounting for rollover with subtraction
    // // if the time since the last loop is greater than the interval

    // // if (currentMillis - previousMillis >= interval)
    // // {
    // //     // save the last time you blinked the LED
    // //     previousMillis = currentMillis;
    // //     Serial.println("distance: " + distance);
    // //     Serial.println("snelheid: " + snelheid(distance, currentMillis));
    // // }
}