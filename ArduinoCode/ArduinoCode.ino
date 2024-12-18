#include "ColorDetection.h"
#include "Oled.h"
#include "Pages.h"
#include "Global.h"

void setup()
{
  Serial.begin(9600);
  setupColorDetector();
  setupOled();
}

void loop()
{
  loopColorDetector();
  loopPages();
  delay(500);
}
