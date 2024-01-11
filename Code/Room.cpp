#include "Room.h"
using namespace std;

Room::Room() {

}

Room::Room(string n, string desc, Character* c) { // Parent class
	roomName = n;
	description = desc;
	character = c;
	explored = false;
}

string Room::getName() {
	return roomName;
}

int Room::Start() {
	return 0;
}

bool Room::getExplored() {
	return explored;
}

void Room::isExplored() {
	explored = true;
}

Room::~Room() { // done

}