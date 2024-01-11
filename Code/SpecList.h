#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "SpecNode.h"
using namespace std;

class SpecList { // SLL
private:
	SpecNode* fLastNode = nullptr; // last node
	SpecNode* fTopNode = nullptr; // first node
	int fCount = 0;

public:
	SpecList();
	void AddSpec(string SpecName);
	int FindMultiplier(int pos);
	void ViewAllSpecs();
	string GetSpecName(int pos);
	void UpgradeSpec(int pos);
	~SpecList();
};