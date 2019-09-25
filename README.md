# LCD

## An Arduino library for LCD SSD1306

Enables lcd zones for improved performance

### v1.0

Added examples

```c++

#include "LCD.h"

// 5 zones
LCD lcd(4);

const char P_TEXT_1[] PROGMEM = "Hi!";
const char P_TEXT_2[] PROGMEM = "Biatch!";

static const unsigned char PROGMEM P_ICON[] = {
    0x3C, 0x3C, 0xFF, 0x81, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD,
    0x81, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0xBD, 0x81, 0xFF
};
    
void setup() {
 Serial.begin(9600);
 lcd.init();

 lcd.zones[0]->set(5, 0,  20, 8);
 lcd.zones[1]->set(5, 10, 20, 8);
 lcd.zones[2]->set(5, 18, 20, 8);
 lcd.zones[3]->set(110, 0, 8, 32);
}

void loop() {
  char* text = (char *) "Fuck-eyah!";
  lcd.zones[0]->text(text, false, 1);
  lcd.zones[1]->pText(P_TEXT_1, false);  
  lcd.zones[2]->pText(P_TEXT_2, true);  
  lcd.zones[3]->icon(P_ICON, false);    
  lcd.update();  
}

```
