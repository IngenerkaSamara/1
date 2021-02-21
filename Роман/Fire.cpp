#include "TXLib.h"

struct Fire
{
    int x;
    int y;
    int f;
    int coll;
    int v;

    HDC fireR;
    HDC fireL;
    HDC fire;
};

void drawFire (Fire fire1)
{
    if (fire1.f == 1)
        txTransparentBlt (txDC(), fire1.x, fire1.y,   19,   9, fire1.fire,  0, 0, TX_WHITE);
}
