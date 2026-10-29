#pragma once
#include "Character.h"
class Player :
    public Character
{
private: 
    int strenght;
    int agility;
    int intelligence;
    int luck;
    int dexterity;

public:
    Player();
    void InitPlayer(std::string name);
    void PrintPlayerStats();

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

