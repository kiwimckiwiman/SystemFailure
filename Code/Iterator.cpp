#include "Iterator.h"
using namespace std;

Iterator::Iterator(Skill aArray[], int aLength, int aStart) : fArr1D(aArray),
fLength(aLength) {
	fIndex = aStart;
}

Skill& Iterator::operator*() const { // return Skill object at index
	return fArr1D[fIndex];
}

Iterator& Iterator::operator ++() { // iterate forwards
	fIndex++;
	return *this;
}

Iterator Iterator::operator ++(int) { // iterate forwards
	Iterator temp = *this;
	fIndex++;
	return temp;
}

Iterator& Iterator::operator --() { // iterate backwards
	fIndex--;
	return *this;
}

Iterator Iterator::operator --(int) { // iterate backwards
	Iterator temp = *this;
	fIndex--;
	return temp;
}

bool Iterator::operator==(const Iterator& aOther) const {
	return(fIndex == aOther.fIndex) && (fArr1D == aOther.fArr1D);
}

bool Iterator::operator!=(const Iterator& aOther) const {
	return !(*this == aOther);
}

Iterator Iterator::begin() const { // go to top of array
	return Iterator(fArr1D, fLength, -1);
}

Iterator Iterator::end() const { // go to end of array
	return Iterator(fArr1D, fLength, fLength);
}

int Iterator::GetfIndex() { // get index of current cursor
	return fIndex;
}

int Iterator::GetfLength() { // get length of array
	return fLength;
}

Iterator::~Iterator() {

}