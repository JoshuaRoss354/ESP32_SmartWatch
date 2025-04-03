#include <Arduino.h>
#include <TFT_eSPI.h>
#include <utilities.h> 
#include "global.h"
#include <WiFi.h>

// Create an instance of the TFT_eSPI class
TFT_eSPI tft = TFT_eSPI(); 

// Function declarations
int myFunction(int, int);
void initializeDisplay();

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("hi");

    const char* ssid     = "edamame-IoT";
    const char* password = "zanylotus139";

    Serial.println("Starting WiFi scan...");

    int n = WiFi.scanNetworks(); //scan for networks
    Serial.println("Scan done");

    if (n == 0) {
        Serial.println("No networks found.");
    } else {
        Serial.printf("%d networks found:\n", n);
        for (int i = 0; i < n; ++i) {
            Serial.printf("%d: %s (%d) %s\n", i + 1,
                          WiFi.SSID(i).c_str(),
                          WiFi.RSSI(i),
                          (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "open" : "");
            delay(10);
        }
    }

    // Attempt to connect
    Serial.printf("\nConnecting to %s...\n", ssid);
    WiFi.begin(ssid, password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 50) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());

        // 🕒 Initialize RTC after Wi-Fi is connected
        initializeRTC();
    } else {
        Serial.println("\n❌ WiFi connection failed.");
    }

    // Initialize the display
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextDatum(MC_DATUM);  // Middle center text alignment
}

void loop() {
    static String lastTime = "";
    String currentTime = getTime();

    if (currentTime != lastTime) {
        Serial.println(currentTime);
        tft.fillScreen(TFT_BLACK); // Clear screen
        tft.drawString(currentTime, tft.width() / 2, tft.height() / 2); // Centered time
        lastTime = currentTime;
    }

    delay(1000); // Wait 1 second

}