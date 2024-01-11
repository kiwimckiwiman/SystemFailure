#pragma once
#include <iostream>
#include <string>
using namespace std;

class Skill { // Skill object
private:
	string name;
	string desc;
	int atk, cooldown, roundUsed, currRound;

public:
	Skill(string name, string desc, int atk, int cooldown);

	int UseSkill();
	string GetName();
	int GetAttack();
	string GetDesc();
	int GetCooldown();

	void SetRoundUsed(int i);
	void SetCurrRound(int i);

	~Skill();
};