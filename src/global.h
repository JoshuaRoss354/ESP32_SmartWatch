// filepath: c:\Users\kcarj\OneDrive\Documents\PlatformIO\Projects\ESP32_SmartWatch-main\src\globals.h
#ifndef GLOBAL_H
#define GLOBAL_H

#include <TFT_eSPI.h>
#include <Arduino.h>
#include <vector>


extern TFT_eSPI tft; // Global display object

// Utility functions from utilities.cpp
void initializeRTC();
String getTime();
void scanNetworks();

// UI / App logic from app.cpp
String getSavedPassword(String ssid);
void drawCenteredText(const String& text, int y, int size, uint16_t color = TFT_WHITE, uint16_t bg = TFT_BLACK);
void drawMenuHeader(const String& title);
void drawMenuOption(const String& label, int y, bool selected);
void drawWelcomeScreen();
void drawWiFiMenu(const std::vector<String>& ssidList, int selectedIndex, bool forceClear = false);
void handleWiFiButtons(int& index, int maxIndex, bool& needsRedraw);
#define BTN1 3   // Up
#define BTN2 6    // Down
#define BTN3 16   // Select
#define BTN4 14 

#endif // GLOBAL_H
