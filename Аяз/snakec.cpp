#include "TXLib.h"

struct Hvost
{
    int x;
    int y;
    HDC picture;
};

    int checkBorder(int newX)
    {
        if (newX < 0)
        {
            newX = 0;
        }
        if (newX > 480)
        {
            newX = 480;
        }
        return newX;
    }



    void drawBody(int x, int y, HDC body)
    {
    txTransparentBlt (txDC(), x, y, 20, 20, body, 0 , 0 , RGB(255, 174, 201));
    }

    void drawFruit(int x1, int y1, HDC fruit)
    {
    txTransparentBlt (txDC(), x1, y1, 20, 20, fruit, 0 , 0 , RGB(255, 174, 201));
    }

    int main()
    {
    txCreateWindow (500, 500);
    // автоматическая рандомизация
    srand( time(0) );

    int speedX = 0;
    int speedY = 0;
    int bs = 0;
    int sc = 0;
    int x1 = 200;
    int y1 = 200;


    int newX = 0;
    int newY = 0;

     char str[100];
     //POINT hvost[10];
     int sum = 0;

    HDC  body0 = txLoadImage("Pics/body0.bmp" );
    HDC  body1 = txLoadImage("Pics/body1.bmp" );
    HDC  body2 = txLoadImage("Pics/body2.bmp" );
    HDC  body3 = txLoadImage("Pics/body3.bmp" );
    HDC  body4 = txLoadImage("Pics/body4.bmp" );
    HDC  body5 = txLoadImage("Pics/body5.bmp" );
    HDC  body6 = txLoadImage("Pics/body6.bmp" );

    HDC fruit = txLoadImage("Pics/fruit.bmp");

    Hvost hvost[100];
    int n_hvost = 1;

    hvost[0] = {0, 20, body0};
    hvost[1] = {0, 20, body1};
    hvost[2] = {0, 20, body2};
    hvost[3] = {0, 20, body3};
    hvost[4] = {0, 20, body4};
    hvost[5] = {0, 20, body5};
    hvost[6] = {0, 20, body6};

    HDC pics[7];
    pics[0] = body0;
    pics[1] = body1;
    pics[2] = body2;
    pics[3] = body3;
    pics[4] = body4;
    pics[5] = body5;
    pics[6] = body6;


    while(!GetAsyncKeyState(VK_SPACE))
    {
        txBegin();
        txClear();

        for (int nomer = 0; nomer < n_hvost; nomer++)
        {
            drawBody(hvost[nomer].x, hvost[nomer].y, hvost[nomer].picture);
        }

        //Где будет голова
        newX = hvost[0].x + speedX;
        newY = hvost[0].y + speedY;

        txSetColor(TX_BLACK);
        sprintf(str, "щот: %d", sc, n_hvost);
        txTextOut(100, 100, str);

        //Движемся на шаг вперед
        for (int nomer = n_hvost - 1; nomer >= 0; nomer--)
        {
            hvost[nomer + 1].x = hvost[nomer].x;
            hvost[nomer + 1].y = hvost[nomer].y;
            hvost[nomer + 1].picture = hvost[nomer].picture;
        }

        newX = checkBorder(newX);
        newY = checkBorder(newY);
        hvost[0] = {newX, newY, pics[random(7)]};


    {    //!fruit and eating
        drawFruit(x1, y1, fruit);
        if (newX < x1 + 20 &&
            newX > x1 - 20 &&
            newY < y1 + 20 &&
            newY > y1 - 20)
        {
            txPlaySound("Sounds/s0.wav");

            while ( newX < x1 + 20 &&
                    newX > x1 - 20 &&
                    newY < y1 + 20 &&
                    newY > y1 - 20)
            {
                x1 = 20 * random(0, 24);
                y1 = 20 * random(0, 24);

                x1 = round(x1/20) * 20;
                y1 = round(y1/20) * 20;
            }
            sc += 1;
            sum+= 1;
            n_hvost++;
        }
    }

    {    //!управление
        if (GetAsyncKeyState('W') ||
            GetAsyncKeyState(VK_UP))
        {
            speedY = -20;
            speedX =   0;
        }

        else if (GetAsyncKeyState('S'))
        {
            speedY =  20;
            speedX =   0;
        }

        else if (GetAsyncKeyState('D'))
        {
            speedY =   0;
            speedX =  20;
        }

        else if (GetAsyncKeyState('A'))
        {
            speedY =   0;
            speedX = -20;
        }
    }



    txEnd();
    txSleep(50);
    }



    return 0;
    }

