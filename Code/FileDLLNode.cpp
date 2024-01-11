#include "FileDLLNode.h"

FileDLLNode FileDLLNode::NIL;

FileDLLNode::FileDLLNode() {

}

FileDLLNode::FileDLLNode(Room* f){
	roomFile = f;
	fNext = &NIL;
	fPrevious = &NIL;
}

void FileDLLNode::prepend(FileDLLNode& aNode){ // adds node behind current node
	aNode.fNext = this;
	if (fPrevious != &NIL){
		aNode.fPrevious = fPrevious;
		fPrevious->fNext = &aNode;
	}
	fPrevious = &aNode;
}

void FileDLLNode::append(FileDLLNode& aNode){ // adds node in front of current node
	aNode.fPrevious = this;
	if (fNext != &NIL){
		aNode.fNext = fNext;
		fNext->fPrevious = &aNode;
	}
	fNext = &aNode;
}

void FileDLLNode::remove(){ // remove node
	if (fNext == &NIL){
		fPrevious->fNext = &NIL;
	}else if (fPrevious == &NIL){
		fNext->fPrevious = &NIL;
	}else{
		fPrevious->fNext = fNext;
		fNext->fPrevious = fPrevious;
	}

	delete this;
}

Room* FileDLLNode::getRoom(){ // get Room object
	return roomFile;
}

string FileDLLNode::getRoomName() { // get Room name
	return roomFile->getName();
}

bool FileDLLNode::getExplored() { // get Room explored status
	return roomFile->getExplored();
}

FileDLLNode& FileDLLNode::getNext(){ // get next Room node 
	return *fNext;
}

FileDLLNode& FileDLLNode::getPrevious(){ // get previous Room node
	return *fPrevious;
}

FileDLLNode::~FileDLLNode() {

}
