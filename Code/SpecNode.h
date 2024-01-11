#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SpecNode { // SLL node
private:
	string fSpecName;
	int fSpecLvl;
	SpecNode* fNext; // pointer to next node

public:
	static SpecNode NIL;

	SpecNode();
	SpecNode(string SpecName);

	string getSpecName();
	int getSpecLvl();

	void upgradeSpec(int inc);

	void appendNode(SpecNode* NextNode);
	SpecNode* getNext();
	void removeNode();
	~SpecNode();
};