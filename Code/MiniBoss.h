#pragma once
#include "Entity.h";

class MiniBoss : public Entity { // MiniBoss is child class of Entity (inheritance)
private:
	string atkName1, atkName2, skill1;
	int atk1, atk2;
public:
	MiniBoss();
	MiniBoss(string image, int md, string name, string atkName1, string atkName2, string skillname);
	string GetAtkName1();
	string GetAtkName2();
	string GetSkillName();
	int Attack1();
	int Attack2();
	~MiniBoss();
};