#ifndef BOTTONS_H
#define BOTTONS_H

/*
 * ***********************************************************
 *             Includes
 * ***********************************************************
 */
#include "PinConfig.h"

/*
 * ***********************************************************
 *           variables
 * ***********************************************************
 */

/*
* ***********************************************************
*             Defines
* ***********************************************************
*/

/*
 * ***********************************************************
 *             Functions body
 * ***********************************************************
 */

void setupbuttons()
{
  pinMode(DOWN_BUTTON_PIN ,INPUT_PULLUP);
  pinMode(LEFT_BUTTON_PIN ,INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN,INPUT_PULLUP);
  pinMode(UP_BUTTON_PIN   ,INPUT_PULLUP);
}

char pressedButton()
{
  if     (digitalRead(DOWN_BUTTON_PIN)  == LOW)  return DOWN_BUTTON_PIN;
  else if(digitalRead(LEFT_BUTTON_PIN)  == LOW)  return LEFT_BUTTON_PIN;
  else if(digitalRead(RIGHT_BUTTON_PIN) == LOW)  return RIGHT_BUTTON_PIN;
  else if(digitalRead(UP_BUTTON_PIN)    == LOW)  return UP_BUTTON_PIN;
  else return -1;
}

 
#endif  //BOTTONS_H
