#pragma once
#include "Character.h"
#include <string>
#include <fstream>
class Player :
    public Character
{
private: 
    int strenght;
    int agility;
    int intelligence;
    int luck;
    int dexterity;

    int MaxXp;
    int skillPoints;

public:
    Player();
    ~Player();
    void InitPlayer(std::string name);
    void PrintPlayerStats();
    void LevelUp();
    void AddStats(int stat, int value);
    void UpdateValues();
    void LoadStats(const std::string& filename);
    std::string SaveStats();

    int GetLuck() { return luck; }
	void SetLuck(int l) { luck = l; }

    int GetStrenght() { return strenght; }
	void SetStrenght(int s) { strenght = s; }

	int GetAgility() { return agility; }    
	void SetAgility(int a) { agility = a; }

    int GetIntelligence() { return intelligence; }
	void SetIntelligence(int i) { intelligence = i; }

    int GetDexterity() { return dexterity; }
    void SetDexterity(int d) { dexterity = d; }

	int GetSkillPoints() { return skillPoints; }    
	void SetSkillPoints(int sp) { skillPoints = sp; }
};

