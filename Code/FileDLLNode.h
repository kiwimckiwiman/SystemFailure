#pragma once
#include "Room.h"

class FileDLLNode // DLL node
{
	private:
		Room* roomFile;
		FileDLLNode* fNext; // pointer to next node
		FileDLLNode* fPrevious; // pointer to previous node

	public:
		FileDLLNode();
		static FileDLLNode NIL;
		FileDLLNode(Room* file);
		void prepend(FileDLLNode& aNode);
		void append(FileDLLNode& aNode);
		void remove();

		Room* getRoom();
		string getRoomName();
		FileDLLNode& getNext();
		FileDLLNode& getPrevious();
		bool getExplored();

		~FileDLLNode();
};

