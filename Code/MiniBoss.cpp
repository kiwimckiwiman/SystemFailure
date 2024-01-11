#include "MiniBoss.h";

MiniBoss::MiniBoss() {

}

MiniBoss::MiniBoss(string s, int md, string n, string a, string b, string c) :Entity(s, n) {
	SetImage(s);
	SetName(n);
	SetMaxHP(400 + (150 * md));
	SetCrit(40);
	atk1 = 15 + (md * 5);
	atk2 = 25 + (md * 5);
	atkName1 = a;
	atkName2 = b;
	skill1 = c;
}

string MiniBoss::GetAtkName1() {
	return atkName1;
}

string MiniBoss::GetAtkName2() {
	return atkName2;
}

string MiniBoss::GetSkillName() {
	return skill1;
}

int MiniBoss::Attack1() {
	int random = rand() % 101;
	if (random < GetCrit()) {
		int attack = atk1 * 2;
		return attack;
	}
	else {
		return atk1;
	}
}

int MiniBoss::Attack2() {
	int random = rand() % 101;
	if (random < GetCrit()) {
		int attack = atk2 * 2;
		return attack;
	}
	else {
		return atk2;
	}
}

MiniBoss::~MiniBoss() { // done

}
