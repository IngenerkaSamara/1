#include "TXLib.h"

struct Bullet
{
    int x;
    int y;
    int speed;
    bool visible;
    HDC picture;
};

/*
   int xBullet = 0;
   int yBullet = 0;
   int speedBullet = 0;
   bool visibleBullet = false;
   HDC Bullet = txLoadImage ("пуля.bmp");
*/

int checkWallX(int xMan)
{
    if (xMan > 1400 - 100)
        xMan = 1400 - 100;
    if (xMan < 0)
        xMan = 0;

    return xMan;
}

int checkWallY(int yMan)
{
    if (yMan > 900-100)
        yMan = 900-100;
    if(yMan < 0)
       yMan = 0;

    return yMan;
}

struct Enemy
{
    int x;
    int y;
    int kadr;
    int life;
    HDC picLeft;
    HDC picRight;
    HDC pic;
};

int main()
{
    txCreateWindow (1400, 800);


    //Enemy monster1 = {700, 500, 0, 3, ...}
    int monsterX = 700, monsterY = 500;
    int kadrMonster = 0;
    HDC monsterRight = txLoadImage("monsterRight.bmp");
    HDC monsterLeft = txLoadImage("monsterLeft.bmp");
    HDC monster = monsterLeft;
    int monsterLife = 3;







    HDC background = txLoadImage("bg.bmp");
    HDC bg2 = txLoadImage("bg2.bmp");
    HDC Heart = txLoadImage("heart.bmp");
    HDC oboima = txLoadImage("oboima.bmp");


    int life = 3;
    int xMan = 400, yMan = 700;
    int kadrMan = 0;
    HDC manRight = txLoadImage ("manRight.bmp");
    HDC manLeft = txLoadImage ("manLeft.bmp");
    HDC man = manRight;



    int speedBullet = 0;
    int n_bullet = 10;
    Bullet bullet1 = {0, 0, 0, false, txLoadImage ("пуля.bmp")};

   HDC pers1 = txLoadImage("pers1.bmp");
   HDC pers2 = txLoadImage("pers2.bmp");
   HDC pers;
   bool gameStart = false;
   while (!gameStart)
   {
       txBitBlt (txDC(), 0, 0, 2000, 14000, bg2);
       Win32::TransparentBlt (txDC(), 200, 500, 300, 300, pers1, 0, 0, 138, 140, TX_WHITE);
       //txTransparentBlt (txDC(), 250, 675, 138, 140, pers1, 0, 0, TX_WHITE);
       Win32::TransparentBlt (txDC(), 800, 500, 300, 300, pers2, 0, 0, 82, 90, TX_WHITE);
       txSleep(10);
       if(txMouseX() > 200 &&              txMouseY() > 500 &&
          txMouseX() < 700 &&              txMouseY() < 500 + 120 &&
          txMouseButtons() == 1)
       {
           gameStart = true; pers1 = pers1;
       }
   }



    while (!GetAsyncKeyState(VK_ESCAPE))
    {
         txBegin();
         txSetFillColor(TX_BLACK);
         txClear();
         txBitBlt(txDC(), 0, 0, 1400, 900, background);

         txTransparentBlt (txDC(), xMan, yMan, 125, 140, man, 125 * kadrMan, 0, TX_WHITE);

         if (monsterLife > 0)
            txTransparentBlt (txDC(), monsterX, monsterY, 100, 198, monster, 100 * kadrMonster, 0, TX_WHITE);
         //txTransparentBlt (txDC(), 1235, 50, 100, 150, oboima, 0, TX_BLACK);


         txSetFillColor(TX_YELLOW);
         txSetColor(TX_BLACK);
         txRectangle(500, 100, 500 + n_bullet * 10, 150 );
         txSetColor(TX_BLACK, 6);
         txLine(500, 150, 500, 100);
         txLine(500, 100, 600, 100);
         txLine(600, 100, 600, 150);
         txLine(600, 150, 500, 150);

         if(yMan < 600)
         {
             yMan = 600;
         }

         if(yMan > 700)
         {
             yMan = 700;
         }

        //Вывод жизней на экран
        int nomer = 0;
        while (nomer < life)
        {
            txTransparentBlt (txDC(), 65 + 30 * nomer, 60, 100, 120, Heart, 0, 0, TX_WHITE);
            nomer = nomer + 1;
        }

         if(bullet1.visible)
         {
            txTransparentBlt (txDC(), bullet1.x, bullet1.y, 13, 5, bullet1.picture, 0, 0, TX_BLACK);
            bullet1.x = bullet1.x + speedBullet;
         }



         xMan = checkWallX(xMan);
         yMan = checkWallY(yMan);
         monsterX = checkWallX(monsterX);
         monsterY = checkWallY(monsterY);



         if(xMan + 100  > monsterX &&
            xMan        < monsterX + 260 &&
            yMan + 240  > monsterY &&
            yMan        < monsterY + 140 &&
            monsterLife > 0)
         {
             life = life - 1;
             xMan = 100;
             monsterX = monsterX + 300;
         }




        if (monsterX + 260  > bullet1.x &&
            monsterX        < bullet1.x + 13 &&
            monsterY + 140  > bullet1.y &&
            monsterY        < bullet1.y + 5 &&
            bullet1.visible &&
            monsterLife > 0)
        {
            bullet1.visible = false;
            monsterLife = monsterLife - 1;
            monsterX = monsterX + 300;
        }



         if (GetAsyncKeyState('D'))
         {
             xMan = xMan + 50;
             kadrMan = kadrMan + 1;
             man = manRight;
         }

         if (GetAsyncKeyState('A'))
         {
             xMan = xMan - 50;
             kadrMan = kadrMan + 1;
             man = manLeft;
         }

         if (kadrMan >= 3)
             kadrMan = 0;

         if (GetAsyncKeyState('W'))
         {
             yMan = yMan - 30;
         }

         if (GetAsyncKeyState('S'))
         {
             yMan = yMan + 30;
         }

         if (monsterX > xMan + 20)//GetAsyncKeyState(VK_LEFT))
         {
             monster = monsterLeft;
             monsterX = monsterX - 10;
             kadrMonster = kadrMonster + 1;
         }

         if (monsterX < xMan - 20)//if (GetAsyncKeyState(VK_RIGHT))
         {
             monster = monsterRight;
             monsterX = monsterX + 10;
             kadrMonster = kadrMonster + 1;
         }

         if (monsterY < yMan - 20)//if (GetAsyncKeyState(VK_RIGHT))
         {
            // monster = monsterRight;
             monsterY = monsterY + 10;
             kadrMonster = kadrMonster + 1;
         }


         if (monsterY > yMan + 20)//if (GetAsyncKeyState(VK_RIGHT))
         {
             //monster = monsterRight;
             monsterY = monsterY - 10;
             kadrMonster = kadrMonster + 1;
         }


         if(kadrMonster >= 8)
            kadrMonster = 0;

         if (GetAsyncKeyState(VK_UP))
         {
             monsterY = monsterY - 30;
         }

         if (GetAsyncKeyState(VK_DOWN))
         {
             monsterY = monsterY + 30;
         }



         if (txMouseButtons() == 1 && bullet1.visible == false && n_bullet > 0)
         {
            bullet1.visible = true;
            n_bullet = n_bullet - 1;





            if (man == manLeft)
            {
                speedBullet = -40;

                bullet1.y = yMan + 70;
                bullet1.x = xMan - 8;
            }

            if(man == manRight)
            {
               speedBullet = 40;

                bullet1.y = yMan + 70;
                bullet1.x = xMan + 100;
            }
         }


        if (bullet1.x > 1400 || bullet1.x < -10)
            bullet1.visible = false;

        //Финиш уровня
        if (xMan > 1100)
        {
            xMan = 100;
            n_bullet = 20;
            monsterLife = 8;
            monsterX = 1200;
            background = bg2;
        }




        txSleep(10);
        txEnd();
   }
      txDeleteDC (background);
      txDeleteDC (man);
      txDeleteDC (monster);
      txDeleteDC (bullet1.picture);
      txDeleteDC (oboima);
    return 0;

}


