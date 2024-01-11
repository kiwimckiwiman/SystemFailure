#pragma once
#include "FileDLL.h"
#include "MiniBossRoom.h"
#include <queue>

class Folder { // Folder class
private:
	int roomsCleared;
	FileDLL* files;
	string folderName;
	Character* character;
	MiniBossRoom* mbRoom;
	bool lost;
	bool folderCleared;

public:
	Folder();
	Folder(FileDLL* files, string folderName, Character* character, MiniBossRoom* miniBossRoom);
	bool Start(queue<string>* dialogue);
	~Folder();
};