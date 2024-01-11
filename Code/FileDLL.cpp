#include "FileDLL.h"

FileDLL::FileDLL(){
	fTop = nullptr;
	fLast = nullptr;
	fCount = 0;
}

bool FileDLL::isEmpty(){
	if (fCount == 0)
		return true;
	else
		return false;
}

int FileDLL::size(){ // get size of DLL
	return fCount;
}


void FileDLL::append(Room* room){ // append Room node to DLL
	FileDLLNode* NewNode = new FileDLLNode(room);

	if (isEmpty()){
		fTop = NewNode;
		fLast = NewNode;
	}else{
		FileDLLNode* Temp = fLast;
		fLast = NewNode;
		fLast->prepend(*Temp);
	}

	fCount++;
}

void FileDLL::ShowLevels() { // cycle through DLL and display Room names
	cout << "Files available:\n" << endl;
	int i = 1;
	FileDLLNode* Temp = fTop;
	while (Temp != &(FileDLLNode::NIL)) {
		cout << i << ") ";
		if (Temp->getRoom()->getExplored()) {
			cout << Temp->getRoom()->getName() << endl;
		}
		else {
			cout << "????????" << endl;
		}
		Temp = &Temp->getNext();
		i++;
	}
	cout << "\nChoose a file number:" << endl;
}

int FileDLL::operator[](int aIndex){ // uses the [] operator to access DLL as array
	FileDLLNode* Temp = fTop;
	while (aIndex != 1){
		aIndex--;
		Temp = &Temp->getNext();
	}
	return Temp->getRoom()->Start();
}

string FileDLL::GetFileName(int aIndex) { // cycle through DLL to get Room name
	FileDLLNode* Temp = fTop;
	while (aIndex != 1) {
		aIndex--;
		Temp = &Temp->getNext();
	}
	return Temp->getRoomName();
}

bool FileDLL::GetFileExplored(int aIndex) { // cycle through DLL to get Room explored status
	FileDLLNode* Temp = fTop;
	while (aIndex != 1) {
		aIndex--;
		Temp = &Temp->getNext();
	}
	return Temp->getExplored();
}

FileDLL::~FileDLL() { // cycle through DLL to delete each node
	while (fTop != &(FileDLLNode::NIL)) {
		FileDLLNode* Temp = fTop;
		fTop = &fTop->getNext();
		Temp->remove();
		fCount--;
	}
}