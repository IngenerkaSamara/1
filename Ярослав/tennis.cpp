#include "TXLib.h"
void Ball(int xBall, int yBall)
{
    txSetColour(TX_GRAY);
    txSetFillColour(TX_GRAY);
    txCircle(xBall, yBall, 10);
}
void rocket1(int yRocket1)
{
    txSetColour(RGB(255, 255, 255));
    txSetFillColour(RGB(255, 255, 255));
    txRectangle(10, yRocket1, 20, yRocket1 + 100);
}
void rocket2(int yRocket2)
{
    txSetColour(RGB(254, 254, 254));
    txSetFillColour(RGB(254, 254, 254));
    txRectangle(1390, yRocket2, 1380, yRocket2 + 100);
}





