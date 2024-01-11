#pragma once
#include "FileDLLNode.h"

class FileDLL // DLL
{
	private:
		FileDLLNode* fTop;
		FileDLLNode* fLast;

		int fCount;

	public:
		FileDLL();

		bool isEmpty();
	
		int size();

		void append(Room* room);

		void ShowLevels();
		string GetFileName(int i);
		bool GetFileExplored(int i);
		int operator[](int aIndex);
		~FileDLL();
};