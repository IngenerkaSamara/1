
#include "TXLib.h"
void drawVictory(int xV, int yV)
{
        txSelectFont("Comic Sans MS", 20);
        txSetFillColour(TX_GREEN);
        txSetColour(TX_RED);
        txRectangle(xV, yV, 100 + xV, 100 + yV);
        txSetColour(TX_RED, 2);
        txDrawText(xV , yV , xV + 100, yV + 100, "Победить");

}

void drawPricel()
{
        txSetFillColour(TX_TRANSPARENT);
        txSetColour(TX_BLACK, 10);
        txLine(0, 350, 1400, 350);
        txLine(700, 0, 700, 700);
        txCircle(700, 350, 40);
}

int checkBaekY(int backgroundY)
{
        if (backgroundY < -2300)
        backgroundY = -2300;

        if (backgroundY > 0)
        backgroundY = 0;

        return backgroundY;
}

int checkBaekX(int backgroundX)
{
        if (backgroundX < -4600)
        backgroundX = -4600;

        if (backgroundX > 0)
        backgroundX = 0;

        return backgroundX;
}

struct Men
{
    int x;
    int y;
    int vishin;
    HDC picMen;
    int kadr;
    int timer;
};

void MenVishin(Men men, int backgroundX, int backgroundY)
{
    if (men.vishin == 1)
    {
        txTransparentBlt (txDC(), men.x + backgroundX, men.y + backgroundY,
                          42, 176, men.picMen, 0, 0, TX_WHITE);
    }

    if (men.vishin == 0)
    {
        txTransparentBlt (txDC(), men.x + backgroundX, men.y + backgroundY,
                          42, 176, men.picMen, 50 * men.kadr, 0, TX_WHITE);
    }
}

void menKilled(Men* men1, int backgroundX, int backgroundY, int *kill, int Idea, int *timep)
{
    if (GetAsyncKeyState(txMouseButtons()) && men1->x + backgroundX >  650 && men1->x + backgroundX < 700 &&
        men1->y + backgroundY > 200 && men1->y + backgroundY < 340 && men1->vishin == 1 && *timep == 0 || Idea == 1)
    {
        *kill = *kill + 1;

        men1->vishin = 0;
    }

    if (men1->vishin == 0)
    {
        men1->kadr = men1->kadr + 1;
        if (men1->kadr > 7)
            men1->kadr = 0;
    }
}


int main()
{
    txCreateWindow (1400, 700);

    int xM1R2 = 1; int yM1R2 = 1;
    int xM2R2 = 1; int yM2R2 = 1;
    int xM3R2 = 1; int yM3R2 = 1;

    int xM1R3 = 1; int yM1R3 = 1;
    int xM2R3 = 1; int yM2R3 = 1;
    int xM3R3 = 1; int yM3R3 = 1;

    Men men[3];
    men[0] ={random (1305, 1400), random (1405, 1500), 1, txLoadImage("men.bmp"), 0, 0};
    men[1] ={random (1555, 1600), random (1155, 1255), 1, men[0].picMen, 0, 0};
    men[2] ={random (4000, 4100), random (2200, 2100), 1, men[0].picMen, 0, 0};


    int timep = 40;
    int Idea = 0;
    int level = 1;
    int kill = 0;
    int backgroundX = 1000;
    int backgroundY = 1000;
    int Round = 1;
    COLORREF color = TX_BLUE;
    COLORREF color2 = TX_RED;

    //ФОн
    HDC pic[3];
    pic[0] = txLoadImage("база.bmp");
    pic[1] = txLoadImage("база 2.bmp");
    pic[2] = txLoadImage("база 3.bmp");

    HDC picMenu = txLoadImage("Меню.bmp");
    HDC picMenu2 = txLoadImage("Меню2.bmp");
    int xV = 1300;
    int yV = 0;
    int music = 1;
    int menu = 1;

    int Start = 0;
    while (Start != 1)
    {
      if (music == 1)
      {
          txTransparentBlt (txDC(), 0, 0,          1400, 700, picMenu, 0, 0, TX_WHITE);
          menu = 1;
      }

      if (music == 0)
      {
          txTransparentBlt (txDC(), 0, 0,          1400, 700, picMenu2, 0, 0, TX_WHITE);
          menu = 2;
      }


          if (txMouseX() > 1318 && txMouseX() < 1400 &&
              txMouseY() > 0 && txMouseY()< 83 &&
              txMouseButtons() == 1 && menu == 1)
          {
           menu = 2;
           music = 0;
          }

          if (txMouseX() > 1318 && txMouseX() < 1400 &&
              txMouseY() > 0 && txMouseY()< 83 &&
              txMouseButtons() == 1 && menu == 2)
          {
           menu = 1;
           music = 1;
          }


          if (txMouseX() > 468 && txMouseX() < 762 &&
              txMouseY() > 290 && txMouseY()< 375 &&
              txMouseButtons() == 1)
          {
          Start = 1;
          }

          txSleep (20);
    }

    int zastavka = 600;
    while (!GetAsyncKeyState(VK_SPACE))
    {
    txBegin();
    txSetFillColor(TX_BLACK);
    txRectangle(0, 0, 1400, 800);
    txSetColor(TX_WHITE);

    xM1R2 = random (905, 1900);  yM1R2 =  random (1005, 2005);
    xM2R2 = random (4055, 5055);  yM2R2 = random (555, 1555);
    xM3R2 = random (3000, 4000);  yM3R2 = random (750, 1750);

    xM1R3 = random (750, 5200);    yM1R3 = random (750, 2650);
    xM2R3 = random (750, 5200);    yM2R3 = random (750, 2650);
    xM3R3 = random (750, 5200);    yM3R3 = random (750, 2650);

    txSelectFont("Comic Sans MS", 30);
    txDrawText(10, 10, 450, 100, "Нажмите ''пробел'' чтобы пропустить");
    txSetColor(TX_RED);
    txSelectFont("Comic Sans MS", 150);
    txDrawText(0, zastavka, 1400, zastavka + 2600, "Внимание!!!"
                                   "\n"
                                   "\n"
                                   "Ваша задача убить"
                                   "\n"
                                   "несколько опасных"
                                   "\n"
                                   "солдат"
                                   "\n"
                                   "\n"
                                   "видимость будет"
                                   "\n"
                                   "почти нулевая"
                                   "\n"
                                   "\n"
                                   "\n"
                                   "!НО!"
                                   "\n"
                                   "с помощью нашего"
                                   "\n"
                                   "дорогущего оборудования"
                                   "\n"
                                   "вы сможете увидеть"
                                   "\n"
                                   "цель в хорошем качестве"
                                   "\n"
                                   "\n"
                                   "Удачи!"
                                   );

        txSleep(20);
        zastavka = zastavka - 15;
        txEnd();
       }




        if (music == 1)
        {
        txPlaySound("Звёздные войны.wav", SND_LOOP);
        }
    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txBegin();
        txSetFillColour(TX_BLACK);
        txClear();


        Win32::TransparentBlt (txDC(), backgroundX, backgroundY,
                          6000, 3000, pic[level-1],
                          0, 0, 6000, 3000, 0);


        timep = timep - 1;
        if (timep < 0)
        timep = 0;

            txSelectFont("Comic Sans MS", 50);
            char stroka[50];
            sprintf(stroka, "перезарядка %d", timep);
            txDrawText(1100, 600, 1400, 700, stroka);

        for (int i = 0; i < 3; i++)
        {
            MenVishin(men[0], backgroundX, backgroundY);
            menKilled(&men[0], backgroundX, backgroundY, &kill, Idea, &timep);
        }

        if (txMouseButtons() && timep < 1)
        {
        timep = 40;
        if (music == 1)
        {
        txPlaySound("Bam.wav");
        }
        }

        if (timep == 25 && music == 1)
        txPlaySound("Звёздные войны.wav", SND_LOOP);

        backgroundX = backgroundX - txMouseX() + 700;
        backgroundY = backgroundY - txMouseY() + 350;

        drawVictory(xV, yV);

        if (xV == 1300 && yV == 0 &&
            txMouseX() > 1300 &&
            txMouseX() < 1400 &&
            txMouseY() > 0 &&
            txMouseY() < 100)
         {
         xV = 0;
         yV = 600;
         }

        if (xV == 0 && yV == 600 &&
            txMouseX() > 0 &&
            txMouseX() < 100 &&
            txMouseY() > 600 &&
            txMouseY() < 700)
         {
         xV = 1300;
         yV = 0;
         }

        backgroundX = checkBaekX(backgroundX);
        backgroundY = checkBaekY(backgroundY);
        drawPricel();

        if (kill <= 2)
        {
            txSelectFont("Comic Sans MS", 50);
            char stroka[20];
            sprintf(stroka, "Kill %d", kill);
            txDrawText(10, 10, 100, 100, stroka);
        }

        if (kill == 3)
        {
            kill = 0;


            if (Round == 1)
            {
                level = 2;
                men[0] ={xM1R2, yM1R2, 1, men[0].picMen, 0, 0};
                men[1] ={xM2R2, yM2R2, 1, men[0].picMen, 0, 0};
                men[2] ={xM3R2, yM3R2, 1, men[0].picMen, 0, 0};
                txSetColor(TX_RED);
                Win32::TransparentBlt (txDC(), backgroundX, backgroundY,
                              1400, 700, pic[level-1],
                              0, 0, 6000, 3245, 0);
                txSelectFont("Comic Sans MS", 200);
                txDrawText(10, 10, 1400, 700, "Уровень 2");
                txSleep(3000);
            }

            if (Round == 2)
            {
                level = 3;
                men[0] ={xM1R3, yM1R3, 1, men[0].picMen, 0, 0};
                men[1] ={xM2R3, yM2R3, 1, men[0].picMen, 0, 0};
                men[2] ={xM3R3, yM3R3, 1, men[0].picMen, 0, 0};
                txSetColor(TX_RED);
                txSelectFont("Comic Sans MS", 200);
                txDrawText(10, 10, 1400, 700, "Уровень 3");
                txSleep(3000);
            }

            if (Round >= 3)
            {
                men[0] ={random (0 - backgroundX, 1200 - backgroundX), random (0 - backgroundY, 500 - backgroundY), 1, men[0].picMen, 0, 0};
                men[1] ={random (0 - backgroundX, 1200 - backgroundX), random (0 - backgroundY, 500 - backgroundY), 1, men[0].picMen, 0, 0};
                men[2] ={random (0 - backgroundX, 1200 - backgroundX), random (0 - backgroundY, 500 - backgroundY), 1, men[0].picMen, 0, 0};

                while (!GetAsyncKeyState(VK_ESCAPE))
                {
                    level = 3;
                    txSetFillColor(TX_BLACK);
                    txSetColor(TX_BLACK);
                    txRectangle(0, 0, 1400, 700);

                    Idea = 1;

                    for (int i = 0; i < 3; i++)
                    {
                        MenVishin(men[i], backgroundX, backgroundY);
                        men[i].vishin = 0;

                        men[i].kadr = men[i].kadr + 1;
                        if (men[i].kadr > 7)
                            men[i].kadr = 0;
                    }

                    txSetColor(TX_RED);
                    txSelectFont("Comic Sans MS", 200);
                    txDrawText(10, 10, 1400, 700, "Победа!!!");

                    txSleep(10);
                }
            }
            Round = Round + 1;
        }

        txSleep(10);
        txEnd();


        if (GetAsyncKeyState('E'))
          {
          kill = kill + 3;
          }


    }


    txDeleteDC(pic);
    txDeleteDC(pic[1]);
    return 0;
}
