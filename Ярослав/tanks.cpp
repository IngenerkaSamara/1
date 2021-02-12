#include "TXLib.h"

const int NAPRAVLENIE_VVERH = 1;
const int NAPRAVLENIE_VNIZ = 2;

void tank(int xTankTrack1, int yTankTrack1, int xTankTrack2, int yTankTrack2, int napravlenieTank, HDC tankUp, HDC tankDown, HDC tankRight, HDC tankLeft)
{
    if(napravlenieTank == 1)
    {
        txTransparentBlt(txDC(), xTankTrack1, yTankTrack1, 36, 36, tankUp, 0, 0, TX_BLACK);
    }
    if(napravlenieTank == 2)
    {
        txTransparentBlt(txDC(), xTankTrack1, yTankTrack1, 36, 36, tankDown, 0, 0, TX_BLACK);
    }
    if(napravlenieTank == 3)
    {
        txTransparentBlt(txDC(), xTankTrack1, yTankTrack1, 36, 36, tankRight, 0, 0, TX_BLACK);
    }
    if(napravlenieTank == 4)
    {
        txTransparentBlt(txDC(), xTankTrack1, yTankTrack1, 36, 36, tankLeft, 0, 0, TX_BLACK);
    }
}
void snaradTank(int xSnaradTank, int ySnaradTank, HDC snaradUp, HDC snaradDown, HDC snaradRight, HDC snaradLeft, int skin)
{
    if(skin == 1)
    {
        txTransparentBlt(txDC(), xSnaradTank, ySnaradTank, 6, 12, snaradUp, 0, 0, TX_BLACK);
    }
    if(skin == 2)
    {
        txTransparentBlt(txDC(), xSnaradTank, ySnaradTank, 6, 12, snaradDown, 0, 0, TX_BLACK);
    }
    if(skin == 3)
    {
        txTransparentBlt(txDC(), xSnaradTank, ySnaradTank, 12, 6, snaradRight, 0, 0, TX_BLACK);
    }
    if(skin == 4)
    {
        txTransparentBlt(txDC(), xSnaradTank, ySnaradTank, 12, 6, snaradLeft, 0, 0, TX_BLACK);
    }
}
void tankVrag(int xTankVrag, int yTankVrag, int xTankVragTower, int yTankVragTower, int napravlenieVrag, HDC tankVragUp, HDC tankVragDown, HDC tankVragRight, HDC tankVragLeft)
{
    if(napravlenieVrag == 1)
    {
        txTransparentBlt(txDC(), xTankVrag, yTankVrag, 36, 36, tankVragUp, 0, 0, TX_BLACK);
    }
    if(napravlenieVrag == 2)
    {
        txTransparentBlt(txDC(), xTankVrag, yTankVrag, 36, 36, tankVragDown, 0, 0, TX_BLACK);
    }
    if(napravlenieVrag == 3)
    {
        txTransparentBlt(txDC(), xTankVrag, yTankVrag, 36, 36, tankVragRight, 0, 0, TX_BLACK);
    }
    if(napravlenieVrag == 4)
    {
        txTransparentBlt(txDC(), xTankVrag, yTankVrag, 36, 36, tankVragLeft, 0, 0, TX_BLACK);
    }
}
void snaradVragTank(int xSnaradTankVrag, int ySnaradTankVrag, int napravlenieTankVrag, HDC snaradVragUp, HDC snaradVragDown, HDC snaradVragRight, HDC snaradVragLeft)
{
    if(napravlenieTankVrag == 1)
    {
        txTransparentBlt(txDC(), xSnaradTankVrag, ySnaradTankVrag, 6, 12, snaradVragUp, 0, 0, TX_BLACK);
    }
    if(napravlenieTankVrag == 2)
    {
        txTransparentBlt(txDC(), xSnaradTankVrag, ySnaradTankVrag, 6, 12, snaradVragDown, 0, 0, TX_BLACK);
    }
    if(napravlenieTankVrag == 3)
    {
        txTransparentBlt(txDC(), xSnaradTankVrag, ySnaradTankVrag, 12, 6, snaradVragRight, 0, 0, TX_BLACK);
    }
    if(napravlenieTankVrag == 4)
    {
        txTransparentBlt(txDC(), xSnaradTankVrag, ySnaradTankVrag, 12, 6, snaradVragLeft, 0, 0, TX_BLACK);
    }
}
void baze(HDC base)
{
    txTransparentBlt(txDC(), 775, 775, 48, 42, base, 0, 0, TX_BLACK);
}
void backend()
{
    txSetColour(RGB(209, 209, 209));
    txSetFillColour(RGB(209, 209, 209));
    txRectangle(0, 0, 488, 1000);
    txRectangle(1112, 0, 1600, 1000);
    txRectangle(0, 0, 1600, 188);
    txRectangle(0, 1000, 1600, 812);
}


