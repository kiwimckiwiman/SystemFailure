#pragma once
#include "Room.h"
#include "Boss.h"
#include <queue>

using namespace std;

class BossRoom : public Room { // BossRoom is child class of Room (inheritance)
private:

	Boss* enemy;
	int Encounter(queue<string>* dialogue);
	int EngageAttack(int round, queue<string>* dialogue, bool restart);

public:
	BossRoom(string name, string desc, Character* c, Boss* enemy);
	void Animate(queue<string>* dialogue);
	void DrawBoss(int i);
	int Start(queue<string>* dialogue); // function is different from base version (polymorphism)
	~BossRoom();
};
