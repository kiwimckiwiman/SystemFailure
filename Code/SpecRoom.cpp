#include "SpecRoom.h"
using namespace std;

SpecRoom::SpecRoom(string n, string desc, Character* c):Room(n, desc, c) { // SpecRoom is child class of Room (inheritance)
	roomName = n;
	description = desc;
	character = c;
}

void SpecRoom::UpgradeSpec() {
	int input;
	while (1) {
		cout << "You found a vulnerable system file!"  << endl;
		cout << "\nChoose a spec to upgrade:\n" << endl;
		character->ViewSpecs();
		cin >> input;
		switch (input) {
		case 1:
			character->UpgradeSpec(1);
			cout << "\n" << character->GetSpecName(1) << " has been upgraded!" << endl;
			goto exit;
		case 2:
			character->UpgradeSpec(2);
			cout << "\n" << character->GetSpecName(2) << " has been upgraded!" << endl;
			goto exit;
		case 3:
			character->UpgradeSpec(3);
			cout << "\n" << character->GetSpecName(3) << " has been upgraded!" << endl;
			goto exit;
		case 4:
			character->UpgradeSpec(4);
			cout << "\n" << character->GetSpecName(4) << " has been upgraded!" << endl;
			goto exit;
		default:
			system("CLS");
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input\n" << endl;
			break;
		}
	}
exit:;
	system("PAUSE");
}

int SpecRoom::Start() { // function is different from base version (polymorphism)
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

int SpecRoom::Encounter() {
	while (1) {
		system("CLS");
		cout << description << "\nDo you wish to continue? [y/n]" << endl;
		string encounter;
		cin >> encounter;
		if (encounter == "y") {
			system("CLS");
			UpgradeSpec();
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

SpecRoom::~SpecRoom() {// done

}