#define SEGA 2
#define SEGB 3
#define SEGC 4
#define SEGD 5
#define SEGE 6
#define SEGF 7
#define SEGG 8

#define LG 9
#define LB 10
#define LR 11

#define BUTTON 12

#define TRANDIG1 A2
#define TRANDIG2 A3
#define TRANBULB A4

void setup()
{
    pinMode(SEGA, OUTPUT);
    pinMode(SEGB, OUTPUT);
    pinMode(SEGC, OUTPUT);
    pinMode(SEGD, OUTPUT);
    pinMode(SEGE, OUTPUT);
    pinMode(SEGF, OUTPUT);
    pinMode(SEGG, OUTPUT);

    pinMode(BUTTON, INPUT);

    pinMode(LR, OUTPUT);
    pinMode(LB, OUTPUT);
    pinMode(LG, OUTPUT);

    pinMode(TRANDIG1, OUTPUT);
    pinMode(TRANDIG2, OUTPUT);
    pinMode(TRANBULB, OUTPUT);

    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);

    digitalWrite(TRANDIG1, LOW);
    digitalWrite(TRANDIG2, LOW);
    digitalWrite(TRANBULB, LOW);

    analogWrite(LR, 0);
    analogWrite(LG, 0);
    analogWrite(LB, 0);
}

byte IS_START = 1;
byte counter = 0;
byte buttonState = 0;
byte lastButtonState = 0;
byte digit1 = 0;
byte digit2 = 0;

void loop()
{
    byte buttonState = digitalRead(BUTTON);

    if (IS_START)
    {
        // White
        writeColorOnLed(255, 255, 255);
        IS_START = 0;
    }

    if (buttonState != lastButtonState)
    {
        if (counter > 99)
        {
            digitalWrite(TRANBULB, LOW);
            counter = 0;
        }

        digit1 = counter / 10;
        digit2 = counter % 10;

        if (buttonState == HIGH && counter < 100)
        {
            counter++;

            if (counter >= 10 && counter <= 28)
            {
                // Yellow
                writeColorOnLed(255, 201, 14);
            }

            if (counter > 30 && counter <= 60)
            {
                // Orange
                writeColorOnLed(252, 131, 38);
            }

            if (counter > 85)
            {
                // Red
                writeColorOnLed(255, 0, 0);
            }

            if (counter > 99)
            {
                // White
                writeColorOnLed(255, 255, 255);
            }

            if (counter <= 20)
            {
                digitalWrite(TRANBULB, LOW);
            }

            if (counter >= 43)
            {
                digitalWrite(TRANBULB, HIGH);
            }
        }
    }

    showDigit(digit1);
    digitalWrite(TRANDIG1, HIGH);
    delay(50);
    turnOffDisplay();
    showDigit(digit2);
    digitalWrite(TRANDIG2, HIGH);
    delay(50);
    turnOffDisplay();

    lastButtonState = buttonState;
}

void writeColorOnLed(byte R, byte G, byte B)
{
    analogWrite(LR, R);
    analogWrite(LG, G);
    analogWrite(LB, B);
}

void turnOffDisplay()
{
    digitalWrite(TRANDIG1, LOW);
    digitalWrite(TRANDIG2, LOW);
}

void showDigit(byte d)
{
    byte VA = LOW;
    byte VB = LOW;
    byte VC = LOW;
    byte VD = LOW;
    byte VE = LOW;
    byte VF = LOW;
    byte VG = LOW;


    if (d == 0)
    {
        VA = HIGH;
        VB = HIGH;
        VC = HIGH;
        VE = HIGH;
        VF = HIGH;
        VG = HIGH;
    }

    if (d == 1)
    {
        VA = HIGH;
        VG = HIGH;
    }

    if (d == 2)
    {
        VA = HIGH;
        VB = HIGH;
        VD = HIGH;
        VE = HIGH;
        VF = HIGH;
    }

    if (d == 3)
    {
        VA = HIGH;
        VB = HIGH;
        VD = HIGH;
        VF = HIGH;
        VG = HIGH;
    }

    if (d == 4)
    {
        VA = HIGH;
        VC = HIGH;
        VD = HIGH;
        VG = HIGH;
    }

    if (d == 5)
    {
        VB = HIGH;
        VC = HIGH;
        VD = HIGH;
        VF = HIGH;
        VG = HIGH;
    }

    if (d == 6)
    {
        VB = HIGH;
        VC = HIGH;
        VD = HIGH;
        VE = HIGH;
        VF = HIGH;
        VG = HIGH;
    }

    if (d == 7)
    {
        VA = HIGH;
        VB = HIGH;
        VG = HIGH;
    }

    if (d == 8)
    {
        VA = HIGH;
        VB = HIGH;
        VC = HIGH;
        VD = HIGH;
        VE = HIGH;
        VF = HIGH;
        VG = HIGH;
    }

    if (d == 9)
    {
        VA = HIGH;
        VB = HIGH;
        VC = HIGH;
        VD = HIGH;
        VF = HIGH;
        VG = HIGH;
    }

    digitalWrite(SEGA, VA);
    digitalWrite(SEGB, VB);
    digitalWrite(SEGC, VC);
    digitalWrite(SEGD, VD);
    digitalWrite(SEGE, VE);
    digitalWrite(SEGF, VF);
    digitalWrite(SEGG, VG);
}
