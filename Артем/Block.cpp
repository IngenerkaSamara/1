#include "TXLib.h"

struct Block
{
    int x;
    int y;
    int width;
    int height;
    HDC picture;
};
struct Thorn
{
    int x;
    int y;
    HDC picture;
};
void drawBlock(Block block1, int objcam)
{
    txTransparentBlt (txDC(), block1.x + objcam, block1.y, block1.width, block1.height, block1.picture, 0, 0, TX_WHITE);
}
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
