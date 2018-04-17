#include <LiquidCrystal_I2C.h>
#include <Wire.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16 ,2);
// อย่างลืมเปลี่ยนตรงนี้ครับ
void setup()
{
// initialize the LCD
lcd.begin();
// Turn on the blacklight and print a message.
lcd.setCursor(0, 0);
lcd.print("Hello, world!");
lcd.setCursor(0, 1);
lcd.print("Arduitronics.com");
}
void loop()
{
lcd.setCursor(0, 0);
lcd.print("Hello, world!");
lcd.setCursor(0, 1);
lcd.print("Arduitronics.com");
}
