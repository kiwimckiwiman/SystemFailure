#include <iostream>
#include "Character.h"
using namespace std;

Character::Character() {

}
Character::Character(string mName, int mHealth) {
	name = mName;
	maxHP = mHealth;
	currHP = mHealth;
}

string Character::GetName() {
	return name;
}

int Character::GetCurrHP() {
	return currHP;
}

void Character::GetHP(int health) {
	int cHP = currHP + health;
	if (cHP >= maxHP) {
		currHP = maxHP;
	}
	else {
		currHP = cHP;
	}
}

int Character::GetMaxHP() {
	int health = Specs->FindMultiplier(1);
	return maxHP + health;
}

void Character::GetDamaged(int i) {
	int def = Specs->FindMultiplier(4);
	int damageReduce = i * def/100;
	currHP = currHP - (i-damageReduce);
}

// iterator functions

void Character::Grab(Iterator* iter) { // get iterator object
	fIter = iter;
}

void Character::NextSkill() { // get next object in array
	if (*fIter != (*fIter).end()) {
		(*fIter)++;
	}
	else {
		cout << "Last item reached" << endl;
	}

}


void Character::PrevSkill() { // get previous skill in array
	if (*fIter != (*fIter).begin()) {
		(*fIter)--;
	}
	else {
		cout << "First item reached" << endl;
	}
}


int Character::Attack() { // use skill in array
	if ((*fIter).GetfIndex() == (*fIter).GetfLength()) {
		(*fIter)--;
	}
	else if ((*fIter).GetfIndex() < 0) {
		(*fIter)++;
	}
	int atkMult = Specs->FindMultiplier(2);
	int critMult = Specs->FindMultiplier(4);
	int baseatk = ((*(*fIter)).GetAttack() + ((*(*fIter)).GetAttack() * atkMult/100));
	int random = rand() % 101;
	if (critMult < 50) {
		if (random < critMult) {
			return baseatk * 2;
		}
		else {
			return baseatk;
		}
	}
	else if(50 < critMult < 100) {
		if (random < critMult) {
			return baseatk * 3;
		}
		else {
			return baseatk;
		}
	}
	else if (100 < critMult) {
		if (random < critMult) {
			return baseatk * 4;
		}
		else {
			return baseatk;
		}
	}
}

string Character::GetSkillDesc() { // get skill description
	return (*(*fIter)).GetDesc();
}

int Character::GetSkillCooldown() { // get skill cooldown
	return (*(*fIter)).GetCooldown();
}

string Character::GetSkillName() { // get skill name
	if ((*fIter).GetfIndex() == (*fIter).GetfLength()) {
		(*fIter)--;
	}
	else if ((*fIter).GetfIndex() < 0) {
		(*fIter)++;
	}
	return (*(*fIter)).GetName();
}

void Character::ToBegin() { // points iterator to head of array
	*fIter = (*fIter).begin();
}

void Character::SetSkillCurrRound(int i) { // set current round
	(*(*fIter)).SetCurrRound(i);
}

void Character::SetSkillRoundUsed(int i) { // set skill round used
	(*(*fIter)).SetRoundUsed(i);
}

// SLL functions

void Character::GetList(SpecList* List) { // get list object
	Specs = List;
}

void Character::UpgradeSpec(int pos) { // upgrade spec
	Specs->UpgradeSpec(pos);
}

string Character::GetSpecName(int pos) { // get spec name
	return Specs->GetSpecName(pos);
}

void Character::ViewSpecs() { // new all specs
	Specs->ViewAllSpecs();
}

// stack functions

void Character::AddBuffer(Buffer b) { // push to stack
	bufferStack.push(b);
}

void Character::RemoveBuffer() { // pop from stack
	bufferStack.pop();
}

string Character::GetTopBufferName() { // get top buffer name
	if (bufferStack.empty()) {
		return "";
	}
	else {
		return bufferStack.top().name + " has soaked up your damage!";
	}
}

int Character::GetTopBufferHealth() { // get top buffer health
	if (bufferStack.empty()) {
		return 0;
	}
	else {
		return bufferStack.top().bHealth;
	}
}

Character::~Character(){

}