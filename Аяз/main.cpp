#include "TXLib.h"
//#include  "catch.cpp"
//#include "snake.cpp"

struct Button
{
    int x;
    int y;
    int kadr;
    HDC pic;
};


int main()
{
    txCreateWindow(1200, 800);

    int menutime = 0;


    Button menu = {0, 0, 0, txLoadImage("Pics/Меню.bmp")};
    Button pause = {10, 10, 0, txLoadImage("Pics/Пауза.bmp")};



     int x_Settings = 390;
      int y_Settings = 340;
     HDC  Settings = txLoadImage("Pics/Шестерёнка.bmp");

      int x_Playg = 387;
      int y_Playg = 187;
     HDC  Playg = txLoadImage("Pics/Плейg.bmp");

     int x_Playsc = 387;
      int y_Playsc = 37;
     HDC  Playsc = txLoadImage("Pics/Плейsc.bmp");

     int x_Playsh = 387;
      int y_Playsh = 340;
     HDC  Playsh = txLoadImage("Pics/Плейsh.bmp");

       int x_Leave = 355;
      int y_Leave = 480;
     HDC  Leave = txLoadImage("Pics/Дверь.bmp");

     bool Menu = true;


    while (!GetAsyncKeyState(VK_ESCAPE)&&(menutime < 1))
    {
        txBegin();
        txClear();

        if(Menu)
        {
            txTransparentBlt (txDC(), menu.x, menu.y, 1200, 824, menu.pic, 1200 * menu.kadr,  0, RGB(255, 127, 39));


            if (txMouseX() >=430   &&
            txMouseY() >=50  &&
            txMouseX() <=816 &&
            txMouseY() <=140&&
            Menu == true)
            {
            txTransparentBlt (txDC(), x_Playsc , y_Playsc , 448, 132, Playsc, 0,  0, RGB(255, 127, 39));
            }


            if (txMouseX() >=430   &&
            txMouseY() >=200  &&
            txMouseX() <=816 &&
            txMouseY() <=304&&
            Menu == true)
            {
            txTransparentBlt (txDC(), x_Playg , y_Playg , 448, 132, Playg, 0,  0, RGB(255, 127, 39));
            }

            if (txMouseX() >=430   &&
            txMouseY() >=350  &&
            txMouseX() <=816 &&
            txMouseY() <=450&&
            Menu == true)
            {
            txTransparentBlt (txDC(), x_Playsh , y_Playsh , 448, 132, Playsh, 0,  0, RGB(255, 127, 39));
            }

            if (txMouseX() >=418   &&
            txMouseY() >=490 &&
            txMouseX() <=816 &&
            txMouseY() <=590&&
            Menu == true)
            {
            txTransparentBlt (txDC(), x_Leave , y_Leave , 468, 140, Leave, 0,  0, RGB(255, 127, 39));
            }

            if (txMouseX() >=430   &&
            txMouseY() >=50  &&
            txMouseX() <=816 &&
            txMouseY() <=150&&
            txMouseButtons () ==1&&
            Menu == true)
            {
            txPlaySound("Sounds/2.wav", SND_ASYNC);
            Menu=false;
            system("start snakec.exe");
            }

            if (txMouseX() >=430   &&
            txMouseY() >=200  &&
            txMouseX() <=816 &&
            txMouseY() <=304&&
            txMouseButtons () ==1&&
            Menu == true)
            {
            txPlaySound("Sounds/2.wav", SND_ASYNC);
            Menu=false;
            txPlaySound("Sounds/comeon.wav", SND_ASYNC);
            system("start catch.exe");
            }

            if (txMouseX() >=430   &&
            txMouseY() >=350  &&
            txMouseX() <=816 &&
            txMouseY() <=450&&
            txMouseButtons () ==1&&
            Menu == true)
            {
            txPlaySound("Sounds/2.wav", SND_ASYNC);
            Menu=false;
            system("start index.html");
            }

            if (txMouseX() >=430   &&
            txMouseY() >=490  &&
            txMouseX() <=816 &&
            txMouseY() <=590&&
            txMouseButtons () ==1&&
            Menu == true)
            {
            txPlaySound("Sounds/2.wav", SND_ASYNC);
            menutime += 1;
            }


        } else {
            //Меню
            txSetFillColour(TX_BLACK);

            txTransparentBlt (txDC(), pause.x , pause.y , 74, 67, pause.pic, 73 * pause.kadr,  0, RGB(255, 127, 39));


            if(GetAsyncKeyState('P') && !Menu) {
                Menu = true;
            }

            if (txMouseX() >=pause.x &&            txMouseY() >=pause.y &&
                txMouseX() <=pause.x + 74 &&       txMouseY() <=pause.y + 67 &&
                !Menu) {
                pause.kadr = 1;
            } else {
                pause.kadr = 0;
            }

            if (txMouseX() >=pause.x &&            txMouseY() >=pause.y &&
                txMouseX() <=pause.x + 74 &&       txMouseY() <=pause.y + 67 &&
                txMouseButtons () == 1 && !Menu) {
                txPlaySound("Sounds/2.wav", SND_ASYNC);
                Menu = true;
            }

        }

        txSleep(20);
        txEnd();
    }

    return 0;
}
