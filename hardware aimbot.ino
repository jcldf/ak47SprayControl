//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with 
// Pixy and Arduino.  This program simply prints the detected object blocks 
// (including color codes) through the serial console.  It uses the Arduino's 
// ICSP SPI port.  For more information go here:
//
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29
//
  
#include <Pixy2.h>
#include <SPI.h>
#include <Mouse.h>

// This is the main Pixy object 
Pixy2 pixy;


void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  Mouse.begin();
  pixy.init();
}

void loop()
{ 
  int i; 
  // grab blocks!
  pixy.ccc.getBlocks();
  
  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    Serial.print("Detected ");
    Serial.println(pixy.ccc.numBlocks);
    for (i=0; i<pixy.ccc.numBlocks; i++)
    {
      Serial.print("  block ");
      Serial.print(i);
      Serial.print(": ");
      //pixy.ccc.blocks[i].print();
      int width = pixy.ccc.blocks[i].m_x;
      int height = pixy.ccc.blocks[i].m_y;
      Serial.print(width); 
      Serial.print(" "); 
      Serial.println(height);
      int x = map(width, 0, 315, 0, 1920);
      int y = map(height, 0, 207, 0, 1080); 
      Serial.print(x);
      Serial.print(" ");
      Serial.println(y);
      delay(100);
    }
  }  
}
