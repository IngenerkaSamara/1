#include "TXLib.h"
#include "pyla.cpp"
#include "tank2.cpp"


int checkWallX(int x)
{
    if (x > 800)
        x = 800;
    if (x < 0)
        x = 0;

    return x;
}

int main()
{
    txCreateWindow (1228, 720);

    //int pyla.x = 500;     int pyla.y = 500;
    //int PylaNapravl;
    //HDC Pyla = txLoadImage("Картинки/Пуля/Пуля влево.bmp");
    //bool vidnaPyla = false;

    Pyla pyla = {500, 500, 0, txLoadImage("Картинки/Пуля/Пуля влево.bmp"), false};


    HDC Pole = txLoadImage("поле.bmp");

   // int t2.x = 500;    int t2.y = 500;
    HDC tank2 = txLoadImage("Картинки/танк 3.bmp");
    HDC tank3 = txLoadImage("Картинки/танк 3 другой.bmp");


    Tank t2 = {500, 500, tank2, tank2, tank2, tank2, tank2, tank2, tank2, tank2, t2.Levo, 5};
    Tank t3 = {800, 500, tank3, tank3, tank3, tank3, tank3, tank3, tank3, tank3, t3.Levo, 5};
    Tank t1 = {20, 20, txLoadImage("Картинки/танк вправо.bmp"),
        txLoadImage("Картинки/танк влево.bmp"),
        txLoadImage("Картинки/танк вниз.bmp"),
        txLoadImage("Картинки/танк вверх.bmp"), tank2, tank2, tank2, tank2, t1.Levo, 10};

    //int t1.x = 20;    //int t1.y = 20;
    //HDC tankPravo = txLoadImage("Картинки/танк вправо.bmp");
    //HDC tankLevo = txLoadImage("Картинки/танк влево.bmp");
    //HDC tankVniz = txLoadImage("Картинки/танк вниз.bmp");
    //HDC tankVerx = txLoadImage("Картинки/танк вверх.bmp");
    HDC tankPravoVniz = txLoadImage("Картинки/танк вправо вниз.bmp");
    HDC tankPravoVerx = txLoadImage("Картинки/танк вправо вверх.bmp");
    HDC tankLevoVniz = txLoadImage("Картинки/танк влево вниз.bmp");
    HDC tankLevoVerx = txLoadImage("Картинки/танк влево вверх.bmp");
    HDC tank = t1.Levo;

    int life = 1;

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txSetFillColour(TX_BLACK);
        txClear();

        txBitBlt     (txDC(), 0, 0, 1228, 720, Pole);


        //Рисуем танк                            Hfpvths
        if (t1.tank == t1.Levo || t1.tank == t1.Pravo)
            txTransparentBlt (txDC(), t1.x - 103, t1.y-42, 206, 85, t1.tank, 0, 0, TX_WHITE);
        else if (t1.tank == t1.Vniz || t1.tank == t1.Verx)
            txTransparentBlt (txDC(), t1.x-42, t1.y-103, 85, 206, t1.tank, 0, 0, TX_WHITE);
        else //Диагональ
            txTransparentBlt (txDC(), t1.x-83, t1.y-83, 166, 166, t1.tank, 0, 0, TX_WHITE);


        drowTank(t1);
        drowTank(t2);
        drowTank(t3);



        if (pyla.vidna)
            txTransparentBlt (txDC(), pyla.x, pyla.y, 67, 67, pyla.picture, 0, 0, TX_WHITE);

        /*txSetFillColor(TX_RED);
        txRectangle(0,0,100,100);
        if (txMouseX() > 0 &&
            txMouseY() > 0 &&
            txMouseX() < 100 &&
            txMouseY() < 100 &&
            txMouseButtons() == 1)
        {
            t2.x = 1150;
            t2.y = 670;
        }*/
        //пуля летит//
        if (GetAsyncKeyState(VK_RETURN) && !pyla.vidna)
        {
            pyla.vidna = true;

            if (t1.tank == t1.Levo)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля влево.bmp");
                pyla.Napravl = 1;
                pyla.x = t1.x - 60;
                pyla.y = t1.y - 32;
            }
            if (t1.tank == t1.Pravo)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля вправо.bmp");
                pyla.Napravl = 2;
                pyla.x = t1.x - 2;
                pyla.y = t1.y - 35;
            }
            if (t1.tank == t1.Verx)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля вверх.bmp");
                pyla.Napravl = 3;
                pyla.x = t1.x - 35;
                pyla.y = t1.y - 65;
            }
            if (t1.tank == t1.Vniz)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля вниз.bmp");
                pyla.Napravl = 4;
                pyla.x = t1.x - 35;
                pyla.y = t1.y - 2;
            }
            if (t1.tank == tankPravoVniz)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля вправо вниз.bmp");
                pyla.Napravl = 5;
                pyla.x = t1.x + 35;
                pyla.y = t1.y + 35;
            }
            if (t1.tank == tankLevoVniz)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля влево вниз.bmp");
                pyla.Napravl = 6;
                pyla.x = t1.x - 35;
                pyla.y = t1.y + 35;
            }
            if (t1.tank == tankPravoVerx)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля вправо вверх.bmp");
                pyla.Napravl = 7;
                pyla.x = t1.x + 35;
                pyla.y = t1.y - 35;
            }
            if (t1.tank == tankLevoVerx)
            {
                pyla.picture = txLoadImage("Картинки/Пуля/пуля влево вверх.bmp");
                pyla.Napravl = 8;
                pyla.x = t1.x - 35;
                pyla.y = t1.y - 35;
            }
        }
        //скорость пули//
        movePyla(&pyla);


        /*if (GetAsyncKeyState('A'))
        {
            if (tank == tankPravoVniz)
            {
                tank = tankVniz;
                t1.y = t1.y + 10;
            }
            else if (tank == tankVniz)
            {
                t1.x = t1.x - 10;
                t1.y = t1.y + 10;
                tank = tankLevoVniz;
            }
            else if (tank == tankLevoVniz)
            {
                t1.x = t1.x - 10;
                tank = tankLevo;
            }
        } */

        if (GetAsyncKeyState('D') &&
            GetAsyncKeyState('S'))
        {
            t1.x = t1.x + 10;
            t1.y = t1.y + 10;
            t1.tank = tankPravoVniz;
        }
        else if (GetAsyncKeyState('W') &&
            GetAsyncKeyState('D'))
        {
            t1.x = t1.x + 10;
            t1.y = t1.y - 10;
            tank = tankPravoVerx;
        }
        else if (GetAsyncKeyState('W') &&
            GetAsyncKeyState('A'))
        {
            t1.x = t1.x - 10;
            t1.y = t1.y - 10;
            tank = tankLevoVerx;
        }
        else if (GetAsyncKeyState('S') &&
            GetAsyncKeyState('A'))
        {
            t1.x = t1.x - 10;
            t1.y = t1.y + 10;
            tank = tankLevoVniz;
        }
        else if (GetAsyncKeyState('D'))
        {
            t1.x = t1.x + 10;
            t1.tank = t1.Pravo;
        }
        else if (GetAsyncKeyState('A'))
        {
            t1.x = t1.x - 10;
            tank = t1.Levo;
        }
        else if (GetAsyncKeyState('S'))
        {
            t1.y = t1.y + 10;
            tank = t1.Vniz;
        }
        else if (GetAsyncKeyState('W'))
        {
            t1.y = t1.y - 10;
            tank = t1.Verx;
        }

        tank2Dvizhenie(&t2.x, &t2.y);
        tank3Dvizhenie(&t3.x, &t3.y);


        if (GetAsyncKeyState(VK_SPACE))
        {
            t1.x = t1.x - 10;
        }
        /*столкновение*/
        /*if (t1.x + 100 > t2.x)
            if (t1.y + 75 > t2.y)
                if (t1.x - 250 < t2.x + 50)
                    if (t1.y - 30 < t2.y + 50)
                    {
                        life = life - 1;
                        t1.x = 0;
                        t1.y = 0;

                        t2.x = 1150;
                        t2.y = 670;
                    }*/

        stolknivenie(&t1, &t3);
        stolknivenie(&t1, &t2);
        //stolknivenie(&pyla.vidna, &t2);
presledovanie(t1, &t2, 3);
presledovanie(t1, &t3, 14);
        /*
        if(t1.x > t2.x - 10)
            t2.x = t2.x + 3;

        if(t1.y > t2.y - 10)
            t2.y = t2.y + 3;

        if(t1.x < t2.x + 10)
            t2.x = t2.x - 3;

        if(t1.y < t2.y + 10)
            t2.y = t2.y - 3;



        if(t1.x > t3.x - 10)
            t3.x = t3.x + 3;

        if(t1.y > t3.y - 10)
            t3.y = t3.y + 3;

        if(t1.x < t3.x + 10)
            t3.x = t3.x - 3;

        if(t1.y < t3.y + 10)
            t3.y = t3.y - 3;
*/


        if (pyla.vidna &&
            pyla.x > t2.x - 80 &&
            pyla.y > t2.y - 80 &&
            pyla.x < t2.x + 80 &&
            pyla.y < t2.y + 80 )
        {
            t2.life = t2.life - 1;
            t2.x = 1150;
            t2.y = 670;
        }



        if (pyla.vidna &&
            pyla.x > t3.x - 80 &&
            pyla.y > t3.y - 80 &&
            pyla.x < t3.x + 80 &&
            pyla.y < t3.y + 80 )
        {
            t3.x = 1150;
            t3.y = 670;
        }


        if (t1.y < 0)
        {
            t1.y = 0;
        }
        if (t1.y > 720)
        {
            t1.y = 720;
        }
        if (t1.x < 0)
        {
            t1.x = 0;
        }
        if (t1.x > 1228)
        {
            t1.x = 1228;
        }

        if (t2.x < 0)
        {
            t2.x = 0;
        }
        if (t2.x + 50 > 1228)
        {
            t2.x = 1228 - 50;
        }
        if (t2.y < 0)
        {
            t2.y = 0;
        }
        if (t2.y + 50 > 720)
        {
            t2.y = 720 - 50;
        }

        txSleep(20);

    }

    return 0;
}
