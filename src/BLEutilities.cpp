#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEAdvertising.h>
#include <BLEScan.h>
#include "ble.h"

static int latestRSSI = -999;
static unsigned long lastSeen = 0;
static const char* friendName = "Friend456"; // default fallback

void initBLEProximity(const char* targetName) {
  friendName = targetName;

  BLEDevice::init("SmartMatch");  // This device’s broadcast name
  BLEAdvertising* adv = BLEDevice::getAdvertising();
  adv->start();

  Serial.printf("BLE advertising as '%s'\n", "SmartMatch");
}

void scanForFriend() {
  BLEScan* scan = BLEDevice::getScan();
  scan->setActiveScan(true);
  BLEScanResults results = scan->start(2, false);

  for (int i = 0; i < results.getCount(); ++i) {
    BLEAdvertisedDevice dev = results.getDevice(i);
    if (dev.getName() == friendName) {
      latestRSSI = dev.getRSSI();
      lastSeen = millis();
      break;
    }
  }
}

bool isFriendSeen() {
  return (millis() - lastSeen) < 5000;
}

int getFriendRSSI() {
  return latestRSSI;
}
