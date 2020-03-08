#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include <cmath>
using namespace std;
struct Status{
	int playerHealth = 100;
	int enemyHealth = 100;
	int magicPower = 100;
	int knightSlash = 1;
	int counterAttack = 1;
	int goddessHeal = (playerHealth * 30) / 100;
	int enrage = (knightSlash * 35) / 100;
	int floor = 1;
	int monsterDamage = 1;
	int tries = 3;
};
void box();
void title();
void tower();
void defeat();
void applause();
void boxDelay();
void dialogue(string);
void defaultKnight();
void knightSlash();
void level1();
void level1Dmg();
void level2();
void level2Dmg();
void level3();
void level3Dmg();
void level4();
void level4Dmg();
void level5();
void level5Dmg();
void level6();
void level6Dmg();
void level7();
void level7Dmg();
void level8();
void level8Dmg();
void level9();
void level9Dmg();
void level10();
void level10Dmg();
void knightDmg();
void knightDmg1();
void counterAttack();
void Heal();
void Heal1();
void Heal2();
void enrage();
void enrage1();
void enrage2();
void monsterLevel(Status *stats);
void monsterLevelDamage(Status *stats);
void monsterRandom(Status *stats);
void knightRandom(Status *stats);
void floorLeveling(char player[255],Status * stats);
void ConsoleWindow(short x, short y, short cx, short cy);
void fightLoop(char player[255],Status *stats);
void firstLevel(char player[255],Status *stats);
void secondLevel(char player[255],Status *stats);
void thirdLevel(char player[255],Status *stats);
void fourthLevel(char player[255],Status *stats);
void fifthLevel(char player[255],Status *stats);
void sixthLevel(char player[255],Status *stats);
void seventhLevel(char player[255],Status *stats);
void eightLevel(char player[255],Status *stats);
void ninthLevel(char player[255],Status *stats);
void tenthLevel(char player[255],Status *stats);
std::string getFileContents (std::ifstream&); 
int main(){
	
	Status stats;
	char player[255];
	string welcome = "Welcome, ";
	string intro = "You are now about to conquer the the tower in front of you...";
	string proceed = "We will now proceed to the first floor...";
	int choice;
	
	ConsoleWindow(0,0,1500,850);
	reMenu:
	title();
	cout << "\n\n\t\t\t\t\t\t\t\tSelect -> ";
	cin >> choice;
	switch(choice){
		case 1:
			cout << "\n\t\t\t\t\t\t\t\tEnter Player Name: ";
			cin.ignore();
			gets(player);
			system("cls");
			tower();
			defaultKnight();
			Sleep(1700);
			dialogue(welcome);
			for(int i = 0; i < strlen(player); i++){
				Sleep(50);
				cout << player[i];
			}
			cout << "!";
			Sleep(1300);
			cout << endl;
			dialogue(intro);
			Sleep(1300);
			cout << endl;
			dialogue(proceed);
			Sleep(2000);
			firstLevel(player,&stats);
			secondLevel(player,&stats);
			thirdLevel(player,&stats);
			fourthLevel(player,&stats);
			fifthLevel(player,&stats);
			sixthLevel(player,&stats);
			seventhLevel(player,&stats);
			eightLevel(player,&stats);
			ninthLevel(player,&stats);
			tenthLevel(player,&stats);
			break;
		case 2:
			exit(1);
			break;
		default:
			cout << "n\n\t\t\t\t\t\t\t\tInvalid Choice\n";
			Sleep(1300);
			system("cls");
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			goto reMenu;
	}
	return 0;
}
void box(){
	cout << "\t";
	for(int i = 0; i < 32; i++){
		std::cout << (char)254u << " ";
	}
}
void boxDelay(){
	cout << "\t";
	for(int i = 0; i < 32; i++){
		std::cout << (char)254u << " ";
		Sleep(40);
	}
}
void dialogue(string d){
	int x = 0;
	cout << "\n\t";
	while(d[x] != '\0'){
		cout << d[x];
		Sleep(20);
		x++;
	}
}
void fightLoop(char player[255],Status *stats){
	int choice;
	string narrate;
	char choose;
	bool checker = false, checker2 = true, checker3 = false, checker4 = false;
	while(stats -> playerHealth != 0 && stats -> enemyHealth != 0){
	restrike:
		if(stats -> playerHealth > 0){
			cout << "\n\n\t" << player << "'s Health = " << stats -> playerHealth;
			cout << "\t\tMonster's Health = " << stats -> enemyHealth << endl;
			cout << "\t" << player << "'s Magic Power = " << stats -> magicPower << endl;
			monsterLevel(stats);
			defaultKnight();
			narrate = "SKILLS: \n\t1 = Knight Slash (0MP) \n\t2 = Counter - Attack (50MP) \n\t3 = Goddess Heal (40MP) \n\t4 = Enrage (30MP)";
			dialogue(narrate);
			cout << "\n\n\tChoose your skill: ";
			cin >> choice;
			if(choice == 1){
				checker4 = false;
				string dialogue2 = "\n\tYou have slashed the monster...";
				system("cls");
				box();
				monsterLevel(stats);
				defaultKnight();
				Sleep(300);
				system("cls");
				box();
				cout << endl;
				monsterLevelDamage(stats);
				knightSlash();
				Sleep(400);
				Sleep(500);
				dialogue(dialogue2);
				Sleep(1300);
				knightRandom(stats);
				if(checker3 == true){
					int newDamage = (stats -> knightSlash * 20) / 100;
					stats -> knightSlash += newDamage;
					stats -> enemyHealth -= stats -> knightSlash;
				} else{
					stats -> enemyHealth -= stats -> knightSlash;
				}
				cout << "\n\tYou have inflicted " << stats -> knightSlash << " damage.";
				Sleep(1300);
				system("cls");
				box();
				int restoreMP = (stats -> knightSlash * 30) / 100;
				if(stats -> magicPower < 100){
					stats -> magicPower += restoreMP;
					if(stats -> magicPower > 100){
						stats -> magicPower = 100;
					}
				}
				checker3 = false;
			} else if(choice == 2){
				if(stats -> magicPower >= 50){
					checker2 = false;
					if(checker == true){
						checker4 = false;
						string dialogue2 = "\n\tYou have counter - attacked the monster...";
						system("cls");
						for(int i=0;i<5;i++)
						{
							monsterLevel(stats);
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5+i);
							counterAttack();
							Sleep(200);
							system("cls");
						}
						monsterLevelDamage(stats);
						defaultKnight();
						Sleep(300);
						system("cls");
						monsterLevel(stats);
						defaultKnight();
						Sleep(1000);
						dialogue(dialogue2);
						if(checker3 == true){
							stats -> counterAttack = (stats -> monsterDamage * 145) / 100;
							checker3 = false;
						} else{
							stats -> counterAttack = (stats -> monsterDamage * 120) / 100;
						}
						Sleep(1300);
						cout << "\n\tYou have inflicted " << stats -> counterAttack << " damage";
						Sleep(1300);
						system("cls");
						box();
						stats -> magicPower -= 50;
						stats -> monsterDamage = rand() % 8 + 7;
						stats -> enemyHealth -= stats -> counterAttack;
						checker = true;
					} else{
						cout << "\n\tWaiting for counter...\n";
						Sleep(1300);
						system("cls");
						box();
					}
				} else{
					cout << "\n\tNot enough mana...";
					Sleep(1700);
					system("cls");
					box();
					goto restrike;
				}
			}
			else if(choice == 3){
				checker4 = false;
				if(stats -> magicPower >= 40){
					if(stats -> playerHealth >= 100){
						cout << "\n\tYou have full health...";
						Sleep(1300);
						system("cls");
						box();
						goto restrike;
					} else{
						string dialogue2 = "\n\tYou have healed yourself...";
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						box();
						monsterLevel(stats);
						Heal();
						Sleep(300);
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						box();
						monsterLevel(stats);
						Heal1();
						Sleep(300);
						system("cls");
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						box();
						monsterLevel(stats);
						Heal2();
						Sleep(500);
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
						dialogue(dialogue2);
						Sleep(1300);
						cout << "\n\tYou healed " << stats -> goddessHeal << " life points";
						Sleep(900);
						stats -> magicPower -= 40;
						stats -> playerHealth += stats -> goddessHeal;
						if(stats -> playerHealth > 100){
							string dialogue2 = "You restored your health...";
							dialogue(dialogue2);
							Sleep(1300);
							stats -> playerHealth = 100;
						}
						Sleep(900);
						system("cls");
						box();
					}
				} else{
					cout << "\n\tNot enough mana...";
					Sleep(1700);
					system("cls");
					box();
					goto restrike;
				}			
			} else if(choice == 4){
				if(stats -> magicPower >= 30 && checker4 == false && checker2 == true){
					string dialogue2 = "\n\tYou have powered up...";
					system("cls");
					monsterLevel(stats);
					enrage();
					Sleep(300);
					system("cls");
					monsterLevel(stats);
					enrage1();
					Sleep(300);
					system("cls");
					monsterLevel(stats);
					enrage2();
					Sleep(300);
					system("cls");
					monsterLevel(stats);
					enrage1();
					Sleep(300);
					system("cls");
					monsterLevel(stats);
					enrage2();
					Sleep(300);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					dialogue(dialogue2);
					Sleep(1300); 
					cout << "\n\tYou have increased offensive skills by 35% for this turn...";
					Sleep(1300);
					stats -> magicPower -= 30;
					checker3 = true;
					checker4 = true;
					system("cls");
					box();
					goto restrike;
				} else if(checker4 == true || checker == true){
					cout << "\n\tEnrage already activated...";
					Sleep(1700);
					system("cls");
					box();
					goto restrike;
				} else{
					cout << "\n\tNot enough mana...";
					Sleep(1700);
					system("cls");
					box();
					goto restrike;
				}
			} else{
				cout << "\n\tInvalid Choice. Please Choose Properly.\n";
				Sleep(1300);
				system("cls");
				box();
				cin.clear();
				cin.ignore(INT_MAX,'\n');
				goto restrike;
			}
		} 
		if(stats -> enemyHealth > 0){
			cout << "\n\n\t" << player << "'s Health = " << stats -> playerHealth;
			cout << "\t\tMonster's Health = " << stats -> enemyHealth << endl;
			cout << "\t" << player << "'s Magic Power = " << stats -> magicPower << endl;
			Sleep(1300);
			if(stats -> playerHealth > 0){
				monsterLevel(stats);
				defaultKnight();
				string enemyDialogue = "\n\tMonster attacked you!\n";
				if(checker == true){
					checker = false;	
				} else{
					if(checker2 == false){
						checker = true;
					} else{
						checker = false;
					}
				}
				checker2 = true;
				dialogue(enemyDialogue);
				cout << endl;
				Sleep(500);
				system("cls");
				for(int i = 0 ; i < 3; i++){
					monsterLevel(stats);
					knightDmg();
					Sleep(100);
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					box();
					cout << endl;
					monsterLevel(stats);
					knightDmg1();
					Sleep(100);
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
					box();
					cout << endl;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				monsterLevel(stats);
				defaultKnight();
				Sleep(800);
				monsterRandom(stats);
				cout << "\n\tYou have been inflicted with " << stats -> monsterDamage << " damage";
				Sleep(2000);
				system("cls");
				box();
				stats -> playerHealth -= stats -> monsterDamage;
				if(stats -> playerHealth <= 0){
					stats -> playerHealth = 0;
					cout << "\n\n\t" << player << "'s Health = " << stats -> playerHealth;
					cout << "\t\tMonster's Health = " << stats -> enemyHealth << endl;
					cout << "\t" << player << "'s Magic Power = " << stats -> magicPower << endl;
					Sleep(1300);
					narrate = "\n\n\t Better luck next time! You haven\'t conquered floor: ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
					boxDelay();
					defeat();
					dialogue(narrate);
					cout << stats -> floor;
					Sleep(1800);
					system("Color 0F");
					cout << endl << endl << "\t\t";
					Sleep(1300);
					rechoose:
					narrate = "\n\n\tTry Again (Y/N): ";
					dialogue(narrate);
					cin >> choose;
					if(choose == 'Y' || choose == 'y'){
						if(stats -> tries > 0){
							stats -> tries--;
							cout << "\n\n\t Tries Left: " << stats -> tries;
							Sleep(1300);
							stats -> playerHealth = 100;
							stats -> magicPower = 100;
							stats -> enemyHealth = 100;
							floorLeveling(player,stats);
						} else{
							cout << "\n\n\tYou have no tries left...";
							cout << "\n\n\tGame Exiting...";
							system("pause>0");
							exit(1);
						}
					} else if(choose == 'N' || choose == 'n'){
						cout << "\n\n\tGame Exiting...";
						system("pause>0");
						exit(1);
					} else{
						cout << "\n\n\tInvalid Choice. Please Choose Properly.";
						Sleep(1300);
						system("cls");
						box();
						cin.clear();
						cin.ignore(INT_MAX,'\n');
						goto rechoose;
					}
				} 
			} 
		} else{
			stats -> enemyHealth = 0;
			cout << "\n\n\t" << player << "'s Health = " << stats -> playerHealth;
			cout << "\t\tMonster's Health = " << stats -> enemyHealth << endl;
			cout << "\t" << player << "'s Magic Power = " << stats -> magicPower << endl;
			Sleep(1000);
			narrate = "\n\n\tCONGRATULATIONS! You have conquered floor: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			boxDelay();
			dialogue(narrate);
			cout << stats -> floor << endl;
			Sleep(1300);
			narrate = "\tYou have increased your attack power...";
			dialogue(narrate);
			cout << endl << endl;
			defaultKnight();
			Sleep(3500);
			system("Color 0F");
		}	
	}
}
void title(){
	ifstream Reader("Title Screen.txt");
	ifstream Reader1("Title Screen 1.txt");
	ifstream Reader2("Title Screen 2.txt");
	ifstream Reader3("Title Screen 3.txt");
	string title = getFileContents(Reader);
	string title1 = getFileContents(Reader1);
	string title2 = getFileContents(Reader2);
	string title3 = getFileContents(Reader3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<title;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	cout<<title1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout<<title2;
	cout<<title3;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
void firstLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 1 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 1;
	fightLoop(player,stats);
	cout << endl;
}
void secondLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 2 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 2;
	stats -> enemyHealth = 105;
	fightLoop(player,stats);
	cout << endl;
}
void thirdLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 3 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 3;
	stats -> enemyHealth = 110;
	fightLoop(player,stats);
	cout << endl;
}
void fourthLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 4 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 4;
	stats -> enemyHealth = 115;
	fightLoop(player,stats);
	cout << endl;
}
void fifthLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 5 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 5;
	stats -> enemyHealth = 120;
	fightLoop(player,stats);
	cout << endl;
}
void sixthLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 6 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 6;
	stats -> enemyHealth = 125;
	fightLoop(player,stats);
	cout << endl;
}
void seventhLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 7 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 7;
	stats -> enemyHealth = 130;
	fightLoop(player,stats);
	cout << endl;
}
void eightLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 8 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 8;
	stats -> enemyHealth = 135;
	fightLoop(player,stats);
	cout << endl;
}
void ninthLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFloor 9 Monster has appeared!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 9;
	stats -> enemyHealth = 140;
	fightLoop(player,stats);
	cout << endl;
}
void tenthLevel(char player[255],Status *stats){
	string narrate;
	cout << endl;
	system("cls");
	boxDelay();
	narrate = "\n\n\tFINAL BOSS MONSTER HAS APPEARED!";
	dialogue(narrate);
	Sleep(1300);
	stats -> floor = 10;
	stats -> enemyHealth = 150;
	fightLoop(player,stats);
	system("cls");
	applause();
	Sleep(1800);
	cout << endl << "\t";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	narrate = "Thanks for playing our game!\n\n\tFrom the Developers of Brave Knight\n\n\t";
	dialogue(narrate);
	Sleep(1500);
	system("pause");
}
void floorLeveling(char player[255],Status *stats){
	if(stats -> floor == 1){
		firstLevel(player,stats);
	} else if(stats -> floor == 2){
		secondLevel(player,stats);
	} else if(stats -> floor == 3){
		thirdLevel(player,stats);
	} else if(stats -> floor == 4){
		fourthLevel(player,stats);
	} else if(stats -> floor == 5){
		fifthLevel(player,stats);
	} else if(stats -> floor == 6){
		sixthLevel(player,stats);
	} else if(stats -> floor == 7){
		seventhLevel(player,stats);
	} else if(stats -> floor == 8){
		eightLevel(player,stats);
	} else if(stats -> floor == 9){
		ninthLevel(player,stats);
	} else if(stats -> floor == 10){
		tenthLevel(player,stats);
	}
}
void monsterRandom(Status *stats){
	if(stats -> floor == 1){
		stats -> monsterDamage = rand() % 3 + 5;
	} else if(stats -> floor == 2){
		stats -> monsterDamage = rand() % 3 + 8;
	} else if(stats -> floor == 3){
		stats -> monsterDamage = rand() % 3 + 11;
	} else if(stats -> floor == 4){
		stats -> monsterDamage = rand() % 4 + 15;
	} else if(stats -> floor == 5){
		stats -> monsterDamage = rand() % 4 + 19;
	} else if(stats -> floor == 6){
		stats -> monsterDamage = rand() % 4 + 23;
	} else if(stats -> floor == 7){
		stats -> monsterDamage = rand() % 5 + 28;
	} else if(stats -> floor == 8){
		stats -> monsterDamage = rand() % 5 + 33;
	} else if(stats -> floor == 9){
		stats -> monsterDamage = rand() % 5 + 38;
	} else if(stats -> floor == 10){
		stats -> monsterDamage = rand() % 5 + 44;
	}
}
void knightRandom(Status *stats){
	if(stats -> floor == 1){
		stats -> knightSlash = rand() % 3 + 22;
	} else if(stats -> floor == 2){
		stats -> knightSlash = rand() % 3 + 25;
	} else if(stats -> floor == 3){
		stats -> knightSlash = rand() % 3 + 28;
	} else if(stats -> floor == 4){
		stats -> knightSlash = rand() % 4 + 31;
	} else if(stats -> floor == 5){
		stats -> knightSlash = rand() % 4 + 34;
	} else if(stats -> floor == 6){
		stats -> knightSlash = rand() % 5 + 37;
	} else if(stats -> floor == 7){
		stats -> knightSlash = rand() % 5 + 40;
	} else if(stats -> floor == 8){
		stats -> knightSlash = rand() % 6 + 43;
	} else if(stats -> floor == 9){
		stats -> knightSlash = rand() % 7 + 46;
	} else if(stats -> floor == 10){
		stats -> knightSlash = rand() % 7 + 49;
	}
}
void tower(){
	ifstream Reader("tower.txt");
	string tower = getFileContents(Reader);	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout << tower;
}
void defeat(){
	ifstream Reader("defeat.txt");
	string defeat = getFileContents(Reader);	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
	cout << defeat;
}
void applause(){
	ifstream Reader("applause.txt");
	string applause = getFileContents(Reader);	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
	cout << applause;
}
void defaultKnight(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("knightDef.txt");
	string knight = getFileContents(Reader);
	cout << knight;
}
void knightSlash(){
	ifstream Reader("knight_attack.txt");
	string attack = getFileContents(Reader);	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	cout << attack;
}
void level1(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level1.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level1Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level1_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level2(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level2.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level2Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level2_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level3(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level3.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level3Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level3_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level4(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level4.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level4Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level4_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level5(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level5.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level5Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level5_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level6(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level6.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level6Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level6_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level7(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level7.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level7Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level7_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level8(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level8.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level8Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level8_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level9(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level9.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level9Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level9_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level10(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
	ifstream Reader("level10.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void level10Dmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("level10_damaged.txt");
	string monster = getFileContents(Reader);
	cout << monster;
}
void knightDmg(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("knight_damage.txt");
	string dmg = getFileContents(Reader);
	cout << dmg;
}
void knightDmg1(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
	ifstream Reader("knight_damage1.txt");
	string dmg = getFileContents(Reader);
	cout << dmg;
}
void counterAttack(){
	ifstream Reader("knight_counterattack.txt");
	string counter = getFileContents(Reader);
	cout<<counter;
}
void Heal(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	ifstream Reader("knight_heal.txt");
	string heal = getFileContents(Reader);
	cout<<heal;
}
void Heal1(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	ifstream Reader("knight_heal2.txt");
	string heal = getFileContents(Reader);
	cout<<heal;
}
void Heal2(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
	ifstream Reader("knight_heal3.txt");
	string heal = getFileContents(Reader);
	cout<<heal;
}
void enrage(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	ifstream Reader("knight_enrage.txt");
	string enrage = getFileContents(Reader);
	cout<<enrage;	
}
void enrage1(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
	ifstream Reader("knight_enrage1.txt");
	string enrage = getFileContents(Reader);
	cout<<enrage;
}
void enrage2(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	ifstream Reader("knight_enrage2.txt");
	string enrage = getFileContents(Reader);
	cout<<enrage;
}
void monsterLevel(Status *stats){
	if(stats -> floor == 1){
		level1();
	} else if(stats -> floor == 2){
		level2();
	} else if(stats -> floor == 3){
		level3();
	} else if(stats -> floor == 4){
		level4();
	} else if(stats -> floor == 5){
		level5();
	} else if(stats -> floor == 6){
		level6();
	} else if(stats -> floor == 7){
		level7();
	} else if(stats -> floor == 8){
		level8();
	} else if(stats -> floor == 9){
		level9();
	} else if(stats -> floor == 10){
		level10();
	}
}
void monsterLevelDamage(Status *stats){
	if(stats -> floor == 1){
		level1Dmg();
	} else if(stats -> floor == 2){
		level2Dmg();
	} else if(stats -> floor == 3){
		level3Dmg();
	} else if(stats -> floor == 4){
		level4Dmg();
	} else if(stats -> floor == 5){
		level5Dmg();
	} else if(stats -> floor == 6){
		level6Dmg();
	} else if(stats -> floor == 7){
		level7Dmg();
	} else if(stats -> floor == 8){
		level8Dmg();
	} else if(stats -> floor == 9){
		level9Dmg();
	} else if(stats -> floor == 10){
		level10Dmg();
	}
} 
void ConsoleWindow(short x, short y, short cx, short cy){
	HWND consoleWindow = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(consoleWindow, &ConsoleRect);
	MoveWindow(consoleWindow,x,y,cx,cy, TRUE);
}
std::string getFileContents (std::ifstream& File){
    std::string Lines = "";       
    if (File){
	while (File.good ()){
	    std::string TempLine;                
	    std::getline (File , TempLine);       
	    TempLine += "\n";                      
	    Lines += TempLine;                  
	}	return Lines;
	} else{
		return "ERROR File does not exist.";
    }
}
