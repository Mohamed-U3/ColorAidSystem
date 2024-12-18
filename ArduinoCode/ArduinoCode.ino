#include "ColorDetection.h"

void setup()
{
  Serial.begin(9600);
  setupColorDetector();
}

void loop()
{
  const char* colorName = loopColorDetector();

  Serial.print(" -> Detected Color: ");
  Serial.println(colorName);
  delay(500);
}
