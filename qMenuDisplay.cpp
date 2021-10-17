#include "qMenuDisplay.h"

qMenuDisplay::qMenuDisplay()
{
}

qMenuDisplay::qMenuDisplay(Adafruit_SSD1306 *disp)
{
  _disp = disp;
}

void qMenuDisplay::Begin()
{
  _disp->begin(SSD1306_SWITCHCAPVCC, 0x3C);
  _disp->setTextColor(WHITE);
  _disp->setTextSize(1);
}

void qMenuDisplay::Start()
{
  _disp->clearDisplay();
}

void qMenuDisplay::Finish()
{
  _disp->display();
}

void qMenuDisplay::Title(const char text[])
{
  _disp->setCursor(64 - strlen(text) * 9 / 2, 11 - textHeight / 2);
  _disp->print(text);
  _disp->drawFastHLine(0, 14, 128, WHITE);
  //_disp->display();
}

void qMenuDisplay::Item(int index, const char text[])
{
  _disp->setCursor(5, (index * 14) + 32 - textHeight / 2);
  _disp->print(text);
  //_disp->display();
}

void qMenuDisplay::Highlight(int index)
{
  for (int i = 0; i < 13; i++)
    _disp->drawFastHLine(4, (index * 14) + 20 + i, 120, INVERSE);
  //_disp->display();
}

void qMenuDisplay::MessageBox(const char text[])
{
  int textWidth = strlen(text) * 9;
  int x = 64 - (textWidth / 2);
  int y = 32;
  for (int i = 0; i < 21 + 3; i++)
    _disp->drawFastHLine(x - 5, y - 12 + i, textWidth + 9, BLACK);
  _disp->drawFastHLine(x - 3, y - 10, textWidth + 5, WHITE);
  _disp->drawFastHLine(x - 3, y - 10 + 17 + 3, textWidth + 5, WHITE);
  _disp->drawFastVLine(x - 3, y - 10, 17 + 3, WHITE);
  _disp->drawFastVLine(x - 3 + textWidth + 5, y - 10, 17 + 3, WHITE);

  _disp->setCursor(x, y + 5 - textHeight / 2);
  _disp->print(text);
  //_disp->display();
}
