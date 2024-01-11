#pragma once
#include "Room.h"
#include "MiniBoss.h"
#include <queue>

using namespace std;

class MiniBossRoom : public Room {
private:

	MiniBoss* enemy;
	int Encounter(queue<string>* dialogue);
	int EngageAttack(int round);
	void UpgradeSpec();

public:
	MiniBossRoom(string name, string desc, Character* c, MiniBoss* enemy);
	void Animate(queue<string>* dialogue);
	int Start(queue<string>* dialogue);
	~MiniBossRoom();
};
