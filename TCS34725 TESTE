#include "TCS34725.h"
TCS34725 tcs;

void setup(void)
{
    Serial.begin(115200);

    Wire.begin();
    if (!tcs.attach(Wire))
        Serial.println("ERROR: TCS34725 NOT FOUND !!!");

    tcs.integrationTime(53); // ms
    tcs.gain(TCS34725::Gain::X01);

    // set LEDs...
    analogWrite(A0, LOW);
}

void loop(void)
{
    if (tcs.available()) // if current measurement has done
    {
        TCS34725::Color color = tcs.color();
        
        
        Serial.print("Red: "); Serial.print(color.r);
        Serial.print(" Green: "); Serial.print(color.g);
        Serial.print(" Blue: "); Serial.println(color.b);
    }
}
