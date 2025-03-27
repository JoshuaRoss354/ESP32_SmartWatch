#include <Arduino.h>
#include <iostream>
#include <time.h>



// put function declarations here:
int myFunction(int, int);
void displayText(const char* text);
void initializeRTC();
String getTime();


void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("hi");

  Serial.println("Calling displayText...");
  //displayText("Hello, world! 1");
  Serial.println("displayText completed.");

  initializeRTC();

  // Print the current time
  Serial.println("Current time: " + getTime());

  int result = myFunction(2, 3);
}
void loop() {
  Serial.println("Current time: " + getTime());
  delay(1000);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}

