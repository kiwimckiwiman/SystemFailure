#pragma once
#include "Room.h"

using namespace std;

class SpecRoom : public Room { // SpecRoom is child class of Room (inheritance)
private:
	void UpgradeSpec();
	int Encounter();

public:
	SpecRoom(string name, string desc, Character* c);
	int Start(); // function is different from base version (polymorphism)
	~SpecRoom();
};
