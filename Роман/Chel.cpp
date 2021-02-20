#include "TXLib.h"
void movex (HDC *man, HDC manLeft, HDC manRight, int *xMan, int *ym)
{
 if (GetAsyncKeyState ('A'))
        {
            *man = manLeft;
            *xMan = *xMan - 12;
            *ym = *ym + 80;
            if (*ym > 479)
                *ym = 0;
        }

        if (GetAsyncKeyState ('D'))
        {
            *man = manRight;
            *xMan = *xMan + 12;
            *ym = *ym + 80;
            if (*ym > 479)
                *ym = 0;
        }
 }

void moveY (int *vyMan, int *jump)
{
    if (GetAsyncKeyState ('W') && *vyMan <= 3 && *jump < 2)
    {
        *vyMan = 13;
        *jump = *jump + 1;
    }
}
