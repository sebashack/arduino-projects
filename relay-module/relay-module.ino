#define VCC_RELAY 3

void setup()
{
    pinMode(VCC_RELAY, OUTPUT);
    digitalWrite(VCC_RELAY, LOW);
}

void loop()
{
    digitalWrite(VCC_RELAY, HIGH);
    delay(1000);
    digitalWrite(VCC_RELAY, LOW);
    delay(1000);
    Serial.print("here...");
}
