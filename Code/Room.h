#pragma once
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class Room { // Parent class
protected:
	Character* character;
	string roomName;
	string description;
	bool explored;

public:
	Room();
	Room(string name, string desc, Character* c);
	string getName();
	virtual int Start(); // virtual function
	virtual ~Room(); // virtual function
	bool getExplored();
	void isExplored();
};