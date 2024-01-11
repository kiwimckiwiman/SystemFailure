#include "SpecNode.h"
#include <iostream>
using namespace std;

SpecNode SpecNode::NIL; //NIL

SpecNode::SpecNode() {
	fSpecName = "";
	fSpecLvl = 0;
	SpecNode* fNext = &NIL;
}

SpecNode::SpecNode(string SpecName) {
	fSpecName = SpecName;
	fSpecLvl = 0;
	SpecNode* fNext = &NIL;
}

string SpecNode::getSpecName() {
	return fSpecName;
}

int SpecNode::getSpecLvl() {
	return fSpecLvl;
}


void SpecNode::upgradeSpec(int inc) {
	fSpecLvl = fSpecLvl + inc;
}


void SpecNode::appendNode(SpecNode* NewNode) { // adds node in front of current node
	if (NewNode == nullptr) {
		fNext = &NIL;
	}
	else {
		SpecNode* temp = fNext;
		fNext = NewNode;
		NewNode->fNext = temp;
	}

}

SpecNode* SpecNode::getNext() { // gets next node
	return fNext;
}

void SpecNode::removeNode() { // deletes current node
	delete this;
}

SpecNode::~SpecNode() {

}