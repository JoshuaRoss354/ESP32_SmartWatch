// App.cpp
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <utilities.h>
#include "global.h"
#include <WiFi.h>
#include "ble.h"
#include <SPIFFS.h>
#include <FS.h>
#include <vector>

extern TFT_eSPI tft;

String getSavedPassword(String ssid) {
    if (ssid == "Slab-o-tech") return "fatblackpeople";
    else if (ssid == "KaiPhone") return "hellokitty";
    return "";
}

void drawCenteredText(const String& text, int y, int size, uint16_t color, uint16_t bg) {
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(size);
    tft.setTextColor(color, bg);
    tft.drawString(text, tft.width() / 2, y);
}

void drawMenuHeader(const String& title) {
    tft.fillScreen(TFT_BLACK);
    drawCenteredText(title, 20, 2, TFT_WHITE, TFT_BLACK);
    tft.drawLine(0, 40, tft.width(), 40, TFT_DARKGREY);
}

void drawMenuOption(const String& label, int y, bool selected) {
    uint16_t fg = selected ? TFT_BLACK : TFT_WHITE;
    uint16_t bg = selected ? TFT_YELLOW : TFT_BLACK;
    tft.setTextDatum(ML_DATUM);
    tft.setTextSize(2);
    tft.setTextColor(fg, bg);
    tft.fillRect(0, y, tft.width(), 30, bg);
    tft.drawString(label, 10, y + 5);
}

void drawWelcomeScreen() {
    tft.fillScreen(TFT_BLACK);
    drawCenteredText("Welcome!", tft.height() / 2, 2, TFT_WHITE, TFT_BLACK);
    delay(2000);
    tft.fillScreen(TFT_BLACK);
}

void drawWiFiMenu(const std::vector<String>& ssidList, int selectedIndex, bool forceClear) {
    drawMenuHeader("Select WiFi");
    int itemsPerPage = 5;
    int start = (selectedIndex / itemsPerPage) * itemsPerPage;
    for (int i = start; i < start + itemsPerPage && i < ssidList.size(); ++i) {
        drawMenuOption(ssidList[i], 50 + ((i - start) * 30), i == selectedIndex);
    }
    Serial.printf("[DEBUG] WiFi menu shown: %d to %d\n", start, min(start + itemsPerPage, (int)ssidList.size()));
}

void handleWiFiButtons(int& index, int maxIndex, bool& needsRedraw) {
    static bool lastBtn1 = HIGH;
    static bool lastBtn2 = HIGH;
    static unsigned long lastDebounce = 0;

    bool currentBtn1 = digitalRead(BTN1);
    bool currentBtn2 = digitalRead(BTN2);

    if (millis() - lastDebounce > 150) {
        if (currentBtn1 == LOW && lastBtn1 == HIGH && index > 0) {
            index--;
            needsRedraw = true;
            lastDebounce = millis();
            Serial.printf("[DEBUG] BTN1 pressed. Index: %d\n", index);
        }
        if (currentBtn2 == LOW && lastBtn2 == HIGH && index < maxIndex) {
            index++;
            needsRedraw = true;
            lastDebounce = millis();
            Serial.printf("[DEBUG] BTN2 pressed. Index: %d\n", index);
        }
    }

    lastBtn1 = currentBtn1;
    lastBtn2 = currentBtn2;
}
