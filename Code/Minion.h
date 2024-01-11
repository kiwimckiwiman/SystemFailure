#pragma once
#include "Entity.h";

class Minion : public Entity { // Minion is child class of Entity (inheritance)
private:
	string atkName;
public:
	Minion();
	Minion(string image, int md, string name, string atkName);
	string GetAtkName();
	~Minion();
};