#include "TXLib.h"

struct Dragon
{
    int Dragonx;
    int y;
    int frameX;
    int frameY;
    int frame;
    int speed;
    int hpp;
    int posL;
    int posR;
    HDC picture;
    HDC hp;
    HDC hpEmpty;

    void draw(int objcam)
    {
        txTransparentBlt (txDC(), Dragonx + objcam, y, 220, 148, picture, frameX * frame, frameY, TX_WHITE);
        //Полоса хп впагов
        txTransparentBlt (txDC(), Dragonx + objcam + 80, y - 30, 100, 27, hpEmpty, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), Dragonx + objcam + 80, y - 30, hpp /* * 100 / MAX_HP*/, 27, hp, 0, 0, TX_WHITE);

        char str1[100];
        sprintf(str1, "HP: %d", hpp);
        txTextOut(Dragonx + objcam + 85, y - 27, str1);
    }

    void Move(int objcam)
    {
        Dragonx = Dragonx + speed;

        if(Dragonx + objcam < posL + objcam)
        {
            speed = 15;
            frame = 0;
        }
        else if(Dragonx + objcam > posR + objcam)
        {
            speed = -15;
            frame = 1;
        }
    }
};
