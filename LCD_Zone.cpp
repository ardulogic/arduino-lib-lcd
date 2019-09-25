/* FILE:    SingleStepper.h
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

#include "LCD_Zone.h"
#include "EEPROM.h"

LCD_Zone::LCD_Zone(Mini_SSD1306* d) {
    // Copy display reference pointer d to display
    display = d;
}

void LCD_Zone::set(byte x_coord, byte y_coord, byte width, byte height) {
    x = x_coord;
    y = y_coord;
    w = width;
    h = height;

    state = LCD_ZONE_STATE_EMPTY;
}

bool LCD_Zone::stateChanged(int new_state_id, bool invert) {
    new_state_id *= invert ? -1 : 1;
    if (new_state_id != state) {
        state = new_state_id;
        return true;
    }

    return false;
}

void LCD_Zone::_prePrint(bool invert) {
    display->setTextSize(1);
    display->setCursor(x, y);

    if (invert) {
        display->setTextColor(BLACK, WHITE);
    } else {
        display->setTextColor(WHITE, BLACK);
    }
}

void LCD_Zone::_postPrint(byte chars) {
    // Print spaces to fill remaining zone area
    while (chars < w / 6) {
        display->print(space);
        chars++;        
    }
}

void LCD_Zone::icon(const unsigned char* icon, bool invert) {
    if (stateChanged((int) icon, invert)) {
        display->drawBitmap(x, y, icon, w, h, (invert ? BLACK : WHITE), (invert ? 1 : 0));
        Serial.println("OK");
    }
}

void LCD_Zone::text(const char* text, bool invert, int state_id) {
    if (stateChanged(state_id, invert)) {
        byte chars = sizeof (text) / sizeof (char);

        _prePrint(invert);

        display->print(text);

        _postPrint(chars);
    }
}

void LCD_Zone::pText(const char* text, bool invert) {
    if (stateChanged((int) text, invert)) {
        byte chars = strlen_P(text);

        _prePrint(invert);

        // read back a char
        char c;
        for (int pa = 0; pa < chars; pa++) {
            c = pgm_read_byte_near(text + pa);
            display->print(c);
            Serial.print(c);
        }
        
        Serial.println("OK until here");
        _postPrint(chars);
    }
}

void LCD_Zone::clear() {
    display->fillRect(x, y, w, h, BLACK);
    state = LCD_ZONE_STATE_EMPTY;
}