#pragma once
#include "Room.h"
#include "Minion.h"

using namespace std;

class EnemyRoom: public Room { // EnemyRoom is child class of Room (inheritance)
private:

	Minion* enemy;
	int Encounter();
	int EngageAttack(int round);
	void UpgradeSpec();

public:
	EnemyRoom(string name, string desc, Character* c, Minion* enemy);
	int Start(); // function is different from base version (polymorphism)
	~EnemyRoom();
};
