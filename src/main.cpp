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
int sensorVoorChannelA = 35;
int sensorVoorChannelB = 25;
// De huidige waarde van de sensor (channel A)


void setup()
{
    Serial.begin(115200);
}

// int snelheid(int distance, int currentMillis)
// {
//     int speed = (distance / currentMillis);
//     return speed;
// }

void loop()
{
    int checkValueA = analogRead(sensorVoorChannelA);
    int checkValueB = analogRead(sensorVoorChannelB);
    Serial.print("checkValueA =");
    Serial.print(checkValueA);
    Serial.print(" en checkValueB =");
    Serial.println(checkValueB);
    delay(200);
 
    // int checkValueB = analogRead(sensorVoorChannelB);
 
    // digital omzetten 
    // als de waarde groter is dan 1 zet de waarde naar 1 anders naar 0
    // if (checkValueA > 1)
    // {
    //     checkValueA = 1;
    // }
    // Serial.print("Sensor waarde is")
    // else
    // {
    //     checkValueA = 0;
    // }

    // int previousValue = checkValueA;


    // if (previousValue == 0)
    // {
    //     // 1 rotatie is voltooid
    //     if (count == 3)
    //     {
    //         count = 0;
    //         Serial.println("rondje gemaakt");
    //         Serial.print("count: ");
    //         Serial.println(count);
    //         delay(1000);
    //     }
    //     else
    //     {
    //         count++;
    //         Serial.print("count: ");
    //         Serial.println(count);
    //         delay(1000);
    //     }
    // }
    // Serial.println("hallo");

    // Serial.println(checkValueA);
    // int distance = rotation * (diavr * pi);
    // // Get snapshot of time
    //     unsigned long currentMillis = millis();


    // How much time has passed, accounting for rollover with subtraction
    // if the time since the last loop is greater than the interval

    // if (currentMillis - previousMillis >= interval)
    // {
    //     // save the last time you blinked the LED
    //     previousMillis = currentMillis;
    //     Serial.println("distance: " + distance);
    //     Serial.println("snelheid: " + snelheid(distance, currentMillis));
    // }
}