#ifndef AUDIO_H
#define AUDIO_H

#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>
#include "PinConfig.h"

SoftwareSerial mySerial(AUDIO_RX, AUDIO_TX); // RX, TX
DFPlayerMini_Fast audio;
#define VOLUME_LEVEL  Global_Volume

void PlayAudio(int i)
{
  audio.play(i);
  Serial.print(F("Play Track Number: "));
  Serial.println(i);
  delay(600);
  while (audio.isPlaying())
    delay(250);
}

void VolumeUp()
{
  VOLUME_LEVEL+=2;
  if(VOLUME_LEVEL>30) VOLUME_LEVEL = 30;
  if(VOLUME_LEVEL<1) VOLUME_LEVEL = 30;
  audio.volume(VOLUME_LEVEL);
  delay(500);
}
void VolumeDown()
{
  VOLUME_LEVEL-=2;
  if(VOLUME_LEVEL<1) VOLUME_LEVEL = 1;
  if(VOLUME_LEVEL>30) VOLUME_LEVEL = 1;
  audio.volume(VOLUME_LEVEL);
  delay(500);
}

void setupAudio()
{
  mySerial.begin(9600);
  audio.begin(mySerial, false);
  delay(500);
  
  VOLUME_LEVEL = 25;
  audio.volume(VOLUME_LEVEL);
  delay(500);
  
  PlayAudio(1);
  PlayAudio(2);
}

#endif //AUDIO_H
