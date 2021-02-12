#include "TXLib.h"

void snake(int xSnake, int ySnake)
{
    txSetColour(TX_NULL);
    txSetFillColour(TX_GREEN);
    txRectangle(xSnake, ySnake, xSnake + 20, ySnake + 20);
}

void eda(int xe, int ye)
{
    txSetColour(TX_RED);
    txSetFillColour(TX_RED);
    txRectangle(xe, ye, xe + 15, ye + 15);
}
