#pragma once
#include <iostream>

class Character
{
private :
	std::string name;
	int level;
	int hp;
	int exp;
	int damageMin;
	int damageMax;
	int defence;


protected:



public:
	Character();
	virtual ~Character();
	void InitCharacter(std::string N);
	void PrintStats();
	void TakeDamge(int d);
	const int DoDamage();
	bool IsAlive();

	//Gets
	std::string GetName() { return name; }
	int GetLevel() { return level; }
	int GetHP() { return hp; }
	int GetExp() { return exp; }
	int GetDamageMin() { return damageMin; }
	int GetDamageMax() { return damageMax; }
	int GetDefence() { return defence; }
	
	
	//Sets
	void SetName(std::string n) { name = n; }
	void SetLevel(int l) { level = l;}
	void SetHp(int h) { hp = h;}
	void SetExp(int e) { exp = e;}
	void SetDamageMin(int DM) { damageMin = DM;}
	void SetDamageMax(int DM) { damageMax = DM;}
	void SetDefence(int D) { defence = D;}

	void AddExp(int xp) { exp += xp; }

	void TakeDamage(int value);
	//int DoDamage();


};

