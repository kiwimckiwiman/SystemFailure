#include "HealthRoom.h"
using namespace std;

HealthRoom::HealthRoom(string n, string desc, Character* c) :Room(n, desc, c) { // HealthRoom is child class of Room (inheritance)
	roomName = n;
	description = desc;
	character = c;
}

int HealthRoom::Start() { // function is different from base version (polymorphism)
	if (this->getExplored()) {
		cout << "Explored!" << endl;
		system("PAUSE");
		return 2;
	}
	else {
		int random = (rand() % 3);
		switch (Encounter()) {
		case 0:
			system("CLS");
			cout << "You found spare MB lying around! Healed for " << ((random + 1) * 3) * 10 << endl;
			character->GetHP(((random + 1) * 3) * 10);
			this->isExplored();
			break;
		case 1:
			break;
		}
		system("PAUSE");
		return 2;
	}
}

int HealthRoom::Encounter() {
	while (1) {
		system("CLS");
		cout << description << "\nDo you wish to continue? [y/n]" << endl;
		string encounter;
		cin >> encounter;
		if (encounter == "y") {
			system("CLS");
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

HealthRoom::~HealthRoom() { // done

}