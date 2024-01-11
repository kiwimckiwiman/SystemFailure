#include <iostream>
#include <string>

#include "Skill.h";

Skill::Skill(string mName, string mDesc, int mAtk, int mCooldown) {
	name = mName;
	desc = mDesc;
	atk = mAtk;
	cooldown = mCooldown;
}

int Skill::UseSkill() {
	return atk;
}

string Skill::GetDesc() {
	return desc;
}

int Skill::GetCooldown() {
	return cooldown;
}

string Skill::GetName() {
	if (cooldown == 0) {
		return name;
	}
	else {
		if (((currRound - roundUsed) == cooldown / 2) || ((currRound - roundUsed) == cooldown)) {
			return name + " (Move is on cooldown!)";
		}
		else {
			return name;
		}
	}
}

int Skill::GetAttack() {
	if (cooldown == 0) {
		return atk;
	}else{
		if (((currRound - roundUsed) == cooldown / 2) || ((currRound - roundUsed) == cooldown)) {
			return 0;
		}
		else {
			return atk;
		}
	}
}

void Skill::SetRoundUsed(int i) {
	roundUsed = i;
}

void Skill::SetCurrRound(int i) {
	currRound = i;
}

Skill::~Skill() {

}