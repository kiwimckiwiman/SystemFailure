#include <iostream>;
#include <fstream>
#include <string>
#include <windows.h>
#include "Entity.h";
using namespace std;

Entity::Entity() {

}
Entity::Entity(string i, string n){
	image = i;
	name = n;
	maxHP = 0;
	currHP = 0;
	atk = 0;
	crit = 0;
}


void Entity::DrawImage() {
	string path = "../Images/" + image + ".txt";
	string line;
	ifstream Image(path);
	while (getline(Image, line)) {
		cout << "                         " << line << endl;
	}
	Image.close();
}

void Entity::Animate() {
	string path = "../Images/" + image + ".txt";
	string line;
	ifstream Image(path);
	while (getline(Image, line)) {
		cout << "                         " << line << endl;
		Sleep(100);
	}
	Image.close();
}

void Entity::SetName(string s) {
	name = s;
}

void Entity::SetMaxHP(int i) {
	maxHP = i;
	currHP = i;
}

void Entity::SetImage(string s) {
	image = s;
}

void Entity::SetAtk(int i) {
	atk = i;
}

void Entity::SetCrit(int i) {
	crit = i;
}

void Entity::SetCurrHP(int hp) {
	currHP = hp;
}

int Entity::GetCrit() {
	return crit;
}

string Entity::GetName() {
	return name;
}

void Entity::GetDamaged(int i) {
	currHP = currHP - i;
}

int Entity::GetAtk() {
	return atk;
}

int Entity::GetCurrHP() {
	return currHP;
}

int Entity::GetMaxHP() {
	return maxHP;
}


int Entity::Attack() {
	int random = rand() % 101;
	if (random < crit) {
		int attack = atk*2;
		return attack;
	}
	else {
		return atk;
	}
}

Entity::~Entity() { // done
	
}