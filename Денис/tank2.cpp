#include "TXLib.h"

struct Tank
{
    int x;
    int y;
    HDC Pravo;
    HDC Levo;
    HDC Vniz;
    HDC Verx;
    HDC PravoVniz;
    HDC PravoVerx;
    HDC LevoVniz;
    HDC LevoVerx;
    HDC tank;
    int life;
};

void presledovanie(Tank t1, Tank* t2, int speed)
{

        if(t1.x > t2->x - 10)
            t2->x = t2->x + speed;

        if(t1.y > t2->y - 10)
            t2->y = t2->y + speed;

        if(t1.x < t2->x + 10)
            t2->x = t2->x - speed;

        if(t1.y < t2->y + 10)
            t2->y = t2->y - speed;
}

void stolknivenie(Tank* t1, Tank* t2)
{
    if (t1->x + 100 > t2->x &&
        t1->y + 75  > t2->y &&
        t1->x - 250 < t2->x + 50&&
        t1->y - 30  < t2->y + 50 &&
        t1->life > 0 &&
        t2->life > 0)
    {
        t1->life = t1->life - 1;
        t1->x = 0;
        t1->y = 0;

        t2->x = 1150;
        t2->y = 670;
    }
}

void drowTank(Tank t2)
{
    if (t2.life > 0)
    {
        if (t2.tank == t2.Levo)
            txTransparentBlt (txDC(), t2.x - 103, t2.y-42, 206, 86, t2.tank, 0, 0, TX_WHITE);
        else if (t2.tank == t2.Vniz || t2.tank == t2.Verx)
            txTransparentBlt (txDC(), t2.x-42, t2.y-103, 85, 206, t2.tank, 0, 0, TX_WHITE);
        else
            txTransparentBlt (txDC(), t2.x - 83, t2.y-83, 166, 166, t2.tank, 0, 0, TX_WHITE);

        txSetFillColor(TX_RED);
        txRectangle(t2.x - 83, t2.y-83, t2.x - 83 + 20 * t2.life, t2.y - 63);
    }
}

void tank2Dvizhenie(int *xTank2, int *yTank2)
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        *xTank2 = *xTank2 + 5;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        *xTank2 = *xTank2 - 5;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        *yTank2 = *yTank2 + 5;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        *yTank2 = *yTank2 - 5;
    }
}


void tank3Dvizhenie(int *xTank3, int *yTank3)
{
    if (GetAsyncKeyState(VK_RIGHT))
    {
        *xTank3 = *xTank3 + 6;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        *xTank3 = *xTank3 - 6;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        *yTank3 = *yTank3 + 6;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        *yTank3 = *yTank3 - 6;
    }
}
