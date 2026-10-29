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
    int skillsPoints;

public:
    Player();
    void InitPlayer(std::string name);
    void PrintPlayerStats();
    void LevelUp();
    void AddStats(int stat, int value);
    void UpdateValues();
    void LoadStats(const std::string& filename);
    std::string SaveStats();

    int GetLuck();
    void SetLuck(int x);

    int GetStrenght();
    void SetStrenght(int s);

    int GetAgility();
    void SetAgility(int a);

    int GetIntelligence();
    void SetIntelligence(int w);

    int GetDexterity();
    void SetDexterity(int r);

   
    ~Player();
};

