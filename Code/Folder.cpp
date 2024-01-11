#include "Folder.h"
#include <windows.h>
#include <lmcons.h>

Folder::Folder() {

}

Folder::Folder(FileDLL* f, string fName, Character* c, MiniBossRoom* mbr) {
	files = f;
	roomsCleared = 0;
	folderName = fName;
	character = c;
	mbRoom = mbr;
	lost = false;
	folderCleared = false;
}

bool Folder::Start(queue<string>* dialogue) {
	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;

	GetComputerName((TCHAR*)username, &username_len);
	
	wstring uName1 = username;
	string uNameString(uName1.begin(), uName1.end());

	string input;
	int roomsCleared = 0;
	while (1) {
		system("CLS");
		cout << "Current Path: C:\\" << uNameString << "\\" << folderName << "\\>\n\n" << endl;
		cout << "Type 'cd\\' to exit folder or 'map' to view the system files\n" << endl;
		files->ShowLevels();
		cin >> input;
		if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7") {
			system("CLS");
			cout << "Current Path: C:\\" << uNameString << "\\" << folderName << "\\";
			if ((*files).GetFileExplored(stoi(input))) {
				cout << (*files).GetFileName(stoi(input));
			}
			else {
				cout << "?????????????";
			}
			cout << ">\n" << endl;
			int room = (*files)[stoi(input)];
			if (room == 1) {
				roomsCleared++;
			}
			else if (room == 0) {
				return false;
			}
			else {
				continue;
			}
		}
		else if (input == "map") {
			system("CLS");
			if (folderName == "My Documents") {
				cout << "System Folders:\n\n" << uNameString << "\n  |\n  |__ My Videos\n  |\n  |__ My Music\n  |\n  |__ My Images\n  |\n  |__ My Documents <-- You are here\n" << endl;
			}
			else if (folderName == "My Images") {
				cout << "System Folders:\n\n" << uNameString << "\n  |\n  |__ My Videos\n  |\n  |__ My Music\n  |\n  |__ My Images <-- You are here\n  |\n  |__ My Documents\n" << endl;
			}
			else if (folderName == "My Music") {
				cout << "System Folders:\n\n" << uNameString << "\n  |\n  |__ My Videos\n  |\n  |__ My Music <-- You are here\n  |\n  |__ My Images\n  |\n  |__ My Documents\n" << endl;
			}
			else if (folderName == "My Videos") {
				cout << "System Folders:\n\n" << uNameString << "\n  |\n  |__ My Videos <-- You are here\n  |\n  |__ My Music\n  |\n  |__ My Images\n  |\n  |__ My Documents\n" << endl;
			}
			system("PAUSE");
		}
		else if (input == "cd\\") {
			system("CLS");
			if (roomsCleared == 3) {
				int room = mbRoom->Start(dialogue);
				if (room == 1) {
					return true;
				}
				else if (room == 0) {
					return false;
				}
			}
			else {
				cout << "You have not defeated all of the files\n" << endl;
				system("PAUSE");
			}
		}
		else {
			system("CLS");
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input\n" << endl;
			system("PAUSE");
		}
	}
}

Folder::~Folder() {

}