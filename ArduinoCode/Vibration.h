#ifndef VIBRATION_H
#define VIBRATION_H

#include "PinConfig.h"

void setupVibration()
{
  pinMode(VIBRATION_PIN,OUTPUT);
  digitalWrite(VIBRATION_PIN,LOW);
}

void Vibration_on()
{
  digitalWrite(VIBRATION_PIN,HIGH);
}
void Vibration_off()
{
  digitalWrite(VIBRATION_PIN,LOW);
}

void Vibration_Red()
{
  Vibration_on();
  delay(500);
  Vibration_off();
}

void Vibration_Green()
{
  Vibration_on();
  delay(500);
  Vibration_off();
  delay(500);
  Vibration_on();
  delay(500);
  Vibration_off();
}

void Vibration_Blue()
{
  Vibration_on();
  delay(500);
  Vibration_off();
  delay(500);
  Vibration_on();
  delay(500);
  Vibration_off();
  delay(500);
  Vibration_on();
  delay(500);
  Vibration_off();
}

void Vibration_Yellow()
{
  Vibration_on();
  delay(1500);
  Vibration_off();
}

void Vibration_Cyan()
{
  Vibration_on();
  delay(1500);
  Vibration_off();
  delay(1500);
  Vibration_on();
  delay(1500);
  Vibration_off();
}

void Vibration_Magenta()
{
  Vibration_on();
  delay(1500);
  Vibration_off();
  delay(1500);
  Vibration_on();
  delay(1500);
  Vibration_off();
  delay(1500);
  Vibration_on();
  delay(1500);
  Vibration_off();
}

void Vibration_White()
{
  Vibration_on();   delay(1000);
  Vibration_off();  delay(500);
  Vibration_on();   delay(500);
  Vibration_off();
}

void Vibration_Gray()
{
  Vibration_on();   delay(200);
  Vibration_off();  delay(200);
  Vibration_on();   delay(200);
  Vibration_off();  delay(200);
  Vibration_on();   delay(200);
  Vibration_off();  delay(200);
  Vibration_on();   delay(200);
  Vibration_off();  delay(200);
  Vibration_on();   delay(200);
  Vibration_off();  delay(200);
  Vibration_on();   delay(200);
  Vibration_off();
}
void Vibration_Orange()
{
  Vibration_on();  delay(200);
  Vibration_off(); delay(1000);
  Vibration_on();  delay(200);
  Vibration_off();
}

void Vibration_Pink()
{
  Vibration_on();  delay(200);
  Vibration_off(); delay(1000);
  Vibration_on();  delay(200);
  Vibration_off();
}


#endif//VIBRATION_H
