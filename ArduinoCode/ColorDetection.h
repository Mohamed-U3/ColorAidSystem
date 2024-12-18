#ifndef COLORDETECTION_H
#define COLORDETECTION_H

#include <math.h>
#include "PinConfig.h"
#include "Global.h"

#define COLOR_NAME_VARIABLE Global_Color_Name

struct Color
{
  const char* name;
  int r, g, b;
};

const Color colorDB[] =
{
  {"Red",     56,   255, 180},
  {"Green",   255,  144, 210},
  {"Blue",    244,  255, 147},
  {"Yellow",  70,   115, 255},
  {"Cyan",    255,  195, 124},
  {"Magenta", 222,  255, 123},
  {"White",   255,  255, 205},
  {"Black",   255,  250, 190},
  {"Gray",    255,  240, 198},
  {"Orange",  88,   160, 255},
  {"Pink",    100,  255, 195},
};
const int colorDBSize = sizeof(colorDB) / sizeof(colorDB[0]);

void setupColorDetector()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(OUT, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

int readColorFrequency(int s2, int s3)
{
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  return pulseIn(OUT, LOW);
}

int normalizeRGB(int value, int maxValue)
{
  return map(value, 0, maxValue, 0, 255);
}

float calculateDistance(int r1, int g1, int b1, int r2, int g2, int b2)
{
  return sqrt(pow(r1 - r2, 2) + pow(g1 - g2, 2) + pow(b1 - b2, 2));
}

const char* findClosestColor(int r, int g, int b)
{
  float minDistance = 1e6;
  const char* closestColor = "Unknown";

  for (int i = 0; i < colorDBSize; i++) {
    float distance = calculateDistance(r, g, b, colorDB[i].r, colorDB[i].g, colorDB[i].b);
    if (distance < minDistance) {
      minDistance = distance;
      closestColor = colorDB[i].name;
    }
  }

  return closestColor;
}

const char* loopColorDetector()
{
  // Read RGB frequencies
  int redFrequency    = readColorFrequency(LOW,   LOW);
  int greenFrequency  = readColorFrequency(HIGH,  HIGH);
  int blueFrequency   = readColorFrequency(LOW,   HIGH);

  // Normalize RGB
  int maxValue  = max(max(redFrequency, greenFrequency), blueFrequency);
  int red       = normalizeRGB(redFrequency, maxValue);
  int green     = normalizeRGB(greenFrequency, maxValue);
  int blue      = normalizeRGB(blueFrequency, maxValue);

  // Find closest color
  const char* colorName = findClosestColor(red, green, blue);

  // Print the result
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(", Green: ");
  Serial.print(green);
  Serial.print(", Blue: ");
  Serial.print(blue);
  Serial.print(" -> Detected Color: ");
  Serial.println(colorName);

  COLOR_NAME_VARIABLE = colorName;
  return colorName;
}

#endif//COLORDETECTION_H
