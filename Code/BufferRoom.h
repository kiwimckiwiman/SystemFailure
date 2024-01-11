#pragma once
#include "Room.h"

using namespace std;

class BufferRoom : public Room { // BufferRoom is child class of Room (inheritance)
private:
	void GetBuffer();
	int Encounter();

public:
	BufferRoom(string name, string desc, Character* c);
	int Start(); // function is different from base version (polymorphism)
	~BufferRoom();
};
