#ifndef AUDIO_H
#define AUDIO_H

#include <DFPlayerMini_Fast.h>
#include <SoftwareSerial.h>
#include "PinConfig.h"

SoftwareSerial mySerial(AUDIO_RX, AUDIO_TX); // RX, TX
DFPlayerMini_Fast audio;

void PlayAudio(int i)
{
  audio.play(i);
  Serial.print(F("Play Track Number: "));
  Serial.println(i);
  delay(600);
  while (audio.isPlaying())
    delay(250);
}

void setupAudio()
{
  mySerial.begin(9600);
  audio.begin(mySerial, false);
  delay(500);

  audio.volume(30);
  delay(500);
  
  PlayAudio(1);
  PlayAudio(2);
}

#endif //AUDIO_H
