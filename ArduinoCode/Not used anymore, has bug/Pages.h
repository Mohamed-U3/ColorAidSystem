#ifndef PAGES_H
#define PAGES_H

/*
 * ***********************************************************
               Includes
 * ***********************************************************
*/
#include "PinConfig.h"
#include "Buttons.h"
#include "Oled.h"
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
#define MAX_LINES_NUM                 4
#define MAX_PAGES_NUM                 4
#define COLOR_NAME_VARIABLE           Global_Color_Name
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
  display.print((current_line == 1) ? F("| >") : F("|  "));  display.print(F("Color detected   |")); display.println();
  display.print((current_line == 2) ? F(">") : F(" ")); display.print(F("Color: ")); display.println(); display.println(); display.setTextSize(2); display.println(COLOR_NAME_VARIABLE);
  display.setTextSize(1); display.println();
  display.print((current_line == 3) ? F(">") : F(" ")); display.print(F("Current Line: "));  display.println(current_line);
  display.print((current_line == 4) ? F(">") : F(" ")); display.print(F("Current Page: "));  display.println(current_page);
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
    case DOWN_BUTTON_PIN:   if (button_last_state == 0){  current_line = (current_line + 1 > MAX_LINES_NUM) ? 1 : current_line + 1; button_last_state = 1;  } break;
    case UP_BUTTON_PIN:     if (button_last_state == 0){  current_line = (current_line - 1 < 1) ? MAX_LINES_NUM : current_line - 1; button_last_state = 1;  } break;
    case RIGHT_BUTTON_PIN:  if (button_last_state == 0){  increaseVal  = 1;                                                         button_last_state = 1;  } break;
    case LEFT_BUTTON_PIN:   if (button_last_state == 0){  decreaseVal  = 1;                                                         button_last_state = 1;  } break;
    default:  button_last_state = 0;
  }

  switch (current_page)
  {
    case 1:   mainpage();  break;
    case 2:   mainpage();  break;
    case 3:   mainpage();  break;
    default:  mainpage();
  }

  if(current_page < 1)
  {
    current_page = MAX_PAGES_NUM;
  }
  else if(current_page > MAX_PAGES_NUM)
  {
    current_page = 1;
  }
  else
  {  }
}

#endif  //PAGES_H
