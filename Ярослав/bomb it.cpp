#include "TXLib.h"

void samolet(int xSamolet, int ySamolet)
{
    txSetColour(RGB(1, 1, 1), 5);
    txSetFillColour(TX_WHITE);
    POINT sam[4] =
    {
        {xSamolet - 5, ySamolet},
        {xSamolet, ySamolet - 10},
        {xSamolet + 50, ySamolet},
        {xSamolet, ySamolet + 10}
    };
    txPolygon (sam, 4);
}
void bomb(int xBomb, int yBomb, int positionSnaradSamolet)
{
    txSetColour(TX_GRAY);
    txSetFillColour(TX_GRAY);
    txCircle(xBomb, yBomb - positionSnaradSamolet, 6);
    txLine(xBomb + 4, yBomb, xBomb + 8, yBomb - 15);
    txLine(xBomb - 4, yBomb, xBomb - 8, yBomb - 15);
}
void boom(int xBoom, int yBoom)
{
    txSetColour(TX_RED);
    txSetFillColour(TX_RED);
    txCircle(xBoom, yBoom, 40);

    txSetColour(TX_ORANGE);
    txSetFillColour(TX_ORANGE);
    txCircle(xBoom, yBoom, 20);
}
void building1(int xBuilding1, int yBuilding1, HDC build1)
{
    txTransparentBlt(txDC(), xBuilding1, yBuilding1, 60, 100, build1, 0, 0, TX_WHITE);
}
void building2(int xBuilding2, int yBuilding2, HDC build2)
{
    txTransparentBlt(txDC(), xBuilding2, yBuilding2, 60, 150, build2, 0, 0, TX_WHITE);
}
void building3(int xBuilding3, int yBuilding3, HDC build3)
{
    txTransparentBlt(txDC(), xBuilding3, yBuilding3, 60, 200, build3, 0, 0, TX_WHITE);
}
