#include <SPI.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#ifndef qMenuDisplay_h
#define qMenuDisplay_h

class qMenuDisplay
{
public:
  qMenuDisplay(Adafruit_SSD1306 *disp);
  qMenuDisplay();
  void Begin();
  void Start();
  void Finish();
  void Title(const char text[]);
  void Item(int index, const char text[]);
  void Highlight(int index);
  void MessageBox(const char text[]);

private:
  Adafruit_SSD1306 *_disp;
  int textHeight = 14;
  //    char tempBuffer[32];
};

#endif
