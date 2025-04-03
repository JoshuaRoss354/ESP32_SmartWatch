// filepath: c:\Users\kcarj\OneDrive\Documents\PlatformIO\Projects\ESP32_SmartWatch-main\src\globals.h
#ifndef GLOBAL_H
#define GLOBAL_H

#include <TFT_eSPI.h>
#include <Arduino.h>

extern TFT_eSPI tft; // Global variable

// Declare shared functions
void initializeRTC();
String getTime();
void scanNetworks();

#endif // GLOBAL_H