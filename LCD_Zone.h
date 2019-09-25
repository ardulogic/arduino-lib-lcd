/*
   FILE:    MotorWaypoint.h
   DATE:    09/07/15
   VERSION: 0.1
   AUTHOR:  Andrew Davies

11/03/15 version 0.1: Original version  
   
Library header for driving DC and stepper motors.

You may copy, alter and reuse this code in any way you like, but please leave
reference to HobbyComponents.com in your comments if you redistribute this code.
This software may not be used directly for the purpose of selling products that
directly compete with Hobby Components Ltd's own range of products.

THIS SOFTWARE IS PROVIDED "AS IS". HOBBY COMPONENTS MAKES NO WARRANTIES, WHETHER
EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ACCURACY OR LACK OF NEGLIGENCE.
HOBBY COMPONENTS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR ANY DAMAGES,
INCLUDING, BUT NOT LIMITED TO, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY
REASON WHATSOEVER.

 */
#ifndef LCD_Zone_h
#define LCD_Zone_h

// This makes uint8_t work, otherwise its undefined
#include "Arduino.h"
#include "Mini_SSD1306.h"
#include "EEPROM.h"

#define LCD_ZONE_STATE_EMPTY -255

class LCD_Zone {
public:
    LCD_Zone(Mini_SSD1306* d);

    // Set Zone Position & Size
    void set(byte x_coord, byte y_coord, byte width, byte height);
    bool stateChanged(int new_state_id, bool invert);
    void clear();
    
    void icon(const unsigned char* icon, bool invert);
    void text(const char* text, bool invert, int state_id);
    void pText(const char* text, bool invert);

    const char space = ' ';
    
    byte x;
    byte y;
    byte w;
    byte h;

    int state;

    // Pointer to the display
    Mini_SSD1306* display;

private:
    void _prePrint(bool invert);
    void _postPrint(byte chars);
    
};

#endif