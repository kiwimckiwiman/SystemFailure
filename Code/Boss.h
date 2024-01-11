#pragma once
#include "Entity.h";

class Boss : public Entity { // Boss is child class of Entity (inheritance)
public:
	Boss();
	Boss(string image, string name);
	string GetAtkName1();
	string GetAtkName2();
	void DrawImage(int i); // function is different from base version (polymorphism)
	int Attack1();
	int Attack2();
	~Boss();
};