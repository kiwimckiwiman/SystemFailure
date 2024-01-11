#pragma once
#pragma once
#include <string>
#include <iostream>
#include "Skill.h"

using namespace std;

class Iterator {
private:
	Skill* fArr1D;
	int fLength;
	int fIndex;

public:
	Iterator(Skill aArray[], int aLength, int aStart = 0);
	Skill& operator*() const; // return string at index
	Iterator& operator ++(); // iterate index forwards
	Iterator operator ++(int); // iterate index forwards
	Iterator& operator --(); // iterate index backwards
	Iterator operator --(int); // iterate index backwards
	bool operator==(const Iterator& aOther)const; // equivalence operator
	bool operator!=(const Iterator& aOther)const; // inequivalence operator
	Iterator begin() const; // returns first item in array
	Iterator end() const; // returns last item in array
	int GetfIndex(); // returns index
	int GetfLength(); // returns length

	~Iterator();
};
