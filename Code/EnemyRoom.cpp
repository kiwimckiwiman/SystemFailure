#include "EnemyRoom.h"

using namespace std;

EnemyRoom::EnemyRoom(string n, string desc, Character* c, Minion* m):Room(n, desc, c) { // EnemyRoom is child class of Room (inheritance)
	roomName = n;
	description = desc;
	character = c;
	enemy = m;
}

void EnemyRoom::UpgradeSpec() {
	int input;
	while (1) {
		cout << "You have slain " << enemy->GetName() << endl;
		cout << "\nChoose a spec to upgrade:\n" << endl;
		character->ViewSpecs();
		cin >> input;
		switch (input) {
		case 1:
			character->UpgradeSpec(1);
			cout << character->GetSpecName(1) << " has been upgraded!" << endl;
			goto exit;
		case 2:
			character->UpgradeSpec(2);
			cout << character->GetSpecName(2) << " has been upgraded!" << endl;
			goto exit;
		case 3:
			character->UpgradeSpec(3);
			cout << character->GetSpecName(3) << " has been upgraded!" << endl;
			goto exit;
		case 4:
			character->UpgradeSpec(4);
			cout << character->GetSpecName(4) << " has been upgraded!" << endl;
			goto exit;
		default:
			system("CLS");
			cout << "Invalid input" << endl;
			break;
		}
	}
exit:;
	system("PAUSE");
}

int EnemyRoom::Start() { // function is different from base version (polymorphism)
	if (this->getExplored()) {
		cout << "Explored!" << endl;
		system("PAUSE");
		return 2;
	}
	else {
		switch (Encounter()) {
		case 0:
			system("CLS");
			UpgradeSpec();
			this->isExplored();
			enemy->~Minion();
			return 1;
		case 1:
			system("CLS");
			return 0;
		case 2:
			system("CLS");
			return 2;
		}
	}
}

int EnemyRoom::Encounter() {
	while (1) {
		system("CLS");
		cout << description << "\nDo you wish to continue? [y/n]" << endl;
		string encounter;
		cin >> encounter;
		if (encounter == "y") {
			return EngageAttack(1);
			break;
		}
		else if (encounter == "n") {
			return 2;
			break;
		}
		else {
			system("CLS");
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid input\n" << endl;
			system("PAUSE");
		}
	}
}

int EnemyRoom::EngageAttack(int round) {

	int move = 0;
	int defeat = false;
	do {
		system("CLS");
		if (enemy->GetCurrHP() <= 0) {
			return 0;
		}
		else if (character->GetCurrHP() <= 0) {
			return 1;
		}
		enemy->DrawImage();
		cout << "\n====================================================================================================\n" << endl;
		cout << "                                    " << "    " << enemy->GetCurrHP() << "/" << enemy->GetMaxHP() << " MB [";
		int percentEnemy = floor((enemy->GetCurrHP() * 30 / enemy->GetMaxHP()));
		for (int i = 1; i < 31; i++) {
			if (i <= percentEnemy) {
				cout << "=";
			}
			else {
				cout << ".";
			}
		}
		cout << "]     " << enemy->GetName() << "\n" << endl;

		cout << "   " << character->GetName() << "    " << character->GetCurrHP() << "/" << character->GetMaxHP() << " MB [";
		int percentPlayer = floor((character->GetCurrHP() * 30 / character->GetMaxHP()));
		for (int i = 1; i < 31; i++) {
			if (i <= percentPlayer) {
				cout << "=";
			}
			else {
				cout << ".";
			}
		}
		cout << "]" << endl;
		cout << "\n====================================================================================================\n" << endl;

		if (move == 0) {
			cout << "Choose Skill" << endl;
			cout << "------------" << endl;
			cout << "Type 'n' for next skill, 'p' for previous skill, 'a' to use current skill\n" << endl;
			cout << "Current Skill: " << character->GetSkillName() << endl;
			cout << character->GetSkillDesc() << " (Does " << character->Attack() << " damage)" << endl;
			cout << "\nCooldown: " << character->GetSkillCooldown() / 2 << " rounds" << endl;
			string input;
			cin >> input;
			if (input == "n") {
				character->NextSkill();
				character->SetSkillCurrRound(round);
				if (EngageAttack(round) == 0) {
					return 0;
				}
				else if (EngageAttack(round) == 1) {
					return 1;
				}
			}
			else if (input == "p") {
				character->PrevSkill();
				character->SetSkillCurrRound(round);
				if (EngageAttack(round) == 0) {
					return 0;
				}
				else if (EngageAttack(round) == 1) {
					return 1;
				}
			}
			else if (input == "a") {
				character->SetSkillCurrRound(round);
				if (character->Attack() == 0) {
					cout << character->GetName() << " used: " << character->GetSkillName() << endl;
					system("PAUSE");
					if (EngageAttack(round) == 0) {
						return 0;
					}
					else if (EngageAttack(round) == 1) {
						return 1;
					}
				}
				else {
					character->SetSkillRoundUsed(round);
					cout << "\n" << character->GetName() << " used: " << character->GetSkillName() << endl;
					enemy->GetDamaged(character->Attack());
					move = 1;
					system("PAUSE");
				}
				character->ToBegin();
			}
			else {
				cout << "Invalid input" << endl;
				system("PAUSE");
				if (EngageAttack(round) == 0) {
					return 0;
				}
				else if (EngageAttack(round) == 1) {
					return 1;
				}
			}
		}
		else {
			int attack = enemy->Attack();
			cout << "\n" << enemy->GetName() << " used "  << enemy->GetAtkName() << "!\n\n" << attack << " damage dealt!\n" << endl;
			if ((character->GetTopBufferHealth() == 0)) {
				character->GetDamaged(attack);
				move = 0;
				system("PAUSE");
			}
			else if (character->GetTopBufferHealth() == attack) {
				cout << character->GetTopBufferName() << endl;
				character->RemoveBuffer();
				move = 0;
				system("PAUSE");
			}
			else if (character->GetTopBufferHealth() > attack) {
				cout << character->GetTopBufferName() << endl;
				character->RemoveBuffer();
				move = 0;
				system("PAUSE");
			}
			else if ((character->GetTopBufferHealth() < attack)) {
				int oncoming = attack;
				int buffer;
				while (1) {
					buffer = character->GetTopBufferHealth();
					cout << character->GetTopBufferName() << endl;
					character->RemoveBuffer();
					oncoming = oncoming - buffer;
					if (character->GetTopBufferHealth() == oncoming) {
						cout << character->GetTopBufferName() << endl;
						character->RemoveBuffer();
						break;
					}
					else if (character->GetTopBufferHealth() > oncoming) {
						cout << character->GetTopBufferName() << endl;
						break;
					}
					else {
						break;
					}

				}
				move = 0;
				system("PAUSE");
			}
		}
		round++;
	} while (1);
}

EnemyRoom::~EnemyRoom() { // done

}