#include "TXLib.h"
void fon()
{
    txSetColour(RGB(0, 0, 0));
    txSetFillColour(RGB(0, 0, 0));
    txRectangle(0, 0, 1400, 800);
}
void stena(int xStena1, int yStena1)
{
    txSetColour(RGB(382, 162, 685), 70);
    txSetFillColour(RGB(382, 162, 685));
    txLine(xStena1, yStena1 - 100, xStena1, yStena1 + 100);
}

void stena5(int xStena5, int yStena5)
{
    txSetColour(RGB(121, 96, 35), 70);
    txSetFillColour(RGB(121, 96, 35));
    txLine(xStena5, yStena5 - 100, xStena5, yStena5 + 100);
}
void stena6(int xStena6, int yStena6)
{
    txSetColour(TX_WHITE, 70);
    txSetFillColour(TX_WHITE);
    txLine(xStena6 - 100, yStena6, xStena6 + 100, yStena6);
}

void dstena(int xStena8, int yStena8)
{
    txSetColour(TX_WHITE, 70);
    txSetFillColour(TX_WHITE);
    txCircle(xStena8, yStena8, 80);
}
void mai(int xMai, int yMai)
{
    txSetColour(TX_ORANGE);
    txSetFillColour(TX_ORANGE);
    txCircle(xMai, yMai, 15);
}

