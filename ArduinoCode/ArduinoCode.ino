#include "Global.h"
#include "ColorDetection.h"
#include "OLED.h"
#include "Buttons.h"
#include "audio.h"


#define COLOR_NAME_VARIABLE Global_Color_Name

void setup()
{
  Serial.begin(9600);
  setupColorDetector();
  setupOLED();
  setupbuttons();
  setupAudio();
}

void loop()
{
  loopColorDetector();
  loopOLED();
  loopGlobal();
}

void loopGlobal()
{
  if (pressedButton() != -1)
  {
    PlayAudio(3);
    if (Global_Color_Name == "Red")           PlayAudio(4);
    else if (Global_Color_Name == "Green")    PlayAudio(5);
    else if (Global_Color_Name == "Blue")     PlayAudio(6);
    else if (Global_Color_Name == "Yellow")   PlayAudio(7);
    else if (Global_Color_Name == "Cyan")     PlayAudio(8);
    else if (Global_Color_Name == "Magenta")  PlayAudio(9);
    else if (Global_Color_Name == "White")    PlayAudio(10);
    else if (Global_Color_Name == "Black")    PlayAudio(11);
    else if (Global_Color_Name == "Gray")     PlayAudio(12);
    else if (Global_Color_Name == "Orange")   PlayAudio(13);
    else if (Global_Color_Name == "Pink")     PlayAudio(14);
    delay(500);
    PlayAudio(15);
  }
}
