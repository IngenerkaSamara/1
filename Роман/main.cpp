#include "TXLib.h"
#include "Chel.cpp"

/*
for (int nomer = 0; nomer < 3; nomer = nomer + 1)
{
drawBottles(bottles[nomer].x, bottles[nomer].y);
moveBottles(x, y, &bottles[nomer], &points);
}
*/

const int PAGE_GAME = 2;
const int PAGE_MENU = 1;
//const int PAGE_CASTLE = 2;
//const int PAGE_NATURE = 3;

struct Monster
{
    int x;
    int y;
    int hp;
    HDC monsterA;
    HDC monsterD;
    HDC monster;
};

void drawMonster(Monster monster1)
{
    if (monster1.hp > 0)
        txTransparentBlt (txDC(), monster1.x, monster1.y,   92,  62, monster1.monster,  0, 0, TX_WHITE);
}

struct Bullet
{
    int v;
    int x;
    int y;
    int f;

    HDC bulL;
    HDC bulR;
    HDC bul;
};

struct Fire
{
    int x;
    int y;
    int f;
    int coll;
    int v;

    HDC fireR;
    HDC fireL;
    HDC fire;
};

void drawFire (Fire fire1)
{
    if (fire1.f == 1)
        txTransparentBlt (txDC(), fire1.x, fire1.y,   19,   9, fire1.fire,  0, 0, TX_WHITE);
}

void monsterBul (Bullet* bul1, Monster* monster1)
{
    if (monster1->hp > 0  &&
       (bul1->x > monster1->x &&
        bul1->x < monster1->x + 40) &&
       (bul1->y > monster1->y &&
        bul1->y < monster1->y + 92))
    {
        monster1->hp = 0;
        bul1->f = 0;
    }
}

void monsterFire (Fire* fire1, Monster* monster1)
{
    if (monster1->hp > 0)
    {
        fire1->x = fire1->x - fire1->v;
    }

    else
    {
        fire1->f = 0;
        fire1->coll = 0;
    }

        if (monster1->monster == monster1->monsterA && fire1->x < 0)
        {
            fire1->x = monster1->x ;
            fire1->coll = 1;
            fire1->f = 1;
        }

        if (monster1->monster == monster1->monsterD && fire1->x > 1150)
        {
            fire1->x = monster1->x + 80;
            fire1->coll = 1;
            fire1->f = 1;
        }
}

void manFire (Fire* fire1, int *hpman, int xMan, int yMan, int *texthpf, int *xtexthp, int *ytexthp)
{
        if ((fire1->x > xMan      &&
            fire1->x < xMan + 80) &&
           (fire1->y > yMan       &&
            fire1->y < yMan + 80) &&
            *hpman > 0          &&
            fire1->coll == 1)
            {
                *hpman = *hpman - 10;
                fire1->f = 0;
                fire1->coll = 0;
                *ytexthp = yMan - 20;
                *xtexthp = xMan + 20;
                *texthpf = 5;

            }
}

void manFireHp (int *texthpf, int *xtexthp, int *ytexthp)
{
            txSetColor (TX_WHITE, 5);
            *texthpf = *texthpf - 1;
            if (*texthpf > 0)
            {
                txTextOut(*xtexthp, *ytexthp, "-10");
                *ytexthp = *ytexthp - 3;
            }
}

void bulFly (Bullet* bul1, HDC manRight, HDC manLeft, HDC man, int xMan, int yMan)
{
    bul1->f = 1;
    bul1->x = xMan;
    bul1->y = yMan + 15;

    if (man == manRight)
    {
        bul1->v = 35;
        bul1->x = xMan + 30;
    }

    if (man == manLeft)
    {
        bul1->v = -35;
    }
}

int main()
{
    txCreateWindow (1150, 650);

    char str [100];
    char hp [100];

    int hpman = 100;

    int page = 1;

    int xres = 1050;
    int yres = 0;
    HDC restart = txLoadImage ("картинки/restart.bmp");

    int yl1 = 300;
    int yl2 = 430;
    HDC floor = txLoadImage ("картинки/gjk.bmp");

    HDC wall = txLoadImage ("картинки/wall.bmp");

    //int xmons = 900;
    //int ymons = 238;
    //int hpmons = 1;
    //int levelm = 1;
    HDC monsterA = txLoadImage ("картинки/monsterA.bmp");
    HDC monsterD = txLoadImage ("картинки/monsterD.bmp");
    Monster monster1 = {900, 238, 1, monsterA, monsterD, monsterA};
    Monster monster2 = {300, 368, 1, monsterA, monsterD, monsterD};         //   struct


    //int xfire = monster1.x;
    //int yfire = monster1.y + 25;
    //int firef = 1;
    //int vfire = 0;
    //int firecoll = 1;
    HDC fireL = txLoadImage ("картинки/fireball.bmp");
    HDC fireR = txLoadImage ("картинки/firebarr.bmp");
    Fire fire1 = {monster1.x, monster1.y + 25, 1, 1,  35, fireR, fireL, fireL};
    Fire fire2 = {monster2.x, monster2.y + 25, 1, 1, -35, fireR, fireL, fireR};                          //   struct


    int xMan = 300;
    int yMan = 225;

    int xManOld = 0;
    int yManOld = 0;

    int vyMan = 10;
    int xm = 2;
    int ym = 0;
    int levelp = 1;

    int xtexthp = 0;
    int ytexthp = 0;
    int texthpf = 0;

    int jump = 0;
    HDC manLeft = txLoadImage ("картинки/manL.bmp");
    HDC manRight = txLoadImage ("картинки/manR.bmp");
    HDC man = manRight;


    //int vbul = 0;
    //int xbul = xMan;
    //int ybul = 0;
    //int bulf = 0;

    int fireMode = 1;
    int bulDist = 0;
    HDC bulL = txLoadImage ("картинки/bulL.bmp");
    HDC bulR = txLoadImage ("картинки/bulR.bmp");
    //HDC bul = bulR;
    Bullet bul[3];
    bul[0] = {35, xMan, 0, 0, bulL, bulR, bulR};
    bul[1] = {35, xMan, 0, 0, bulL, bulR, bulR};
    bul[2] = {35, xMan, 0, 0, bulL, bulR, bulR};                                      // struct

    int xgo = 450;
    int ygo = 200;
    HDC gameover = txLoadImage ("картинки/gameover.bmp");


    while (!GetAsyncKeyState(VK_ESCAPE))
    {


        txBegin ();
        txSetFillColor (TX_WHITE);
        txClear();
        xManOld = xMan;
        yManOld = yMan;



        //Выбор уровня
        if (page == PAGE_MENU)
        {
            txSetFillColor (TX_WHITE);
            txRectangle (0, 0, 1150, 650);
            txSelectFont ("Comic Sans MS", 50);
            txSetColor (TX_BLACK);
            txTextOut (450, 200, "Выбрать уровень:");
            txTextOut (450, 300, "Замок");
            txTextOut (450, 400, "Природа");

            if (txMouseX() > 450 &&
                txMouseY() > 300 &&

                txMouseX() < 550 &&
                txMouseY() < 350 &&

                txMouseButtons() == 1)
            {
                page = PAGE_GAME;
            }

            if (txMouseX() > 450 &&
                txMouseY() > 400 &&

                txMouseX() < 550 &&
                txMouseY() < 450 &&

                txMouseButtons() == 1)
            {
                page = 3;
            }

        }

        //Игра
        if (page == PAGE_GAME)
        {
            txBitBlt (txDC(),    0,   0, 1150, 650,  wall);

            txRectangle(-500, yl1 + 2,  650, yl1 + 7);
            txRectangle( 850, yl1 + 2, 1150, yl1 + 7);
            txRectangle(   0, yl2 + 2, 1150, yl2 + 7);
            for (int nomer = 0; nomer < 3; nomer++)
            {
                if (bul[nomer].f > 0)
                    txTransparentBlt (txDC(),  bul[nomer].x,  bul[nomer].y, 26, 20, bul[nomer].bul, 0, 0, TX_BLACK);
            }

            if (hpman > 0)
                txTransparentBlt (txDC(),    xMan,    yMan,   80,  80,     man, xm,ym, TX_WHITE);
            txTransparentBlt     (txDC(),    xres,    yres,  100, 100, restart,  0, 0, TX_WHITE);
            drawMonster(monster1);
            drawMonster(monster2);
            drawFire (fire1);
            drawFire (fire2);

            txSetColor (TX_BLACK, 4);
            txSetFillColor (TX_RED);
            Win32::RoundRect (txDC(),30, 30, 30 + 200, 60, 25, 25);
            txSetFillColor (RGB(68,249,15));
            Win32::RoundRect (txDC(),30, 30, 30 + hpman * 2, 60, 25, 25);
            txSetFillColor (TX_TRANSPARENT);
            Win32::RoundRect (txDC(),30, 30, 30 + 200, 60, 25, 25);
            //Transparent


            //ВСЕ ФУНКЦИИ
            manFireHp (&texthpf, &xtexthp, &ytexthp);
            manFire (&fire1, &hpman, xMan, yMan, &texthpf, &texthpf, &ytexthp);

            for (int nomer = 0; nomer < 3; nomer++)
            {
                monsterBul (&bul[nomer], &monster1);
                monsterBul (&bul[nomer], &monster2);
            }
            monsterFire (&fire1,  &monster1);
            monsterFire (&fire2,  &monster2);
            movex (&man, manLeft, manRight, &xMan, &ym);
            moveY (&vyMan, &jump);
            //bulFly(&bul1, manRight, manLeft, &man, xMan, yMan);
            //bulFly(&bul2, manRight, manLeft, &man, xMan, yMan);

            yMan = yMan - vyMan;
            vyMan = vyMan - 1;
            if (vyMan < -10)
                vyMan = -10;

            //хп чувака выводятся
            txSetColor (TX_WHITE, 4);
            txSelectFont ("Comic Sans MS", 25, 10, 1000);
            sprintf(str, "%d / 100", hpman);
            txTextOut(90, 32.5, str);


            //режим стрельбы
            txSetColor (TX_WHITE, 5);


            if (txMouseX() > xgo + 149 && txMouseX() < xgo + 201 &&
                txMouseY() > ygo + 122 && txMouseY() < ygo + 174 &&
                txMouseButtons() == 1)
            {
                txSetFillColor (TX_BLACK);
                txRectangle (0, 0, 1150, 650);
                txSelectFont ("Arial", 650, 250, 0);
                txTextOut (0, 0, "ЗРЯ");
                txSleep (1000);
                return 0;
            }

            //Рестарт после смерти                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          я устал                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        1500 колонна зачем                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  2000 колонна бж                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         3000 хъ                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 4000                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    5000 короче я все
            if (hpman <= 0)
            {
                txTransparentBlt (txDC(),  xgo,  ygo,  254, 203, gameover,  0, 0, TX_WHITE);

                if (txMouseX() > xgo + 41  && txMouseX() < xgo + 92  &&          //вроде рестарт после смерти
                    txMouseY() > ygo + 120 && txMouseY() < ygo + 171 &&          //approved
                    txMouseButtons() == 1)
                {
                    levelp = 1;
                    xMan = 300;
                    yMan = 225;
                    //bul1.f = 0;
                    monster1.hp = 1;
                    monster2.hp = 1;
                    hpman = 100;
                    fire1.x = monster1.x;
                    fire2.x = monster2.x;
                }
            }





        if ((txMouseX() > xres      &&
        txMouseY() < 100       &&                 //а вот рестарт...
        txMouseButtons() == 1) ||                 //а они разделены
        GetAsyncKeyState ('R'))
        {
        levelp = 1;
        xMan = 300;
        yMan = 225;
        //bul1.f = 0;
        //bul2.f = 0;
        monster1.hp = 1;
        monster2.hp = 1;
        hpman = 100;
        fire1.x = monster1.x;
        fire2.x = monster2.x;
        }


        /*if (levelp == 1 && yMan > yl1 - 75 && (xMan < 650 || xMan > 770))
        {
            yMan = 225;
            vyMan = 0;
            jump = 0;
            levelp = 1;
        }

        if (yMan > yl1 - 75 && (xMan > 650 && xMan < 770))
        {
            levelp = 2;
        }

        if (yMan < yl1 - 75 && (xMan > 650 && xMan < 770))                      //денчик слазиет
        {
            levelp = 1;
        }

        if (levelp == 2 && yMan < yl1 + 8 && (xMan < 650 || xMan > 770))
        {
            yMan = yl1 + 8;
            vyMan = 0;
        }

        if (levelp == 2 && yMan > yl2 - 75)
        {
            yMan = yl2 - 75;
            vyMan = 0;
            jump = 0;
        }*/
         //Картинка пули


         if (txGetPixel (xMan + 20, yMan + 75) == TX_WHITE ||
             txGetPixel (     xMan,      yMan) == TX_WHITE)
         {
             //yMan = yManOld;
             jump = 0;
             vyMan = 0;
         }


        for (int nomer = 0; nomer < 3; nomer++)
        {
            bul[nomer].x = bul[nomer].x + bul[nomer].v;                                  //пуля летает
            if (bul[nomer].x > 1150  ||
                bul[nomer].x < 0)
            {
                bul[nomer].f = 0;
            }
        }

    if (GetAsyncKeyState('F'))
    {
        fireMode = fireMode + 1;
        txSleep (100);
    }

    if (fireMode > 2)
        fireMode = 1;

    if (fireMode == 1)
    {
        txTextOut (100, 150, "одиночный");

        if (GetAsyncKeyState (VK_SPACE))
        {
            bulFly (&bul[0], manRight, manLeft, man, xMan, yMan);
        }
    }

    if (fireMode == 2)
    {
        txTextOut (100, 150, "очередь");

        if (GetAsyncKeyState (VK_SPACE))
        {
            for (int nomer = 0; nomer < 3; nomer ++)
            {
                if (bul[nomer].f == 0)
                {
                    bulFly (&bul[nomer], manRight, manLeft, man, xMan, yMan);
                    break;
                }
            }
        }
     }


    txBitBlt (txDC(),  850, yl1, 1150,   8, floor);
    txBitBlt (txDC(),    0, yl2, 1150,   8, floor);
    txBitBlt (txDC(), -500, yl1, 1150,   8, floor);



            if (xMan > 1130)
            {
                xMan = 1130;
            }

            if (xMan < 20)
            {
                xMan = 20;
            }



        }

        if (page == 3)
        {

        }


        txSleep(10);
        txEnd();
        }

    txDeleteDC(manLeft);
    txDeleteDC(manRight);
    txDeleteDC(bulL);
    txDeleteDC(bulR);
    txDeleteDC(fireR);
    txDeleteDC(fireL);
    txDeleteDC(wall);
    txDeleteDC(floor);
    txDeleteDC(monsterA);
    txDeleteDC(monsterD);
    txDeleteDC(restart);
    txDeleteDC(gameover);

    return 0;

}
