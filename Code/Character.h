#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "Iterator.h"
#include "SpecList.h"

using namespace std;

struct Buffer { // buffer details (struct)
	string name;
	int bHealth;
};

class Character {
	
private:
	string name;
	int maxHP;
	int currHP;
	Iterator* fIter; // skill set (iterator)
	SpecList* Specs; // specs (SLL)
	stack<Buffer> bufferStack; // shield buffers (stack)
	

public:
	Character();
	Character(string name, int health);

	// class fucntions
	string GetName();
	int GetCurrHP();
	int GetMaxHP();
	void GetHP(int health);
	void GetDamaged(int i);

	// iterator functions
	void Grab(Iterator* iter);
	void NextSkill();
	void PrevSkill();
	string GetSkillName();
	string GetSkillDesc();
	int GetSkillCooldown();
	int Attack();
	void ToBegin();
	void SetSkillRoundUsed(int i);
	void SetSkillCurrRound(int i);

	// SLL functions
	void GetList(SpecList* List);
	string GetSpecName(int pos);
	void UpgradeSpec(int pos);
	void ViewSpecs();

	// stack functions
	void AddBuffer(Buffer b);
	void RemoveBuffer();
	string GetTopBufferName();
	int GetTopBufferHealth();

	~Character();
};