#include "BufferRoom.h"
using namespace std;

BufferRoom::BufferRoom(string n, string desc, Character* c) :Room(n, desc, c) { // BufferRoom is child class of Room (inheritance)
	roomName = n;
	description = desc;
	character = c;
}

void BufferRoom::GetBuffer() {
	int buffer;

	buffer = ((rand() % 4) + 1) * 5;
	cout << "You found spare RAM that can be used to make a buffer!" << endl;
	cout << "\nAdded " << buffer << " MB to your buffer!" << endl;
		
	Buffer b;
	b.bHealth = buffer;
	b.name = "RAM Buffer";

	character->AddBuffer(b);
	system("PAUSE");
}

int BufferRoom::Start() { // function is different from base version (polymorphism)
	if (this->getExplored()) {
		cout << "Explored!" << endl;
		system("PAUSE");
		return 2;
	}
	else {
		switch (Encounter()) {
		case 0:
			this->isExplored();
			break;
		case 1:
			break;
		}
		return 2;
	}
}

int BufferRoom::Encounter() {
	while (1) {
		system("CLS");
		cout << description << "\nDo you wish to continue? [y/n]" << endl;
		string encounter;
		cin >> encounter;
		if (encounter == "y") {
			system("CLS");
			GetBuffer();
			return 0;
			break;
		}
		else if (encounter == "n") {
			return 1;
			break;
		}
		else {
			system("CLS");
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input\n" << endl;
			system("PAUSE");
		}
	}
}

BufferRoom::~BufferRoom() {// done

}