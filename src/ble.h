#pragma once

void initBLEProximity(const char* targetName);
void scanForFriend();
bool isFriendSeen();
int getFriendRSSI();