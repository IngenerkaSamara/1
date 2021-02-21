#include "TXLib.h"

struct Monster
{
    int x;
    int y;
    int hp;
    HDC monsterA;
    HDC monsterD;
    HDC monster;
};

void drawMonster(Monster monster1)
{
    if (monster1.hp > 0)
        txTransparentBlt (txDC(), monster1.x, monster1.y,   92,  62, monster1.monster,  0, 0, TX_WHITE);
}
