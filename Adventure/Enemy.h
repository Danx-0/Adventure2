#pragma once
#include "Character.h"
class Enemy :
    public Character
{
private:
   

public:
    Enemy(std::string name, int l, int hp, int damage, int defence, int exp);
    Enemy();
    ~Enemy();
    void InitEnemy();
    void PrintEnemyStats();


};

//que se muera, 3 enemigos y otra cosa
//ir a internet y buscar raylib; es una libreria para hacer quien sabe que :V