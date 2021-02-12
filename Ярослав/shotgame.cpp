#include "txLib.h"

struct VragShooterMan
{
    int x;
    int y;
    int napravlenie;
};


void drawShooterMan(VragShooterMan man, int destroyVragShooter)
{
    if(destroyVragShooter == 0)
    {
    txSetColour(TX_BLACK, 10);
    txSetFillColour(RGB(254, 254, 254));
    txCircle(man.x, man.y, 50);
    }
}

void wallCollisionShooterMan(VragShooterMan* shooterVrag1)
{
    if (shooterVrag1->x >= 1600)
    {
        shooterVrag1->x = 10;
    }
    if (shooterVrag1->x <= 0)
    {
        shooterVrag1->x = 1590;
    }
}

void ShooterMan(int xShooterMan, int yShooterMan)
{
    txSetColour(TX_BLACK, 10);
    txSetFillColour(TX_WHITE);
    txCircle(xShooterMan, yShooterMan, 50);
}

void gun(int xGun1, int yGun1, int yGun12, int xGun2, int yGun2, int yGun2Hatchet, int napravlenieShooterMan, int Gun)
{
    txSetColour(TX_BLACK, 10);
    txSetFillColour(TX_BLACK);

    if(Gun == 1)
    {
        if(napravlenieShooterMan == 1)
        {
            txLine(xGun1, yGun1, xGun1 + 50, yGun12);
        }
        if(napravlenieShooterMan == 2)
        {
            txLine(xGun1, yGun1, xGun1 - 50, yGun12);
        }
    }
    if(Gun == 2)
    {
        if(napravlenieShooterMan == 1)
        {
            txLine(xGun2, yGun2, xGun2 + 70, yGun2Hatchet - 50);
            txCircle(xGun2 + 80, yGun2Hatchet - 40, 20);
        }
        if(napravlenieShooterMan == 2)
        {
            txLine(xGun2, yGun2, xGun2 - 70, yGun2Hatchet - 50);
            txCircle(xGun2 - 80, yGun2Hatchet - 40, 20);
        }
    }


}
void snaradGun1(int xSnaradGun1, int ySnaradGun1)
{
    txSetColour(TX_BLACK);
    txSetFillColour(TX_BLACK);
    txCircle(xSnaradGun1, ySnaradGun1, 5);
}
void vragShooter(int xVragShooter, int yVragShooter)
{
    txSetColour(TX_BLACK, 10);
    txSetFillColour(TX_WHITE);
    txCircle(xVragShooter, yVragShooter, 50);
}

