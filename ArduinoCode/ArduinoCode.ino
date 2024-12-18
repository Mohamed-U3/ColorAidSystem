#include "ColorDetection.h"
#include "OLED.h"
#include "Buttons.h"
#include "Global.h"
#include "audio.h"

//#define COLOR_NAME_VARIABLE Global_Color_Name

void setup()
{
  Serial.begin(9600);
  setupColorDetector();
//  setupOled();
  setupOLED();
  setupbuttons();
  setupAudio();
}

void loop()
{
  loopColorDetector();
//  loopPages();
  loopOLED();
  if (pressedButton() != -1)
  {
    PlayAudio(3);
    if (COLOR_NAME_VARIABLE == "Red")     PlayAudio(4);
    if (COLOR_NAME_VARIABLE == "Green")   PlayAudio(5);
    if (COLOR_NAME_VARIABLE == "Blue")    PlayAudio(6);
    if (COLOR_NAME_VARIABLE == "Yellow")  PlayAudio(7);
    if (COLOR_NAME_VARIABLE == "Cyan")    PlayAudio(8);
    if (COLOR_NAME_VARIABLE == "Magenta") PlayAudio(9);
    if (COLOR_NAME_VARIABLE == "White")   PlayAudio(10);
    if (COLOR_NAME_VARIABLE == "Black")   PlayAudio(11);
    if (COLOR_NAME_VARIABLE == "Gray")    PlayAudio(12);
    if (COLOR_NAME_VARIABLE == "Orange")  PlayAudio(13);
    if (COLOR_NAME_VARIABLE == "Pink")    PlayAudio(14);
    PlayAudio(15);
  }
}
