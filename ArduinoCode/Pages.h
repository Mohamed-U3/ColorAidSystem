#ifndef PAGES_H
#define PAGES_H

/*
 * ***********************************************************
               Includes
 * ***********************************************************
*/
#include "PinConfig.h"
#include "Buttons.h"
#include "Global.h"

/*
 * ***********************************************************
             variables
 * ***********************************************************
*/
unsigned char current_page      = 1;
unsigned char current_line      = 1;
bool          button_last_state = 0;
bool          increaseVal       = 0;
bool          decreaseVal       = 0;

/*
* ***********************************************************
              Defines
* ***********************************************************
*/
#define COLOR_NAME_VARIABLE Global_Color_Name
/*
 * ***********************************************************
               Functions body
 * ***********************************************************
*/


void mainpage()
{
  display.clearDisplay();
  display.setTextSize(1);               // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print((current_line == 1) ? F("|   > ") : F("|  "));  display.print(F("Color detected   >")); display.println();
  display.print((current_line == 2) ? F(">") : F(" ")); display.print(F("Color: "));     display.println(); display.println();  display.setTextSize(2); display.println(COLOR_NAME_VARIABLE);
  display.display();                    // Show initial text

  switch (current_line)
  {
    case 1: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 2: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 3: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 4: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 5: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 6: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 7: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    case 8: if (increaseVal == 1){ current_page++; increaseVal = 0;} if (decreaseVal == 1){ current_page--; decreaseVal = 0;}   break;
    default: ;
  }
}

//Task of Loading Pages on OLED.
void loopPages()
{
  switch (pressedButton())
  {
    case DOWN_BUTTON_PIN:   if (button_last_state == 0){  current_line = (current_line + 1 > 8) ? 1 : current_line + 1; button_last_state = 1;  } break;
    case UP_BUTTON_PIN:     if (button_last_state == 0){  current_line = (current_line - 1 < 1) ? 8 : current_line - 1; button_last_state = 1;  } break;
    case RIGHT_BUTTON_PIN:  if (button_last_state == 0){  increaseVal  = 1;                                             button_last_state = 1;  } break;
    case LEFT_BUTTON_PIN:   if (button_last_state == 0){  decreaseVal  = 1;                                             button_last_state = 1;  } break;
    default:  button_last_state = 0;
  }

  switch (current_page)
  {
    case 1:   mainpage();  break;
    case 2:   mainpage();  break;
    case 3:   mainpage();  break;
    default:  mainpage();
  }

  if(current_page < 0 || current_page > 4)
  {
    current_page = 1;
  }
}

#endif  //PAGES_H
