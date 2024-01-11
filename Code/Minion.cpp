#include "Minion.h";

Minion::Minion() {

}

Minion::Minion(string s, int md, string n, string a):Entity(s, n) { // Minion is child class of Entity (inheritance)
	SetImage(s);
	SetName(n);
	SetMaxHP(200 + (200 * 0.2 * md));
	SetAtk(15 + md);
	SetCrit(30);
	atkName = a;
}

string Minion::GetAtkName() {
	return atkName;
}
Minion::~Minion() { // done
	
}
