#define TMP 0
#define LR 5
#define LB 6
#define LG 9

void setup()
{
    pinMode(TMP, INPUT); // Temperature analog pin

    pinMode(LR, OUTPUT);
    pinMode(LB, OUTPUT);
    pinMode(LG, OUTPUT);
    analogWrite(LR, 0);
    analogWrite(LG, 0);
    analogWrite(LB, 0);

    Serial.begin(9600); // Serial port at 9600 kb/s
}

void loop()
{
    float averageTmp = readTemperature(3000);

    writeRGBColor(255, 0, 0);

    Serial.print("average-temperature: ");
    Serial.println(averageTmp);
}

// Read temperature for a given span of time and return
// average temperature.
float readTemperature(unsigned int span)
{
    float registerTmp=0;
    float vout=0;
    float accumTmp = 0;
    float numberOfReadings = 0;

    unsigned long start = millis();
    unsigned long current = start;

    while (current - start <= span)
    {
        registerTmp = analogRead(TMP); // Read temperature
        vout = (5 * registerTmp) / 1023;

        accumTmp += (vout - 0.5) / 0.01;
        ++numberOfReadings;
        current = millis();
        delay(100); // Delay between readings for performance purposes
    }

    Serial.print("accumulated-tmp: ");
    Serial.println(accumTmp);
    Serial.print("readings: ");
    Serial.println(numberOfReadings);

    return (accumTmp / numberOfReadings);
}

void writeRGBColor(byte r, byte g, byte b)
{
    analogWrite(LR, r);
    analogWrite(LG, g);
    analogWrite(LB, b);
}
