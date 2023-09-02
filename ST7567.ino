//#include <Arduino.h>
#include "ST7567S.h"
#include "Console.h"

Console<ST7567S<0x3F>> lcd;

void setup() {
  Serial.begin(115200);
  Serial.println();

  lcd.init();
  if (! lcd.begin()) {
    Serial.println(F("ST7567S display not found!"));
    Serial.flush();
    //ESP.deepSleep(0);
  }
//  lcd.flip(true);
  lcd.drawHLine(0, 0, lcd.width(), 1);
  lcd.drawHLine(0, lcd.height() - 1, lcd.width(), 1);
  lcd.drawVLine(0, 0, lcd.height(), 1);
  lcd.drawVLine(lcd.width() - 1, 0, lcd.height(), 1);
  delay(1000);
  lcd.clear();
  lcd.println(F("*********************"));
  lcd.println(F("*   Hello, World!   *"));
  lcd.println(F("* Здравствуй, Мир!  *"));
  lcd.println(F("*********************"));
  for (uint8_t i = 0; i < 4; ++i) {
    delay(1000);
    lcd.inverse((i & 0x01) == 0);
  }
  for (uint8_t i = 0; i < 8; ++i) {
    lcd.println();
    delay(250);
  }
  lcd.println(F("Z   Z  V   V  OOOO  Z"));
  lcd.println(F("ZZ ZZ  V  VV  O   O Z"));
  lcd.println(F("Z Z Z  V V V  OOOO  Z"));
  lcd.println(F("Z   Z  VV  V  O      "));
  lcd.println(F("Z   Z  V   V  O     Z"));
  lcd.println();
  lcd.println();
  for (uint8_t i = 0; i < 4; ++i) {
    delay(1000);
    lcd.inverse((i & 0x01) == 0);
  }
  lcd.print(F("\fКакой-то там непонятный процесс "));
  for (uint8_t i = 0; i < 20; ++i) {
    static const char PROGRESS[] PROGMEM = { '-', '\\', '|', '/' };

    lcd.print((char)pgm_read_byte(&PROGRESS[i % 4]));
    lcd.print('\b');
    delay(100);
  }
  lcd.println(F("OK"));
  lcd.println(F("А теперь спать..."));
  for (int8_t contrast = 29; contrast >= 0; contrast -= 2) {
    delay(100);
    lcd.contrast(contrast);
  }
  lcd.powerSave(true);
  //ESP.deepSleep(0);
}

void loop() {}

