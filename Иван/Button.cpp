#include "TXLib.h"

struct Button
{
    int x;
    int y;
    int x2;
    int y2;
    const char* text;
    HDC picture;
    HDC avatar;
    HDC avatarMini;
};

void drawButton(Button btn) {
    if(btn.text != ""){
        txDrawText(btn.x, btn.y, btn.x2, btn.y2, btn.text);
    }
    if (btn.picture != nullptr)
        txBitBlt(txDC(), btn.x, btn.y, btn.x2-btn.x, btn.y2 - btn.y, btn.picture);
}

bool clickButton(Button btn) {
    if (txMouseX() > btn.x && txMouseX() < btn.x2
        && txMouseY() > btn.y && txMouseY() < btn.y2
        && txMouseButtons() == 1) {
        return true;
    } else {
        return false;
    }
}
