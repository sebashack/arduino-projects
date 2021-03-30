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

#define TRAN1 A2
#define TRAN2 A3

#define MAX_COLOR 255

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

    pinMode(TRAN1, OUTPUT);
    pinMode(TRAN2, OUTPUT);

    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);

    digitalWrite(TRAN1, LOW);
    digitalWrite(TRAN2, LOW);

    analogWrite(LR, 0);
    analogWrite(LG, 0);
    analogWrite(LB, 0);
}


byte IS_START = 1;

byte counter = 0;
byte button_state = 0;
byte last_button_state = 0;
byte R;
byte B;
byte G;


void loop()
{
    if (IS_START)
    {
        digitalWrite(TRAN1, HIGH);
        digitalWrite(TRAN2, HIGH);
        IS_START = 0;
    }

    while (true)
    {
        show_digit(7);
        digitalWrite(TRAN1, LOW);
        delay(100);
        turn_off_display();
        show_digit(9);
        digitalWrite(TRAN2, LOW);
        delay(100);
        turn_off_display();
    }

    //byte button_state = digitalRead(BUTTON);

    //if (button_state != last_button_state)
    //{
    //    if (counter > 9)
    //    {
    //        counter = 0;
    //    }

    //    if (button_state == HIGH && counter < 10)
    //    {
    //        turn_on_display();
    //        show_digit(counter);
    //        counter++;
    //        delay(50);
    //    }

    //}

    //last_button_state = button_state;
}

void turn_off_display()
{
    digitalWrite(TRAN1, HIGH);
    digitalWrite(TRAN2, HIGH);
}

void turn_on_display()
{
    digitalWrite(TRAN1, LOW);
    digitalWrite(TRAN2, LOW);
}

void show_digit(byte d)
{
    byte VA = HIGH;
    byte VB = HIGH;
    byte VC = HIGH;
    byte VD = HIGH;
    byte VE = HIGH;
    byte VF = HIGH;
    byte VG = HIGH;


    if (d == 0)
    {
        VA = LOW;
        VB = LOW;
        VC = LOW;
        VE = LOW;
        VF = LOW;
        VG = LOW;
    }

    if (d == 1)
    {
        VA = LOW;
        VG = LOW;
    }

    if (d == 2)
    {
        VA = LOW;
        VB = LOW;
        VD = LOW;
        VE = LOW;
        VF = LOW;
    }

    if (d == 3)
    {
        VA = LOW;
        VB = LOW;
        VD = LOW;
        VF = LOW;
        VG = LOW;
    }

    if (d == 4)
    {
        VA = LOW;
        VC = LOW;
        VD = LOW;
        VG = LOW;
    }

    if (d == 5)
    {
        VB = LOW;
        VC = LOW;
        VD = LOW;
        VF = LOW;
        VG = LOW;
    }

    if (d == 6)
    {
        VB = LOW;
        VC = LOW;
        VD = LOW;
        VE = LOW;
        VF = LOW;
        VG = LOW;
    }

    if (d == 7)
    {
        VA = LOW;
        VB = LOW;
        VG = LOW;
    }

    if (d == 8)
    {
        VA = LOW;
        VB = LOW;
        VC = LOW;
        VD = LOW;
        VE = LOW;
        VF = LOW;
        VG = LOW;
    }

    if (d == 9)
    {
        VA = LOW;
        VB = LOW;
        VC = LOW;
        VD = LOW;
        VF = LOW;
        VG = LOW;
    }

    digitalWrite(SEGA, VA);
    digitalWrite(SEGB, VB);
    digitalWrite(SEGC, VC);
    digitalWrite(SEGD, VD);
    digitalWrite(SEGE, VE);
    digitalWrite(SEGF, VF);
    digitalWrite(SEGG, VG);
}
