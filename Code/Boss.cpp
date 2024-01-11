#include "Boss.h";
#include <fstream>

Boss::Boss() {

}

Boss::Boss(string s, string n) :Entity(s, n) { // Boss is child class of Entity (inheritance)
	SetImage(s);
	SetName(n);
	SetMaxHP(1000);
	SetCrit(40);
}

string Boss::GetAtkName1() {
	return "Delete";
}

string Boss::GetAtkName2() {
	return "End Task";
}


int Boss::Attack1() {
	return 40;
}

int Boss::Attack2() {
	return 60;
}

void Boss::DrawImage(int i) { // function is different from base version (polymorphism)
	string path = "";
	string line = "";
	ifstream Image(path);
	if (i == 1) {
		string path = "../Images/pc.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 2) {
		string path = "../Images/hello.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 3) {
		string path = "../Images/sad.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 4) {
		string path = "../Images/angry.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 5) {
		string path = "../Images/restart.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 6) {
		string path = "../Images/delete.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 7) {
		string path = "../Images/firewall.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 8) {
		string path = "../Images/antivirus.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
	else if (i == 9) {
		string path = "../Images/endtask.txt";
		string line;
		ifstream Image(path);
		while (getline(Image, line)) {
			cout << "               " << line << endl;
		}
		Image.close();
	}
}


Boss::~Boss() { // done

}
