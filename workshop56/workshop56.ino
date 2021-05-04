#include <Servo.h>

#define TMP A0
#define PIR 13
#define TRIGGER 11
#define ECHO 12
#define SERVO 3
#define PHOTO A1

#define LR 5
#define LB 6
#define LG 9

Servo servo;

void setup()
{
    pinMode(TMP, INPUT); // Temperature analog pin

    pinMode(ECHO, INPUT); // Input echo from HC-SR0
    pinMode(TRIGGER, OUTPUT); // Output trigger from HC-SR0
    digitalWrite(TRIGGER, LOW);

    pinMode(PHOTO, INPUT); // Input from photo-sensor

    pinMode(LR, OUTPUT);
    pinMode(LB, OUTPUT);
    pinMode(LG, OUTPUT);
    analogWrite(LR, 0);
    analogWrite(LG, 0);
    analogWrite(LB, 0);

    servo.attach(SERVO);
    closeServo();

    Serial.begin(9600); // Serial port at 9600 kb/s
}

const float MAX_DISTANCE = 15;
byte pirState = 0;

void loop()
{
    pirState = digitalRead(PIR);

    if (pirState == 1)
    {
        writeRGBColor(255, 255, 0); // Red flag
        Serial.println("person detected");

        float distance;
        distance = computeDistance();

        Serial.print("distance: ");
        Serial.println(distance);

        if (distance <= MAX_DISTANCE)
        {
            float averageTmp = readTemperature(3000);

            if (averageTmp > 37.5)
            {
                writeRGBColor(255, 0, 0); // Red flag
            }
            else
            {
                writeRGBColor(0, 255, 0); // Green flag
                openServo();

                unsigned int registerPhoto;
                while (1)
                {
                    registerPhoto = analogRead(PHOTO);

                    if (registerPhoto == 0)
                    {
                        Serial.print("person in");
                        delay(250);

                        closeServo();
                        writeRGBColor(255, 255, 255); // White flag
                        break;
                    }

                    delay(150);
                }
            }

            Serial.print("average-temperature: ");
            Serial.println(averageTmp);
        }

        pirState = 0;
        delay(100);
    }
}

float openServo()
{
    for (byte position = 90; position < 180; ++position)
    {
        servo.write(position);
        delay(30);
    }
}

float closeServo()
{
    for (byte position = 180; position > 90; --position)
    {
        servo.write(position);
        delay(30);
    }
}

float computeDistance()
{
    digitalWrite(TRIGGER, LOW);
    delay(2);
    digitalWrite(TRIGGER, HIGH); // Make TRIGGER high for 10 microsec to send pulse
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);

    unsigned long duration = pulseIn(ECHO, HIGH); // Time (microsecs) it takes to ultrasonic wave to come back

    /*
     * Sound speed in Air = 340 m/s
     * Multiply Sound speed  by 100 to get data in cm
     * Divide by 10^6 as duration is in microseconds
     * Divide it by 2 as ultrasound signal travels to object and comes back
     * Thus, distance = duration * ((34000/10^6)/2) = duration * 0.017
     */
    float distance = duration * 0.017;

    return distance;
}

// Read temperature for a given span of time and return
// average temperature.
float readTemperature(unsigned int span)
{
    float registerTmp;
    float vout;
    float temperature;
    float avgTemperature = -100;

    unsigned long start = millis();
    unsigned long current = start;

    while (current - start <= span)
    {
        registerTmp = analogRead(TMP); // Read temperature
        vout = (5 * registerTmp) / 1023;

        temperature = (vout - 0.5) / 0.01;

        if (avgTemperature < -41)
        {
            avgTemperature = temperature;
        }
        else
        {
            avgTemperature = (avgTemperature + temperature) / 2;
        }

        current = millis();
        delay(100); // Delay between readings for performance purposes
    }

    return avgTemperature;
}

void writeRGBColor(byte r, byte g, byte b)
{
    analogWrite(LR, r);
    analogWrite(LG, g);
    analogWrite(LB, b);
}
