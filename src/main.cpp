#include <Arduino.h>

// creeer cons.0dretant variables
float pi = 3.1415926535; // nodig voor uitreken van omtrek van de wielen
int count = 0;           // count gemaakt om rotaties te meten.
float diameterVoorBand = 0.25;
float rotation = 0; // if count == 2, dan roation++
bool magneetVoorSensor = false;
float distance = 0;

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
// int snelheid(int distance, int currentMillis)
// {
//     int speed = (distance / currentMillis);
//     return speed;
// }

void loop()
{
    int checkValueA = analogRead(sensorVoorChannelA);
    if (checkValueA > 100)
    {
        checkValueA = 1;
    }
    else
    {
        checkValueA = 0;
    }
    int checkValueB = analogRead(sensorVoorChannelB);
    if (checkValueB > 100)
    {
        checkValueB = 1;
    }
    else
    {
        checkValueB = 0;
    }

    // Bepaal of de kart vooruit of acheruit gaat
    // if (checkValueA == 1 && checkValueB == 0)
    // {
    //     Serial.println("Vooruit");
    // }
    // else if (checkValueA == 0 && checkValueB == 1)
    // {
    //     Serial.println("Achteruit");
    // }

    if (checkValueA && checkValueB == 1)
    {
        if (PreviousValueA != checkValueA)
        {
            if (PreviousValueB != checkValueB)
            {
                magneetVoorSensor = true;
            }
        }
    }

    if (magneetVoorSensor)
    {
        // Serial.println("vooruit half rondje gemaakt");
        count++;
        if (count == 2)
        {
            unsigned long startmills = millis();
            rotation++;

            delay(50); // testen voor serial print, want waarden zijn niet constant

            float distance = (rotation / 2) * (diameterVoorBand * pi);
            Serial.print("distance in meters: ");
            Serial.println(distance);
            magneetVoorSensor = false;
            count = 0;
        }

        static unsigned long lastTime = millis();
        unsigned long currentTime = millis();

        if (currentTime - lastTime >= 1000)
        {
            float distance2 = (rotation / 2) * (diameterVoorBand * pi);
            lastTime = currentTime;
        }
    }
}
// Serial.print("checkValueA =");
// Serial.print(checkValueA);
// Serial.print(" en checkValueB =");
// Serial.println(checkValueB);

// int checkValueB = analogRead(sensorVoorChannelB);

// digital omzetten
//     als de waarde groter is dan 1 zet de waarde naar 1 anders naar 0 if (checkValueA > 1)
// {
//     checkValueA = 1;
// }
// Serial.print("Sensor waarde is") else
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
// int distance = rotation * (diameterVoorBand * pi);
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
//}