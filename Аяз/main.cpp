#include "TXLib.h"
//#include  "catch.cpp"
//#include "snake.cpp"



    int main()
    {
    txCreateWindow(1200, 800);

        int menutime = 0;

     int x_Menu_ = 0;
      int y_Menu_ = 0;
      int x_kadr_Menu = 0;
     HDC  Menu_ = txLoadImage("Pics/Меню.bmp");

     int x_kadr_Pause = 0;
      int x_Pause = 10;
      int y_Pause = 10;
     HDC  Pause = txLoadImage("Pics/Пауза.bmp");

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


    txTransparentBlt (txDC(), x_Menu_, y_Menu_, 1200, 824, Menu_, 1200 * x_kadr_Menu,  0, RGB(255, 127, 39));


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


     }  else{
     //Меню
     txSetFillColour(TX_BLACK);

     txTransparentBlt (txDC(), x_Pause , y_Pause , 74, 67, Pause, 73 * x_kadr_Pause,  0, RGB(255, 127, 39));


     if(GetAsyncKeyState('P') && Menu == false)  {
     //txSleep(150);
     Menu = true; }

     if (txMouseX() >=10   &&
    txMouseY() >=10  &&
    txMouseX() <=83 &&
    txMouseY() <=77&&
    Menu == false){
    x_kadr_Pause = 1;}
    else{x_kadr_Pause = 0;}

     if (txMouseX() >=10   &&
    txMouseY() >=10  &&
    txMouseX() <=83 &&
    txMouseY() <=77&&
    txMouseButtons () ==1&&
    Menu == false){txPlaySound("Sounds/2.wav", SND_ASYNC);
    Menu = true;}







     }







    txSleep(20);
    txEnd();
    }

        return 0;
    }
