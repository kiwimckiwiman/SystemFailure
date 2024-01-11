#include "BossRoom.h"
#include <windows.h>
#include <fstream>


using namespace std;

BossRoom::BossRoom(string n, string desc, Character* c, Boss* m) :Room(n, desc, c) { // BossRoom is child class of Room (inheritance)
	roomName = n;
	description = desc;
	character = c;
	enemy = m;
}


int BossRoom::Start(queue<string>* dialogue) { // function is different from base version (polymorphism)
	switch (Encounter(dialogue)) {
	case 0:
		system("CLS");
		this->isExplored();
		enemy->~Boss();
		return 1;
	case 1:
		system("CLS");
		return 0;
	case 2:
		system("CLS");
		return 2;
	}
}

void BossRoom::Animate(queue<string>* dialogue) {
	cout << "\n\n\n\n\n\n" << endl;
	enemy->DrawImage(1);
	Sleep(3000);

	for (int i = 6; i > 0; i--) {
		int j = i;
		while (j != 0) {
			cout << "\n";
			j--;
		}
		cout << endl;
		enemy->DrawImage(1);
		Sleep(50);
		system("CLS");
	}

	for (int i = 0; i < 6; i++) {
		system("CLS");
		enemy->DrawImage(2);
		cout << "\n====================================================================================================\n\n\n" << endl;
		cout << dialogue->front() << endl;
		dialogue->pop();
		cout << "\n\n\n====================================================================================================\n" << endl;
		system("PAUSE");
	}

	for (int i = 0; i < 2; i++) {
		system("CLS");
		enemy->DrawImage(3);
		cout << "\n====================================================================================================\n\n\n" << endl;
		cout << dialogue->front() << endl;
		dialogue->pop();
		cout << "\n\n\n====================================================================================================\n" << endl;
		system("PAUSE");
	}

	for (int i = 0; i < 5; i++) {
		system("CLS");
		enemy->DrawImage(4);
		cout << "\n====================================================================================================\n\n\n" << endl;
		cout << dialogue->front() << endl;
		dialogue->pop();
		cout << "\n\n\n====================================================================================================\n" << endl;
		system("PAUSE");
	}
}

int BossRoom::Encounter(queue<string>* dialogue) {
	while (1) {
		system("CLS");
		cout << "\nYou find a huge stash of memory... your health is back up to full\n" << endl;
		Sleep(3000);
		cout << "It's coming... it's bad.... turn back now..." << endl;
		Sleep(2000);
		character->GetHP(1000);
		system("CLS");
		cout << "\n\n\n\n\n\n\n\nIt's too late" << endl;
		Sleep(2000);
		system("CLS");
		Animate(dialogue);
		return EngageAttack(1, dialogue, true);
		break;
	}
}

void BossRoom::DrawBoss(int i) {
	system("CLS");
	enemy->DrawImage(i);
	cout << "\n====================================================================================================\n" << endl;
	cout << "                           " << "    " << enemy->GetCurrHP() << "/" << enemy->GetMaxHP() << " MB [";
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

}

int BossRoom::EngageAttack(int round, queue<string>* dialogue, bool restart) {
	int move = 0;
	bool blocked = false;
	bool mitigated = false;
	int randHelp;
	do {
		system("CLS");
		randHelp = rand() % 101;
		if (randHelp > 80) {
			DrawBoss(1);
			character->GetHP(character->GetMaxHP() / 4);
			cout << enemy->GetName() << " has its code exposed! You heal for a quarter of your health!" << endl;
			system("PAUSE");
		}
		if (enemy->GetCurrHP() <= 0) {
			if (restart) {
				system("CLS");
				Sleep(1000);
				enemy->DrawImage(5);
				Sleep(2000);
				system("CLS");
				enemy->DrawImage(3);
				Sleep(1000);
				for (int i = 0; i < 2; i++) {
					system("CLS");
					enemy->DrawImage(3);
					cout << "\n====================================================================================================\n\n\n" << endl;
					cout << dialogue->front() << endl;
					dialogue->pop();
					cout << "\n\n\n====================================================================================================\n" << endl;
					system("PAUSE");
				}
				system("CLS");
				enemy->DrawImage(4);
				cout << "\n====================================================================================================\n\n\n" << endl;
				cout << dialogue->front() << endl;
				dialogue->pop();
				cout << "\n\n\n====================================================================================================\n" << endl;
				system("PAUSE");

				enemy->SetCurrHP(enemy->GetMaxHP());
				restart = false;
			}
			else {
				return 0;
			}
			
		}
		else if (character->GetCurrHP() <= 0) {
			return 1;
		}
		
		DrawBoss(1);

		if (move == 0) {
			if (blocked) {
				cout << "Your turn is skipped!" << endl;
				system("PAUSE");
				move = 1;
				blocked = false;
			}

			else {
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
					if (EngageAttack(round, dialogue, restart) == 0) {
						return 0;
					}
					else if (EngageAttack(round, dialogue, restart) == 1) {
						return 1;
					}
				}
				else if (input == "p") {
					character->PrevSkill();
					character->SetSkillCurrRound(round);
					if (EngageAttack(round, dialogue, restart) == 0) {
						return 0;
					}
					else if (EngageAttack(round, dialogue, restart) == 1) {
						return 1;
					}
				}
				else if (input == "a") {
					int attack;
					if (mitigated) {
						attack = 0;
						mitigated = false;
					}
					else {
						attack = character->Attack();
					}
					character->SetSkillCurrRound(round);
					if (character->Attack() == 0) {
						cout << character->GetName() << " used: " << character->GetSkillName() << endl;
						system("PAUSE");
						if (EngageAttack(round, dialogue, restart) == 0) {
							return 0;
						}
						else if (EngageAttack(round, dialogue, restart) == 1) {
							return 1;
						}
					}
					else {
						character->SetSkillRoundUsed(round);
						cout << "\n" << character->GetName() << " used: " << character->GetSkillName() << endl;
						enemy->GetDamaged(attack);
						move = 1;
						system("PAUSE");
					}
					if (mitigated) {
						cout << "\nYour damage was soaked up by the Firewall!" << endl;
					}
					character->ToBegin();
				}
				else {
					cout << "Invalid input" << endl;
					system("PAUSE");
					if (EngageAttack(round, dialogue, restart) == 0) {
						return 0;
					}
					else if (EngageAttack(round, dialogue, restart) == 1) {
						return 1;
					}
				}
			}
		}
		else {
			int random = rand() % 6;
			if (random < 2) {
				DrawBoss(6);
				int attack = enemy->Attack1();
				
				cout << "\n" << enemy->GetName() << " used " << enemy->GetAtkName1() << "!\n\n" << attack << " damage dealt!" << endl;
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
			else if (random == 3) {
				DrawBoss(9);
				int attack = enemy->Attack2();
				cout << "\n" << enemy->GetName() << " used " << enemy->GetAtkName2() << "!\n\n" << attack << " damage dealt!" << endl;
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
			else if (random == 4) {
				DrawBoss(8);
				cout << "\n" << enemy->GetName() << " used Anti Virus!\n\nYour next turn's is skipped!\n" << endl;
				system("PAUSE");
				blocked = true;
				move = 0;
			}
			else if (random == 5) {
				DrawBoss(7);
				cout << "\n" << enemy->GetName() << " used FireWall!\n\nYour next turn's damage is mitigated!\n" << endl;
				system("PAUSE");
				move = 0;
				mitigated = true;
			}
		}
		round++;
	} while (1);
}

BossRoom::~BossRoom() { // done

}