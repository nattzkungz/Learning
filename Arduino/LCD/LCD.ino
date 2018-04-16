#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// อย่างลืมเปลี่ยนตรงนี้ครับ 
void setup()
{
// initialize the LCD
lcd.begin();
// Turn on the blacklight and print a message.
lcd.backlight();
lcd.print("Hello, world!");
lcd.setCursor(0, 1);
lcd.print("Arduitronics.com");        
}
void loop()
{
// Do nothing here...
}
