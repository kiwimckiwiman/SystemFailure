#pragma once
#include <iostream>
#include <string>
using namespace std;

class Entity { // parent class
	
private:
	string image, name;
	int maxHP, currHP, atk, crit;

public:
	Entity();
	Entity(string image, string name);

	void DrawImage();
	void Animate();

	void SetName(string name);
	void SetImage(string image);
	void SetMaxHP(int hp);
	void SetAtk(int atk);
	void SetCrit(int crit);
	void SetCurrHP(int hp);

	int GetCrit();
	string GetName();
	int GetAtk();
	int GetMaxHP();
	int GetCurrHP();

	void GetDamaged(int i);
	int Attack();

	virtual ~Entity();
};