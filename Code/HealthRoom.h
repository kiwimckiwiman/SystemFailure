#pragma once
#include "Room.h"

using namespace std;

class HealthRoom : public Room { // HealthRoom is child class of Room (inheritance)
private:
	int Encounter();

public:
	HealthRoom(string name, string desc, Character* c);
	int Start(); // BossRoom is child class of Room (inheritance)
	~HealthRoom();
};
