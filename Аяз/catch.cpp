/*!
 Итак. Суть игры: ты - dungeon master,
но billy хочет поймать тебя! Не дай ему это сделать!
*/
#include <stdio.h>
#include   <dos.h>
#include <conio.h>
#include <time.h>
#include "TXLib.h"

    struct Gachi
    {
        int x;
        int y;
        HDC photo;
    };

    void drawDeadscreen(HDC Deadscreen)
    {
    txTransparentBlt (txDC(), 0, 0, 1280, 720, Deadscreen, 0 , 0 , RGB(255, 174, 201));
    }

    void drawLife(HDC life1)
    {
    txTransparentBlt (txDC(), 1130, 670, 150, 50, life1, 0 , 0 , RGB(255, 174, 201));
    }

    void drawGuide()
    {
    txDrawText  (900, 600, 1200, 700, "чтобы выйти из этого gym заплати 300 bucks или нажми esc два раза \n");
    }

    void drawVan(int x, int y, HDC van)
    {
    txTransparentBlt (txDC(), x, y, 50, 50, van, 0 , 0 , RGB(255, 174, 201));
    }

    void drawBilly(int x, int y, HDC billy)
    {
    txTransparentBlt (txDC(), x, y, 50, 50, billy, 0 , 0 , RGB(255, 174, 201));
    }

    void drawCum(int x, int y, HDC cum)
    {
    txTransparentBlt (txDC(), x, y, 40, 40, cum, 0 , 0 , RGB(255, 174, 201));
    }

    int main()
    {
    txCreateWindow (1280, 720);
    HDC gym = txLoadImage("Pics/gym.bmp");
    srand(time(0));

    int deb = 0;
    int nedeb = 0;
    int score = 0;
    int life = 3;
    int speed = 15;
    int speed1 = 10;
    int x = 150, x1 = 450;//, x2 = random(50, 1200);
    int y = 350, y1 = 350;// y2 = random(50, 650);
    int sn = random(1, 3);
    const char* s = "a";
    char str[100];
    int xFon = 0;



    HDC Deadscreen = txLoadImage("Pics/deadscreen.bmp");
    HDC life3 = txLoadImage("Pics/life3.bmp");
    HDC life2 = txLoadImage("Pics/life2.bmp");
    HDC life1 = txLoadImage("Pics/life1.bmp");
    HDC billyRight = txLoadImage("Pics/billy1.bmp");
    HDC billyLeft = txLoadImage("Pics/billy.bmp");
    HDC billy = billyRight;
    HDC vanLeft = txLoadImage("Pics/van1.bmp");
    HDC vanRight = txLoadImage("Pics/van.bmp");
    HDC van = vanRight;
    HDC cum = txLoadImage("Pics/cum.bmp");
    HDC ad = txLoadImage("Pics/azino.bmp");

    Gachi Cum={random(50, 1200), random(50, 650), txLoadImage("Pics/cum.bmp")};
    //HDC billy = txLoadImage("Pics/billy.bmp");
    //HDC van = txLoadImage("Pics/van.bmp");
    while(!GetAsyncKeyState(VK_ESCAPE)&&(score < 20)&&(deb < 1)&&(nedeb < 3))
    {
        if (life == 0)
        {
            drawDeadscreen(Deadscreen);
            if (txMouseX() >=610   &&
                txMouseY() >=210  &&
                txMouseX() <=1200 &&
                txMouseY() <=690&&
                txMouseButtons () ==1)
            {
                    nedeb += 1;
                    txBitBlt (txDC(), 340, 160, 600, 400, ad, 0 , 0);
                    txSleep(5000);
                    life += 1;
            }

            if (txMouseX() >=200   &&
                txMouseY() >=256  &&
                txMouseX() <=456 &&
                txMouseY() <=410&&
                txMouseButtons () ==1)
                {
                  system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
                  deb += 1;
                }
        }

        else
        {

            txSetFillColor(RGB(0, 0, 0));
            txSetColor(RGB(255, 255, 255));
            txClear();
            txBitBlt (txDC(), xFon - 2560, 0, 2560, 719, gym);
            txBitBlt (txDC(), xFon, 0, 2560, 719, gym);
            txBitBlt (txDC(), xFon + 2560, 0, 2560, 719, gym);

            txBegin();
            drawGuide();
            /*{struct  time t;
            gettime(&t);
            printf("The current time is: %2d:%02d:%02d.%02d\n",
            t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
            }*/
            sprintf(str, "%d", score);//Writing car_x_coord value to str //!xD
            txTextOut(100, 100, str);
            //txDrawText  (1000, 100, 1200, 150, "баночек симена собрано - score  \n");
            txSetFillColor(RGB(255, 255, 255));
            drawVan(x, y, van);
            drawVan(x1, y1, billy);
            drawCum(Cum.x, Cum.y, cum);
            if (GetAsyncKeyState('W'))
            {
                  y = y - speed;

            }


            if (GetAsyncKeyState('S'))
            {
                y = y + speed;
            }


            if (GetAsyncKeyState('D'))
            {
                x = x + speed;
                 //drawVan = drawVan1;
                 van = vanRight;
            }


            if (GetAsyncKeyState('A'))
            {
                x = x - speed;
                 //drawVan = drawVan;
                 van = vanLeft;
            }


            {    //catch sounds
            srand(time(0));

            if (sn == 1)
            {
            s = "Sounds/s1.wav";
            }
            if (sn == 2)
            {
            s = "Sounds/s3.wav";
            }
            if (sn == 3)
            {
            s = "Sounds/s3.wav";
            }
            }


            {    //lifes
            if (life == 3)
            {
                drawLife(life3);
            }
            if (life == 2)
            {
                drawLife(life2);
            }
            if (life == 1)
            {
                drawLife(life1);
            }
            }


            {    //semen
            if (x < Cum.x + 50)
                if (x > Cum.x - 50)
                    if (y < Cum.y + 50)
                        if (y > Cum.y - 50)
                        {
                           score += 1;
                           speed += 1;
                           Cum.x = random(50, 1200);
                           Cum.y = random(50, 650);
                        }
             }


            {    //catching
            if (x < x1 + 30)
                if (x > x1 - 30)
                    if (y < y1 + 30)
                        if (y > y1 - 30)
                        {
                        sn = random(1, 3);
                            txPlaySound(s, SND_ASYNC);
                            life -= 1;
                            y +=    speed;
                            x += 20*speed;
                            if (x > 1270)
                            {
                                x = 1269;
                            }
                        }
            }


            {    //billy
            if (x > x1 - 5)
            {
              billy = billyLeft;
              x1+=speed1;
            }
            if (x < x1 + 5)
            {
              billy = billyRight;
              x1-=speed1;
            }
            if (y > y1 + 5)
            {
              y1+=speed1;
            }
            if (y < y1 - 5)
            {
              y1-=speed1;
            }
            }



            if (x < 0)
            {
                x = 0;
            }

            if (x > 1280)
            {
                x+=   150;
                xFon-=150;
            }


        }

        txEnd();
        txSleep(10);
    }


    return 0;
}

