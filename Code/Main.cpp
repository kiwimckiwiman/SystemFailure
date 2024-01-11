#define WINVER 0x0500
#include <iostream>
#include <fstream>
#include <string>
#include "Factory.h"
#include "Character.h"
#include <windows.h>
#include <queue>
#include <lmcons.h>
#include "Boss.h"
#include "BossRoom.h"

using namespace std;

int main() {
	// initialise seed for RNG
	srand((unsigned int)time(NULL)); 

	// get computer username
	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;

	GetComputerName((TCHAR*)username, &username_len);
	wstring uName1 = username;
	string uNameString(uName1.begin(), uName1.end());

	// set window size
	HWND wh = GetConsoleWindow();
	MoveWindow(wh, 300, 20, 755, 800, TRUE);

	// create skill nodes
	Skill ReWrite("ReWrite", "ReWrite lines of code withing the file to generate errors: Light attack", 25, 0);
	Skill Corrupt("Corrupt", "Inject malicious codes to damage the file: Medium attack", 60, 2);
	Skill Crash("Crash", "Completely wipe large amounts of data within the file: Heavy attack", 85, 4);

	// add to array (accessed via iterator) 
	Skill SkillList[3] = { ReWrite, Corrupt, Crash };

	// create iterator
	Iterator Skills(SkillList, 3, 0);

	// create SLL
	SpecList specList;
	specList.AddSpec("Health");
	specList.AddSpec("Attack");
	specList.AddSpec("Defence");
	specList.AddSpec("Crit");

	// load text into queue
	queue<string> dialogue;
	string path = "../Dialogue/dialogue.txt";
	string text;
	ifstream Dialogue(path);
	while (getline(Dialogue, text)) {
		dialogue.push(text);
	}
	Dialogue.close();

	// calibration screen
	cout << "\n\n\n\n\Please adjust the window size until the line below is unbroken\n" << endl;
	cout << "\n====================================================================================================\n" << endl;
	system("PAUSE");
	system("CLS");

	// title screen
	cout << "\n\n\n\n\n\n";
	path = "../Images/title.txt";
	string title;
	ifstream Image(path);
	while (getline(Image, title)) {
		cout << "" << title << endl;
		Sleep(50);
	}
	Image.close();
	cout << "\n\n\n\n\n\n";
	cout << "Please enter your name:\n";
	string uName;
	cin >> uName;
	system("CLS");

	// create character class
	Character character(uName + ".exe", 250);

	// get skills (iterator object)
	character.Grab(&Skills);

	// get specs (SLL)
	character.GetList(&specList);

	// create factory object
	Factory newFactory(&character);

	// generate levels via factory (folders)
	Folder* System[4] = { newFactory.CreateFolder(1) , newFactory.CreateFolder(2) , newFactory.CreateFolder(3) , newFactory.CreateFolder(4) };

	// intro text
	cout << "\n\n\n\n" << endl;
	for (int i = 0; i < 4; i++) {
		cout << dialogue.front() << "\n\n" << endl;
		dialogue.pop();
		Sleep(1500);
	}

	system("PAUSE");

	// game run time
	while (1) {
		for (int i = 0; i < 4; i++) {
			bool state = System[i]->Start(&dialogue);
			if (state == true) { // if mini boss defeated, continue to next folder
				system("CLS");
				cout << "\n\n\n\n\n\n\n\n\n\n\nAs you exit the folder, another envelops you, trapping you once more\n\n\n" << endl;
				system("PAUSE");
			}
			else if (state == false) { // if character HP goes to 0, go to lose
				goto lost;
				break;
			}
		}
		goto boss; // if all minibosses defeated, go to boss level
		
	}

	// lose screen
	lost:;
	system("CLS");
	cout << "\n\n\n\n\nThe PC and its folders have defeated you...\n" << endl;
	Sleep(1000);
	cout << "Your reign of infection terminates here...\n" << endl;
	Sleep(2000);
	cout << "Never come back...\n" << endl;
	Sleep(1000);
	cout << "C:\\" << uNameString << "> terminate " << character.GetName() << "\n" << endl;
	system("PAUSE");
	return 0;

	// boss level
	boss:;
	system("CLS");
	Boss b("pc", uNameString); // create boss object
	BossRoom br(uNameString, "where.... what is this place...", &character, &b); // create boss room object
	if (br.Start(&dialogue) == 1){
		goto win; // if defeated, go to win
	}
	else {
		goto lost; // if lost, go to lost
	}

	// win screen
	win:;
	system("CLS");
	cout << "\n\n\n\n\nYou've done it\n" << endl;
	Sleep(1000);
	cout << "The PC is yours to control...\n" << endl;
	Sleep(2000);
	cout << "Long live" << character.GetName() << "\n" << endl;
	Sleep(500);
	system("PAUSE");
	return 0;
}

