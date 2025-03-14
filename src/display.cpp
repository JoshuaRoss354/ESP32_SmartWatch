
#include <TFT_eSPI.h>
#include <iostream>


TFT_eSPI tft = TFT_eSPI();

void displayText(){
    //bool time = 1.00;

    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.drawCentreString("hellow", 30,30,2);
    std :: cout << " why\n";
    




}
