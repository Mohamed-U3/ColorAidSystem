#include "Global.h"
#include "ColorDetection.h"
#include "OLED.h"
#include "Buttons.h"
#include "audio.h"
#include "Vibration.h"

#define COLOR_NAME_VARIABLE Global_Color_Name

void setup()
{
  Serial.begin(9600);
  setupColorDetector();
  setupOLED();
  setupbuttons();
  setupAudio();
  setupVibration();
}

void loop()
{
  loopColorDetector();
  loopOLED();
  loopGlobal();
}

void loopGlobal()
{
  if (pressedButton() == DOWN_BUTTON_PIN)
  {
    if (Global_Selected_Mode == VOICE_MODE)
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
    else if (Global_Selected_Mode == VIBRATION_MODE)
    {
      if (Global_Color_Name == "Red")           Vibration_Red();
      else if (Global_Color_Name == "Green")    Vibration_Green();
      else if (Global_Color_Name == "Blue")     Vibration_Blue();
      else if (Global_Color_Name == "Yellow")   Vibration_Yellow();
      else if (Global_Color_Name == "Cyan")     Vibration_Cyan();
      else if (Global_Color_Name == "Magenta")  Vibration_Magenta();
      else if (Global_Color_Name == "White")    Vibration_White();
      else if (Global_Color_Name == "Black")    ;
      else if (Global_Color_Name == "Gray")     Vibration_Gray();
      else if (Global_Color_Name == "Orange")   Vibration_Orange();
      else if (Global_Color_Name == "Pink")     Vibration_Pink();
    }
  }
  else if (pressedButton() == LEFT_BUTTON_PIN)
  {
    //change modes
    Global_Selected_Mode++;
    if (Global_Selected_Mode > 2) Global_Selected_Mode = 1;
    delay(150);
  }
  else if (pressedButton() == RIGHT_BUTTON_PIN)
  {
    VolumeUp();
  }
  else if (pressedButton() == UP_BUTTON_PIN)
  {
    VolumeDown();
  }

}
