#include <Arduino.h>

// creeer cons.0dretant variables
float pi = 3.1415926535;
int count = 0;
float diavr = 0.25;
int rotation = 0;
bool pietje = false;
// creer constant interval voor de tijd
int interval = 5000;
// Tracks the time for how long the program has been running for
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

int PreviousValueA = 0;
int PreviousValueB = 0;

// Datapin waar de voorsensor is aangesloten (channel A)
int sensorVoorChannelA = A0;
int sensorVoorChannelB = A1;
// De huidige waarde van de sensor (channel A)

void setup()
{
    Serial.begin(9600);
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
    if (checkValueA && checkValueB > 20)
    {
        Serial.print("checkValueA =");
        Serial.println(checkValueA);
        Serial.print(" en checkValueB =");
        Serial.println(checkValueB);
        if (PreviousValueA != checkValueA)
        {
            if (PreviousValueB != checkValueB)
            {
                pietje = true;
            }
        }
    }

    if (pietje == true)
    {
        Serial.println("vooruit half rondje gemaakt");
        count++;
        if (count == 2)
        {
            unsigned long startmills = millis();
            rotation++;
            Serial.print("rotation: ");
            Serial.println(rotation / 2);
            // Serial.print("checkValueA: ");
            // Serial.println(checkValueA);
            // Serial.print("checkValueB: ");
            // Serial.println(checkValueB);
            // Serial.print("PreviousValueA: ");
            // Serial.println(PreviousValueA);
            // Serial.print("PreviousValueB: ");
            // Serial.println(PreviousValueB);
            // delay(15);
            unsigned long endmills = millis();
            Serial.print("time: ");
            Serial.println(endmills - startmills);
            pietje = false;
            count = 0;
        }
    }

    // Serial.print("checkValueA =");
    // Serial.print(checkValueA);
    // Serial.print(" en checkValueB =");
    // Serial.println(checkValueB);

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