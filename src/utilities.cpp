#include <TFT_eSPI.h>
#include <WiFi.h>
#include <time.h>
#include "global.h"

// Initialize RTC using NTP
#include <time.h>
#include <TFT_eSPI.h>
extern TFT_eSPI tft;

void initializeRTC() {
    Serial.println("🕒 Initializing RTC via NTP...");

    // Show syncing screen
   
    // Configure timezone + NTP servers
    configTzTime("MST7MDT,M3.2.0/2,M11.1.0/2", "pool.ntp.org", "time.nist.gov");

    Serial.println("⌛ Waiting for valid NTP time...");
    time_t now = time(nullptr);
    int waitCount = 0;

    while (now < 8 * 3600 * 2 && waitCount < 40) {
        delay(500);
        Serial.print(".");
        now = time(nullptr);
        waitCount++;
    }

    if (now >= 8 * 3600 * 2) {
        Serial.println("\n✅ Time synchronized.");
        struct tm timeinfo;
        localtime_r(&now, &timeinfo);
        Serial.printf("📅 Current time: %02d:%02d:%02d\n",
                      timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    } else {
        Serial.println("\n⚠️ Failed to sync time.");
       
        delay(2000);
    }

    // Clear screen after sync attempt
    tft.fillScreen(TFT_BLACK);
}




// Returns the current time as a formatted string
String getTime() {
    time_t now = time(nullptr);
    struct tm timeinfo;
    localtime_r(&now, &timeinfo);
    char buffer[25];
    strftime(buffer, sizeof(buffer), "%I:%M:%S %p", &timeinfo);  // 12-hour format with AM/PM
    return String(buffer);
}

// Returns the current date as a formatted string
String getDate() {
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        return String("??/??/??");
    }

    char buf[9]; // MM/DD/YY + null terminator
    strftime(buf, sizeof(buf), "%m/%d/%y", &timeinfo);
    return String(buf);
}

// Optional: Scan available Wi-Fi networks
void scanNetworks() {
    Serial.println("🔍 Scanning for Wi-Fi networks...");
    int n = WiFi.scanNetworks();
    if (n == 0) {
        Serial.println("❌ No networks found.");
    } else {
        Serial.printf("✅ Found %d network(s):\n", n);
        for (int i = 0; i < n; ++i) {
            Serial.printf("  [%d] %s (%ddBm) %s\n", i + 1,
                          WiFi.SSID(i).c_str(),
                          WiFi.RSSI(i),
                          (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "open" : "");
        }
    }
}

// Display text on the TFT screen using global tft
void displayText(const char* text) {
    if (!text) {
        Serial.println("⚠️ Error: Null text passed to displayText.");
        return;
    }

    Serial.println("🖥️ Displaying text on TFT...");
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.println(text);
    Serial.println("✅ Text displayed.");
}
