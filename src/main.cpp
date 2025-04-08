// #include <Arduino.h>
// #include <TFT_eSPI.h>
// #include <utilities.h> 
// #include "global.h"
// #include <WiFi.h>
// #include "ble.h"

// // Create an instance of the TFT_eSPI class
// TFT_eSPI tft = TFT_eSPI(); 

// // Function declarations
// int myFunction(int, int);
// void initializeDisplay();

// void setup() {
//     Serial.begin(115200);
//     delay(1000);
//     Serial.println("Welcome"); //print hi to serial monitor

//     tft.init();         // Initialize the display
//     tft.setRotation(1);
//     tft.fillScreen(TFT_BLACK);
//     tft.setTextSize(3);
//     tft.setTextColor(TFT_WHITE, TFT_BLACK);
//     tft.setTextDatum(MC_DATUM);

//     tft.fillScreen(TFT_WHITE);
//     tft.setTextColor(TFT_BLACK, TFT_WHITE);
//     tft.setTextDatum(MC_DATUM); // Center text
//     tft.setTextSize(2);

//     // First line: centered
//     tft.drawString("Welcome!", tft.width() / 2, tft.height() / 2 - 20);

//     // Second line: just below
//     tft.drawString("Setting Up...", tft.width() / 2, tft.height() / 2 + 20);





//     const char* ssid     = "edamame";
//     const char* password = "mmHellof409";
//     Serial.println("Starting WiFi scan...");
//     int n = WiFi.scanNetworks(); //scan for networks
//     Serial.println("Scan done");

//     if (n == 0) {
//         Serial.println("No networks found.");
//     } else {
//         Serial.printf("%d networks found:\n", n);
//         for (int i = 0; i < n; ++i) {
//             Serial.printf("%d: %s (%d) %s\n", i + 1,
//                           WiFi.SSID(i).c_str(),
//                           WiFi.RSSI(i),
//                           (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "open" : "");
//             delay(10);
//         }
//     }

//     // Attempt to connect
//     Serial.printf("\nConnecting to %s...\n", ssid);
//     WiFi.begin(ssid, password);

//     tft.fillScreen(TFT_WHITE);
//     tft.setTextColor(TFT_BLACK, TFT_WHITE);
//     tft.setTextDatum(MC_DATUM);
//     tft.setTextSize(2);
    
//     // First line
//     tft.drawString("WiFi", tft.width() / 2, tft.height() / 2 - 20);
    
//     // Second line with variable
//     String wifiMsg = "Connecting to " + String(ssid);
//     tft.drawString(wifiMsg, tft.width() / 2, tft.height() / 2 + 20);

//     int attempts = 0;
//     while (WiFi.status() != WL_CONNECTED && attempts < 100) {
//         delay(1000);
//         Serial.print(".");
//         attempts++;
//     }

//     if (WiFi.status() == WL_CONNECTED) {
//         Serial.println("\nWiFi connected!");
//         Serial.print("IP Address: ");
//         Serial.println(WiFi.localIP());

//         // 🕒 Initialize RTC after Wi-Fi is connected
//         initializeRTC();
//     } else {
//         Serial.println("\n❌ WiFi connection failed.");
//     }

//     // Initialize BLE
//     initBLEProximity("Freenove");
//     // Initialize the display
//       // Middle center text alignment
// }

// void loop() {
//     static String lastTime = "";
//     String currentTime = getTime();

//     if (currentTime != lastTime) {
//         Serial.println(currentTime);
//         tft.fillScreen(TFT_BLACK); // Clear screen
//         tft.drawString(currentTime, tft.width() / 2, tft.height() / 2); // Centered time
//         lastTime = currentTime;
//     }

//     delay(1000); // Wait 1 second

//     scanForFriend();

//     if (isFriendSeen){
//         int rssi = getFriendRSSI();
//         Serial.printf("Friend seen! RSSI: %d\n", rssi);
//         tft.fillScreen(TFT_GREEN); // Change screen color to green
//         tft.drawString("Friend Seen!", tft.width() / 2, tft.height() / 2);
//         delay(10000); // Wait 10 second
//     } else {
//         Serial.println("Friend not seen.");
//         tft.fillScreen(TFT_RED); // Change screen color to red
//         tft.drawString("No Friend", tft.width() / 2, tft.height() / 2);
//     }
    
    
// }
// #include <Arduino.h>
// #include <TFT_eSPI.h>
// #include <utilities.h>
// #include "global.h"
// #include <WiFi.h>
// #include "ble.h"

// // Create an instance of the TFT_eSPI class
// TFT_eSPI tft = TFT_eSPI();

// // Function declarations
// int myFunction(int, int);
// void initializeDisplay();

// void setup() {
//     Serial.begin(115200);
//     delay(1000);
//     Serial.println("Welcome");

//     // Initialize the display
//     tft.init();
//     tft.setRotation(1);
//     tft.fillScreen(TFT_WHITE);
//     tft.setTextSize(2);
//     tft.setTextColor(TFT_BLACK, TFT_WHITE);
//     tft.setTextDatum(MC_DATUM);

//     // Welcome screen
//     tft.drawString("Welcome!", tft.width() / 2, tft.height() / 2 - 20);
//     tft.drawString("Setting up...", tft.width() / 2, tft.height() / 2 + 20);
//     delay(3000);

//     const char* ssid     = "edamame";
//     const char* password = "mmHellof409";

//     // Display: Scanning for networks
//     tft.fillScreen(TFT_WHITE);
//     tft.drawString("WiFi", tft.width() / 2, tft.height() / 2 - 40);
//     tft.drawString("Scanning", tft.width() / 2, tft.height() / 2 - 5);
//     tft.drawString("for networks...", tft.width() / 2, tft.height() / 2 + 25);

//     Serial.println("Starting WiFi scan...");
//     int n = WiFi.scanNetworks();
//     Serial.println("Scan done");

//     if (n == 0) {
//         Serial.println("No networks found.");
//     } else {
//         Serial.printf("%d networks found:\n", n);
//         for (int i = 0; i < n; ++i) {
//             Serial.printf("%d: %s (%d) %s\n", i + 1,
//                           WiFi.SSID(i).c_str(),
//                           WiFi.RSSI(i),
//                           (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "open" : "");
//             delay(10);
//         }
//     }

//     // Display: Connecting to WiFi
//     tft.fillScreen(TFT_WHITE);
//     tft.drawString("WiFi", tft.width() / 2, tft.height() / 2 - 40);
//     tft.drawString("Connecting to", tft.width() / 2, tft.height() / 2);
//     tft.drawString(String(ssid), tft.width() / 2, tft.height() / 2 + 30);

//     Serial.printf("\nConnecting to %s...\n", ssid);
//     WiFi.begin(ssid, password);

//     int attempts = 0;
//     while (WiFi.status() != WL_CONNECTED && attempts < 25) {
//         delay(1000);
//         Serial.print(".");
//         attempts++;
//     }

//     // Display connection result
//     tft.fillScreen(TFT_WHITE);
//     tft.drawString("WiFi", tft.width() / 2, tft.height() / 2 - 40);

//     if (WiFi.status() == WL_CONNECTED) {
//         Serial.println("\n✅ WiFi connected!");
//         Serial.print("IP Address: ");
//         Serial.println(WiFi.localIP());

//         tft.drawString("Connected to", tft.width() / 2, tft.height() / 2);
//         tft.drawString(String(ssid), tft.width() / 2, tft.height() / 2 + 30);
//         delay(1500);

//         initializeRTC();
//     } else {
//         Serial.println("\n❌ WiFi connection failed.");
//         tft.drawString("Connection", tft.width() / 2, tft.height() / 2);
//         tft.drawString("failed!", tft.width() / 2, tft.height() / 2 + 30);
//         delay(2000);
//     }

//     // Initialize BLE
//     initBLEProximity("Freenove");
//     // Clear entire screen before main loop begins
//     tft.fillScreen(TFT_BLACK);

// }

// void loop() {
//     static String lastTime = "";
//     String currentTime = getTime();

//     // Update only the time section (top third)
//     if (currentTime != lastTime) {
//         Serial.println(currentTime);

//         // Clear only the time area
//         tft.fillRect(0, 0, tft.width(), tft.height() / 2, TFT_BLACK);

//         tft.setTextDatum(MC_DATUM);
//         tft.setTextColor(TFT_WHITE, TFT_BLACK);
//         tft.setTextSize(3);
//         tft.drawString(currentTime, tft.width() / 2, tft.height() / 3);

//         lastTime = currentTime;
//     }

//     // Scan for friend and calculate RSSI/distance
//     scanForFriend();

//     int circleY = (tft.height() * 2) / 3;
//     int circleRadius = 30;
//     uint16_t color = TFT_RED;
//     float distance = -1;

//     if (isFriendSeen) {
//         int rssi = getFriendRSSI();
//         Serial.printf("Friend seen! RSSI: %d\n", rssi);

//         float txPower = -59;
//         float n = 2.0;
//         distance = pow(10.0, (txPower - rssi) / (10.0 * n));

//         if (distance < 1.5) {
//             color = TFT_GREEN;
//         } else if (distance < 4.0) {
//             color = TFT_YELLOW;
//         } else {
//             color = TFT_ORANGE;
//         }
//     } else {
//         Serial.println("Friend not seen.");
//     }

//     // Clear just the circle area
//     int clearSize = circleRadius + 10;
//     tft.fillRect((tft.width() / 2) - clearSize,
//                  circleY - clearSize,
//                  clearSize * 2,
//                  clearSize * 2,
//                  TFT_BLACK);

//     // Draw the filled circle
//     tft.fillCircle(tft.width() / 2, circleY, circleRadius, color);

//     // Draw distance inside the circle
//     tft.setTextDatum(MC_DATUM);
//     tft.setTextColor(TFT_BLACK, color);
//     tft.setTextSize(1);

//     if (distance >= 0) {
//         char buf[20];
//         sprintf(buf, "~%.1f m", distance);
//         tft.drawString(buf, tft.width() / 2, circleY);
//     } else {
//         tft.drawString("?", tft.width() / 2, circleY);
//     }

//     delay(1000);
// }
#include <Arduino.h>
#include <TFT_eSPI.h>
#include <utilities.h>
#include "global.h"
#include <WiFi.h>
#include "ble.h"
#include <SPIFFS.h>
#include <FS.h>

TFT_eSPI tft = TFT_eSPI();

int myFunction(int, int);
void initializeDisplay();

void displayLoadingDots(const String& message, int cycles = 2) {
    tft.fillScreen(TFT_WHITE);
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(2);

    for (int i = 0; i < cycles; ++i) {
        for (int d = 0; d < 4; ++d) {
            String dots = "";
            for (int j = 0; j < d; ++j) dots += ".";
            tft.drawString(message + dots, tft.width() / 2, tft.height() / 2);
            delay(500);
        }
    }
}

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("Welcome");

    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_WHITE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
    tft.setTextDatum(MC_DATUM);

    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS Mount Failed");
    }

    displayLoadingDots("Welcome", 1);
    displayLoadingDots("Setting up", 1);

    const char* ssid     = "edamame";
    const char* password = "mmHellof409";

    displayLoadingDots("Scanning WiFi", 1);

    Serial.println("Starting WiFi scan...");
    int n = WiFi.scanNetworks();
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

    displayLoadingDots("Connecting WiFi", 2);
    Serial.printf("\nConnecting to %s...\n", ssid);
    WiFi.begin(ssid, password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 25) {
        delay(1000);
        Serial.print(".");
        attempts++;
    }

    tft.fillScreen(TFT_WHITE);
    tft.drawString("WiFi", tft.width() / 2, tft.height() / 2 - 40);

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n✅ WiFi connected!");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());

        tft.drawString("Connected to", tft.width() / 2, tft.height() / 2);
        tft.drawString(String(ssid), tft.width() / 2, tft.height() / 2 + 30);
        delay(1500);

        tft.fillScreen(TFT_BLACK);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setTextSize(2);
        tft.setTextDatum(MC_DATUM);
        tft.drawString("Syncing Time", tft.width() / 2, tft.height() / 2 - 10);

        initializeRTC();
    } else {
        Serial.println("\n❌ WiFi connection failed.");
        tft.drawString("Connection", tft.width() / 2, tft.height() / 2);
        tft.drawString("failed!", tft.width() / 2, tft.height() / 2 + 30);
        delay(2000);
    }

    initBLEProximity("Freenove");
    tft.fillScreen(TFT_BLACK);
}

void loop() {
    static String lastTime = "";
    String currentTime = getTime().substring(0, 5);  // Extract only HH:MM
    String currentDate = getDate();

    if (currentTime != lastTime) {
        Serial.println(currentTime);

        tft.fillRect(0, 0, tft.width(), 70, TFT_BLACK);

        tft.setTextDatum(TC_DATUM);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setTextSize(4);
        tft.drawString(currentTime, tft.width() / 2, 5);

        tft.setTextDatum(TC_DATUM);
        tft.setTextSize(3);
        tft.setTextColor(TFT_YELLOW, TFT_BLACK);
        tft.drawString(currentDate, tft.width() / 2, 45);

        lastTime = currentTime;
    }

    scanForFriend();

    int rectY = (tft.height() * 2) / 3 - 25;
    int rectH = 100;
    int rectW = 200;
    int rectX = (tft.width() - rectW) / 2;
    uint16_t color = TFT_RED;
    float distance = -1;
    int rssi = -100;

    if (isFriendSeen) {
        rssi = getFriendRSSI();
        Serial.printf("Friend seen! RSSI: %d\n", rssi);

        float txPower = -59;
        float n = 2.0;
        distance = pow(10.0, (txPower - rssi) / (10.0 * n));
        if (distance < 1.5) {
            color = TFT_GREEN;
        } else if (distance < 4.0) {
            color = TFT_YELLOW;
        } else {
            color = TFT_ORANGE;
        }
    } else {
        Serial.println("Friend not seen.");
    }

    tft.fillRect(rectX - 5, rectY - 5, rectW + 10, rectH + 10, TFT_BLACK);
    tft.fillRect(rectX, rectY, rectW, rectH, color);
    tft.drawRect(rectX, rectY, rectW, rectH, TFT_WHITE);

    tft.setTextDatum(TL_DATUM);
    tft.setTextColor(TFT_BLACK);
    tft.setTextSize(2);

    if (distance >= 0) {
        char distBuf[20];
        sprintf(distBuf, "~%.1f ft", distance * 3.28084);
        tft.drawString("Distance:", rectX + 10, rectY + 10);
        tft.drawString(distBuf, rectX + 120, rectY + 10);

        char rssiBuf[20];
        sprintf(rssiBuf, "%d dBm", rssi);
        tft.drawString("Signal:", rectX + 10, rectY + 50);
        tft.drawString(rssiBuf, rectX + 120, rectY + 50);
    } else {
        tft.drawString("No device found", rectX + 10, rectY + 30);
    }

    delay(1000);
}
