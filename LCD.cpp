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

#include "LCD.h"

LCD::LCD(byte zone_count) {
    zone_cnt = zone_count;

    Mini_SSD1306 display(4);
}

void LCD::init() {
    // We allocate memory for storing 
    // array of pointers to LCD_zone objects
    zones = new LCD_Zone*[10];
        
    // We assign the objects for each pointer
    for (int i = 0; i < zone_cnt; i++) {                
        zones[i] = new LCD_Zone(&display);
    }

    // initialize with the I2C addr 0x3D (for the 128x64)    
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    update();
    delay(1000);

    display.clearDisplay();
    update();    
}

void LCD::clear() {
    display.clearDisplay();
}

void LCD::update() {
    display.display();
}

LCD::~LCD() {
    for (int i = 0; i < zone_cnt; i++, delete zones[i]); //ptZonePointers[i]);

    delete[] * zones; //ptZonePointers;
};