#pragma once
#include "EnemyRoom.h"
#include "Minion.h"
#include "SpecRoom.h"
#include "HealthRoom.h"
#include "BufferRoom.h"
#include "MiniBoss.h"
#include "MiniBossRoom.h"
#include "Folder.h"

enum EnemyType {
	TXT, PDF, MS, GIF, PNG, JPG, OGG, WAV, MP3, MOV, AVI, MP4
};

class Factory { // factory design pattern
private:
	Character* character;
public:
	Factory(Character* character);
	Minion* CreateEnemy(EnemyType type); // function to return Minions
	EnemyRoom* CreateEnemyRoom(EnemyType type); // function to return EnemyRoom
	Room* GenerateRoom(); // function to return Room
	Folder* CreateFolder(int i); // function to return Folder
	MiniBoss* CreateMiniBoss(int i); // function to return MiniBoss
	MiniBossRoom* CreateMiniBossRoom(int i); // function to return MiniBossRoom
	~Factory();
};

