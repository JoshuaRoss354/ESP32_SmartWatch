#include <TFT_eSPI.h>
#include <iostream>
#include <time.h> // Required for time functions


TFT_eSPI tft = TFT_eSPI();



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

// void displayText(const char* text) {
//     if (text == nullptr) {
//         Serial.println("Error: Null text passed to displayText.");
//         return;
//     }
//     tft.init();
//     tft.setRotation(1);
//     tft.fillScreen(TFT_BLACK);
//     tft.drawCentreString(text, tft.width() / 2, tft.height() / 2, 2);
//     std::cout << "Displayed text: " << text << std::endl;
// }