#include <TFT_eSPI.h>
#include <iostream>
#include <time.h> // Required for time functions
#include "global.h"

void someFunction() {
    Serial.println("someFunction: Filling screen with black...");
    tft.fillScreen(TFT_BLACK); // Example usage of tft
}

void initializeRTC() {
    // Set the time zone (e.g., UTC+0)
    configTime(0, 0, "pool.ntp.org", "time.nist.gov"); // Use NTP servers to sync time
    Serial.println("Waiting for time synchronization...");
    while (!time(nullptr)) {
        delay(1000);
        Serial.println("Syncing time...");
    }
    Serial.println("Time synchronized.");
}

// Function to get the current time as a formatted string
String getTime() {
    time_t now = time(nullptr); // Get the current time
    struct tm timeinfo;
    localtime_r(&now, &timeinfo); // Convert to local time
    char buffer[25];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo); // Format time
    return String(buffer);
}

// Function to display text on the screen
void displayText(const char* text) {
    if (text == nullptr) {
        Serial.println("Error: Null text passed to displayText.");
        return;
    }
    Serial.println("Displaying text on TFT...");
    tft.fillScreen(TFT_BLACK); // Clear the screen
    tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color
    tft.setTextSize(2); // Set text size
    tft.setCursor(10, 10); // Set cursor position
    tft.println(text); // Display the text
    Serial.println("Text displayed.");
}