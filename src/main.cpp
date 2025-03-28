// #include <Arduino.h>
// #include <iostream>
// #include <time.h>



// // put function declarations here:
// int myFunction(int, int);
// void displayText(const char* text);
// void initializeRTC();
// String getTime();


// void setup() {
//   Serial.begin(115200);
//   delay(1000);
//   Serial.println("hi");

//   Serial.println("Calling displayText...");
//   //displayText("Hello, world! 1");
//   Serial.println("displayText completed.");

//   initializeRTC();

//   // Print the current time
//   Serial.println("Current time: " + getTime());

//   int result = myFunction(2, 3);
// }
// void loop() {
//   Serial.println("Current time: " + getTime());
//   delay(1000);
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }

#include <Arduino.h>
#include <TFT_eSPI.h> // Include the TFT_eSPI library

TFT_eSPI tft = TFT_eSPI(); // Define the tft object here

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting setup...");

  // Initialize the TFT screen
  Serial.println("Initializing TFT...");
  tft.init();
  tft.setRotation(1); // Set screen orientation (0-3)
  tft.fillScreen(TFT_BLACK); // Clear the screen with black color

  // Display some text
  Serial.println("Displaying text...");
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color (foreground, background)
  tft.setTextSize(2); // Set text size
  tft.setCursor(10, 10); // Set cursor position (x, y)
  tft.println("Hello, Smartwatch!");

  // Draw a rectangle
  Serial.println("Drawing rectangle...");
  tft.drawRect(50, 50, 100, 50, TFT_RED); // (x, y, width, height, color)

  // Draw a filled circle
  Serial.println("Drawing circle...");
  tft.fillCircle(120, 120, 30, TFT_BLUE); // (x, y, radius, color)

  Serial.println("Setup completed.");
}

void loop() {
  // Add more screen updates here if needed
}