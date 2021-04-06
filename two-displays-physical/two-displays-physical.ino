#define SEGA D0
#define SEGB D3
#define SEGC D5
#define SEGD D6
#define SEGE D2
#define SEGF D1
#define SEGG D4


#define TRANDIG1 D7
#define TRANDIG2 D8

void setup()
{
    pinMode(SEGA, OUTPUT);
    pinMode(SEGB, OUTPUT);
    pinMode(SEGC, OUTPUT);
    pinMode(SEGD, OUTPUT);
    pinMode(SEGE, OUTPUT);
    pinMode(SEGF, OUTPUT);
    pinMode(SEGG, OUTPUT);
    pinMode(TRANDIG1, OUTPUT);
    pinMode(TRANDIG2, OUTPUT);

    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);
    digitalWrite(TRANDIG1, LOW);
    digitalWrite(TRANDIG2, LOW);
}

byte counter = 0;
byte digit1 = 0;
byte digit2 = 0;

void loop()
{
    if (counter > 99)
    {
        counter = 0;
    }

    counter++;

    digit1 = counter / 10;
    digit2 = counter % 10;

    showDigit(digit1);
    digitalWrite(TRANDIG1, HIGH);
    delay(70);
    turnOffDisplay();
    showDigit(digit2);
    digitalWrite(TRANDIG2, HIGH);
    delay(70);
    turnOffDisplay();
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
        VB = HIGH;
        VD = HIGH;
        VE = HIGH;
        VF = HIGH;
        VG = HIGH;
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
        VA = HIGH;
    }

    if (d == 6)
    {
        VA = HIGH;
        VB = HIGH;
        VC = HIGH;
        VD = HIGH;
        VE = HIGH;
        VF = HIGH;
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
