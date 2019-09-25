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
#ifndef LCD_h
#define LCD_h

#define OLED_RESET 4

// This makes uint8_t work, otherwise its undefined
#include "Arduino.h"
#include <SPI.h>
#include <Wire.h>
#include <Mini_GFX.h>
#include <Mini_SSD1306.h>
#include "LCD_Zone.h"
#include "MemoryFree.h"


#define LCD_ZONE_STATE_EMPTY -255

class LCD {
public:
    LCD(byte zone_count);

    void init();
    void clear();
    void update();

    Mini_SSD1306 display;

    /* We need an array of pointers to each dynamically allocated
     * Object (LCD_Zone) in memory. */
    LCD_Zone** zones; // ptZonePointers

    byte zone_cnt;

    // Destructor
    ~LCD();
};

#endif