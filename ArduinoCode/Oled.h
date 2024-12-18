#ifndef OLED_H
#define OLED_H

#include <U8g2lib.h>
#include <Wire.h>
#include "Global.h"

#define COLOR_NAME_VARIABLE     Global_Color_Name

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setupOLED()
{
  u8g2.begin();
}
//void displayTestMessage()
//{
//  u8g2.firstPage();                           // Start the first page
//  do{
//    // Draw text on the display
//    u8g2.setFont(u8g2_font_6x10_tr);       // Set a built-in font
//    u8g2.drawStr(0, 10, "Hello, World!");     // Draw a string at x=0, y=10
//    u8g2.drawStr(0, 30, "u8g2_font_6x10_tr");   // Another string at x=0, y=30
//    u8g2.drawStr(0, 50, "Page Buffer Mode");  // Another string at x=0, y=50
//  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
//}
//void displayTestMessage2()
//{
//  u8g2.firstPage();                           // Start the first page
//  do{
//    // Draw text on the display
//    u8g2.setFont(u8g2_font_t0_11_tr );       // Set a built-in font
//    u8g2.drawStr(0, 10, "Hello, World!");     // Draw a string at x=0, y=10
//    u8g2.drawStr(0, 30, "u8g2_font_t0_11_tr");   // Another string at x=0, y=30
//    u8g2.drawStr(0, 50, "Page Buffer Mode");  // Another string at x=0, y=50
//  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
//}
//void displayTestMessage3()
//{
//  u8g2.firstPage();                           // Start the first page
//  do{
//    // Draw text on the display
//    u8g2.setFont(u8g2_font_micro_tr);       // Set a built-in font
//    u8g2.drawStr(0, 10, "Hello, World!");     // Draw a string at x=0, y=10
//    u8g2.drawStr(0, 30, "u8g2_font_micro_tr");   // Another string at x=0, y=30
//    u8g2.drawStr(0, 50, "Page Buffer Mode");  // Another string at x=0, y=50
//  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
//}
//
//void displayTestMessage4()
//{
//  u8g2.firstPage();                           // Start the first page
//  do{
//    // Draw text on the display
//    u8g2.setFont(u8g2_font_ncenB08_tr);       // Set a built-in font
//    u8g2.drawStr(0, 10, "Hello, World!");     // Draw a string at x=0, y=10
//    u8g2.drawStr(0, 30, "u8g2_font_ncenB08_tr");   // Another string at x=0, y=30
//    u8g2.drawStr(0, 50, "Page Buffer Mode");  // Another string at x=0, y=50
//  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
//}
//void displayTestMessage5()
//{
//  u8g2.firstPage();                           // Start the first page
//  do{
//    // Draw text on the display
//    u8g2.setFont(u8g2_font_helvR08_tr);       // Set a built-in font
//    u8g2.drawStr(0, 10, "Hello, World!");     // Draw a string at x=0, y=10
//    u8g2.drawStr(0, 30, "u8g2_font_helvR08_tr");   // Another string at x=0, y=30
//    u8g2.drawStr(0, 50, "Page Buffer Mode");  // Another string at x=0, y=50
//  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
//}
void displayTestMessage6()
{
  u8g2.firstPage();                           // Start the first page
  do{
    // Draw text on the display
    u8g2.setDrawColor(1);                     // Set drawing color to black
    u8g2.drawBox(0, 0, 128, 16);              // Fill the entire display with a black background
    u8g2.setDrawColor(0);                     // Set drawing color to white
    u8g2.setFont(u8g2_font_courB10_tr);       // Set a built-in font
    u8g2.drawStr(0, 12, "ColorAidSystem!");   // Draw a string at x=0, y=10
    
    u8g2.setDrawColor(1);                     // Set drawing color to black
    u8g2.setFont(u8g2_font_courB14_tr);       // Set a built-in font
    u8g2.drawStr(25, 40, COLOR_NAME_VARIABLE); // Another string at x=0, y=30
    u8g2.setFont(u8g2_font_courB08_tr);       // Set a built-in font
    u8g2.drawStr(0, 60, "Page Buffer Mode");  // Another string at x=0, y=50
  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
}
//
//void displayTestMessage7()
//{
//  u8g2.firstPage();                           // Start the first page
//  do{
//    // Draw text on the display
//    u8g2.setFont(u8g2_font_fur11_tr);       // Set a built-in font
//    u8g2.drawStr(0, 10, "Hello, World!");     // Draw a string at x=0, y=10
//    u8g2.drawStr(0, 30, "u8g2_font_fur11_tr");   // Another string at x=0, y=30
//    u8g2.drawStr(0, 50, "Page Buffer Mode");  // Another string at x=0, y=50
//  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
//}
//void displayTestMessage8()
//{
//  u8g2.firstPage();                           // Start the first page
//  do{
//    // Draw text on the display
//    u8g2.setFont(u8g2_font_osb18_tr);       // Set a built-in font
//    u8g2.drawStr(0, 10, "Hello, World!");     // Draw a string at x=0, y=10
//    u8g2.drawStr(0, 30, "u8g2_font_osb18_tr");   // Another string at x=0, y=30
//    u8g2.drawStr(0, 50, "Page Buffer Mode");  // Another string at x=0, y=50
//  }while (u8g2.nextPage());                   // Render the page and prepare for the next one
//}

void loopOLED(void) {
  
//  displayTestMessage();
//  delay(1000);
//  displayTestMessage2();
//  delay(1000);
//  displayTestMessage3();
//  delay(1000);
//  displayTestMessage4();
//  delay(1000);
//  displayTestMessage5();
//  delay(1000);
  displayTestMessage6();
//  displayTestMessage7();
//  delay(1000);
//  displayTestMessage8();
//  delay(1000);
  
}

#endif  //OLED_H
