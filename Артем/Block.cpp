#include "TXLib.h"

struct Block
{
    int x;
    int y;
    int width;
    int height;
    HDC picture;

    void draw(int objcam)
    {
        txTransparentBlt (txDC(), x + objcam, y, width, height, picture, 0, 0, TX_WHITE);
    }
};
void blockCollision(int* heroX, int* heroY, int objcam, Block block1)
{
    if (*heroX      > block1.x + objcam - 140 &&
        *heroX + 40 < block1.x + objcam + block1.width &&
        *heroY      > block1.y - 413 &&
        *heroY      < block1.y)
    {
        if (*heroX      < block1.x + objcam - 120 &&
            *heroY      > block1.y - 400)
            *heroX = block1.x + objcam - 140 - 40;
        else if (*heroX > block1.x + objcam + 640 &&
            *heroY      > block1.y - 400)
            *heroX = block1.x + objcam + 640;
        else
            *heroY = block1.y - 413;
    }
}
