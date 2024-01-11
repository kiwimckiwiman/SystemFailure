#include "MiniBossRoom.h"
#include <windows.h>
#include <fstream>


using namespace std;

MiniBossRoom::MiniBossRoom(string n, string desc, Character* c, MiniBoss* m) :Room(n, desc, c) {
	roomName = n;
	description = desc;
	character = c;
	enemy = m;
}


void MiniBossRoom::UpgradeSpec() {
	int input;
	int specpoints = 3;
	while (specpoints != 0) {
		system("CLS");
		cout << "You have slain " << enemy->GetName() << endl;
		cout << "\nChoose " << specpoints << " spec(s) to upgrade : \n" << endl;
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
		exit:;
		specpoints--;
		system("PAUSE");
	}

}

int MiniBossRoom::Start(queue<string>* dialogue) {
	if (this->getExplored()) {
		cout << "Explored!" << endl;
		system("PAUSE");
		return 2;
	}
	else {
		switch (Encounter(dialogue)) {
		case 0:
			system("CLS");
			UpgradeSpec();
			this->isExplored();
			enemy->~MiniBoss();
			system("CLS");
			cout << "\n\n\nYour health has been restored to 100%\n" << endl;
			system("PAUSE");
			character->GetHP(character->GetMaxHP());
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

void MiniBossRoom::Animate(queue<string>* dialogue) {
	cout << "\n\n\n\n\n\n" << endl;
	enemy->Animate();

	for (int i = 6; i > 0; i--) {
		int j = i;
		while (j != 0) {
			cout << "\n";
			j--;
		}
		cout << endl;
		enemy->DrawImage();
		Sleep(50);
		system("CLS");
	}

	for (int i = 0; i < 3; i++) {
		system("CLS");
		enemy->DrawImage();
		cout << "\n====================================================================================================\n\n\n" << endl;
		cout << dialogue->front() << endl;
		dialogue->pop();
		cout << "\n\n\n====================================================================================================\n" << endl;
		system("PAUSE");
	}
	
}

int MiniBossRoom::Encounter(queue<string>* dialogue) {
	while (1) {
		cout << "\nAs you exit, the walls of the folder close in on you, sealing you in...\n" << endl;
		Sleep(2000);
		cout << description << "\n\nDo you wish to continue? [y/n]" << endl;
		string encounter;
		cin >> encounter;
		if (encounter == "y") {
			system("CLS");
			cout << "\nYou found a way to repurpose the code of the enemies you've slain to restore half of your health\n" << endl;
			Sleep(3000);
			cout << "Its coming..." << endl;
			Sleep(2000);
			character->GetHP((character->GetMaxHP()) / 2);
			system("CLS");
			Animate(dialogue);
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
		system("CLS");
	}
}

int MiniBossRoom::EngageAttack(int round) {

	int move = 0;
	int defeat = false;
	bool blocked = false;
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
			if (blocked) {
				cout << "\n\nYour turn is skipped!" << endl;
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
		}
		else {
			int random = rand() % 5;
			if (random == 2 || random == 3) {
				int attack = enemy->Attack1();
				cout << "\n" << enemy->GetName() << " used " << enemy->GetAtkName1() << "!\n\n" << attack << " damage dealt!\n" << endl;
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
				int attack = enemy->Attack2();
				cout << "\n" << enemy->GetName() << " used " << enemy->GetAtkName2() << "!\n\n" << attack << " damage dealt!\n" << endl;
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
			else if(random == 1) {
				cout << "\n" << enemy->GetName() << " used " << enemy->GetSkillName() << "!\n\nYour next turn's is skipped!\n" << endl;
				system("PAUSE");
				blocked = true;
				move = 0;
			}
		}
		round++;
	} while (1);
}

MiniBossRoom::~MiniBossRoom() { // done

}