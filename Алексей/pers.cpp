#include "TXLib.h"

struct Pers
{
    HDC pic;
    int x;
    int y;
    bool visible;
};

void drawVrag(Pers vrag)
{
    if (vrag.visible)
        txTransparentBlt(txDC(),vrag.x,vrag.y,99,99,vrag.pic, 0, 0, TX_WHITE);
}

void drawStar(Pers stary)
{
    if(stary.visible)
        txTransparentBlt(txDC(),stary.x,stary.y,68,68,stary.pic, 0, 0, TX_WHITE);
}
