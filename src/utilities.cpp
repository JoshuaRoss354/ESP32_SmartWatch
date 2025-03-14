#include <TFT_eSPI.h>
#include <iostream>


TFT_eSPI tft = TFT_eSPI();


void displayText(const char* text) {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.drawCentreString(text, tft.width() / 2, tft.height() / 2, 2);
    std::cout << "Displayed text: " << text << std::endl;
}
