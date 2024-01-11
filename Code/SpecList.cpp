#include <iostream>
#include "SpecList.h"
using namespace std;

SpecList::SpecList() {

}

void SpecList::AddSpec(string SpecName) { // adds Spec node
	SpecNode* NewNode = new SpecNode(SpecName);
	if (fLastNode == nullptr) {
		fLastNode = NewNode;
		fTopNode = NewNode;
		fCount++;
	}
	else {
		fLastNode->appendNode(NewNode);
		fLastNode = NewNode;
		fCount++;
	}
}

void SpecList::ViewAllSpecs() { // cycles through SLL and outputs all Spec nodes
	SpecNode* cursor = fTopNode;
	for (int i = 0; i < fCount; i++) {
		cout << i + 1 << ") Spec name: " << cursor->getSpecName() << " Spec multiplier: +" << cursor->getSpecLvl() << endl;
		cursor = cursor->getNext();
	}
}

string SpecList::GetSpecName(int pos) { // cycles through SLL and outputs Spec name
	SpecNode* cursor = fTopNode;
	for (int i = 1; i < pos; i++) {
		cursor = cursor->getNext();
	}
	return cursor->getSpecName();
}


int SpecList::FindMultiplier(int pos) { // cycles through SLL and outputs Spec multiplier
	SpecNode* cursor = fTopNode;
	for (int i = 1; i < pos; i++) {
		cursor = cursor->getNext();
	}
	return cursor->getSpecLvl();
}

void SpecList::UpgradeSpec(int pos) { // cycles through SLL and upgrades Spec
	SpecNode* cursor = fTopNode;
	for (int i = 1; i < pos; i++) {
		cursor = cursor->getNext();
	}
	switch (pos) {
		case 1:
			cursor->upgradeSpec(20);
			break;
		case(2):
			cursor->upgradeSpec(10);
			break;
		case(3):
			cursor->upgradeSpec(4);
			break;
		case(4):
			cursor->upgradeSpec(10);
			break;
	}
}

SpecList::~SpecList() { // cycles through SLL and deletes all Spec
	SpecNode* cursor = fTopNode;
	SpecNode* deleteNode;
	for (int i = 0; i < fCount - 1; i++) {
		deleteNode = cursor;
		deleteNode->~SpecNode();
		cursor = cursor->getNext();
	}
	cursor->~SpecNode();
	fTopNode = nullptr;
}