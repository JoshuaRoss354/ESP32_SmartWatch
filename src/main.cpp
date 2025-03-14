#include <Arduino.h>
#include <iostream>

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000); // wait for a second to ensure serial communication is initialized
  Serial.println("hi");
  int result = myFunction(2, 3);
}

void loop() {
  Serial.println("Hello, world!");
  delay(1000); // wait for a second
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}