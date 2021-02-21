#include "TXLib.h"
#include "Chel.cpp"
#include "Fire.cpp"
#include "Monster.cpp"

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

struct Floor
{
    int x;
    int y;
    int x2;
    HDC pic;
};


int main()
{
    txCreateWindow (1150, 650);

    char str [100];
    char hp [100];

    int hpman = 100;
    int page = 1;
    int level = 1;

    int xres = 1050;
    int yres = 0;
    HDC restart = txLoadImage ("��������/restart.bmp");

    int n_floor = 3;
    Floor floor[10];
    floor[0] = {-500, 300, 650, txLoadImage ("��������/gjk.bmp")};
    floor[1] = { 850, 300, 1150, floor[0].pic};
    floor[2] = {   0, 430, 1150, floor[0].pic};


    HDC wall = txLoadImage ("��������/wall.bmp");

    HDC monsterA = txLoadImage ("��������/monsterA.bmp");
    HDC monsterD = txLoadImage ("��������/monsterD.bmp");
    Monster monster1 = {900, 238, 1, monsterA, monsterD, monsterA};
    Monster monster2 = {300, 368, 1, monsterA, monsterD, monsterD};         //   struct



    HDC fireL = txLoadImage ("��������/fireball.bmp");
    HDC fireR = txLoadImage ("��������/firebarr.bmp");
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
    HDC manLeft = txLoadImage ("��������/manL.bmp");
    HDC manRight = txLoadImage ("��������/manR.bmp");
    HDC man = manRight;




    int fireMode = 1;
    int bulDist = 0;
    HDC bulL = txLoadImage ("��������/bulL.bmp");
    HDC bulR = txLoadImage ("��������/bulR.bmp");
    //HDC bul = bulR;
    Bullet bul[3];
    bul[0] = {35, xMan, 0, 0, bulL, bulR, bulR};
    bul[1] = {35, xMan, 0, 0, bulL, bulR, bulR};
    bul[2] = {35, xMan, 0, 0, bulL, bulR, bulR};                                      // struct

    int xgo = 450;
    int ygo = 200;
    HDC gameover = txLoadImage ("��������/gameover.bmp");


    while (!GetAsyncKeyState(VK_ESCAPE))
    {


        txBegin ();
        txSetFillColor (TX_WHITE);
        txClear();
        xManOld = xMan;
        yManOld = yMan;



        //����� ������
        if (page == PAGE_MENU)
        {
            txSetFillColor (TX_WHITE);
            txRectangle (0, 0, 1150, 650);
            txSelectFont ("Comic Sans MS", 50);
            txSetColor (TX_BLACK);
            txTextOut (450, 200, "������� �������:");
            txTextOut (450, 300, "�����");
            txTextOut (450, 400, "�������");

            if (txMouseX() > 450 &&                txMouseY() > 300 &&
                txMouseX() < 550 &&                txMouseY() < 350)
            {
                txSetFillColor(TX_RED);
                txCircle(420, 320, 20);

                if (txMouseButtons() == 1)
                    page = PAGE_GAME;
            }

            if (txMouseX() > 450 &&                txMouseY() > 400 &&
                txMouseX() < 550 &&                txMouseY() < 450)
            {
                txSetFillColor(TX_RED);
                txCircle(420, 420, 20);

                if (txMouseButtons() == 1)
                    page = 3;
            }

        }

        //����
        if (page == PAGE_GAME)
        {
            txBitBlt (txDC(),    0,   0, 1150, 650,  wall);

            for (int i = 0; i < n_floor; i++)
                txRectangle(floor[i].x, floor[i].y + 2, floor[i].x2, floor[i].y + 7);

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


            //��� �������
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

            //�� ������ ���������
            txSetColor (TX_WHITE, 4);
            txSelectFont ("Comic Sans MS", 25, 10, 1000);
            sprintf(str, "%d / 100", hpman);
            txTextOut(90, 32.5, str);


            //����� ��������
            txSetColor (TX_WHITE, 5);


            if (txMouseX() > xgo + 149 && txMouseX() < xgo + 201 &&
                txMouseY() > ygo + 122 && txMouseY() < ygo + 174 &&
                txMouseButtons() == 1)
            {
                txSetFillColor (TX_BLACK);
                txRectangle (0, 0, 1150, 650);
                txSelectFont ("Arial", 650, 250, 0);
                txTextOut (0, 0, "���");
                txSleep (1000);
                return 0;
            }

            //������� ����� ������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          � �����                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        1500 ������� �����                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  2000 ������� ��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         3000 ��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 4000                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    5000 ������ � ���
            if (hpman <= 0)
            {
                txTransparentBlt (txDC(),  xgo,  ygo,  254, 203, gameover,  0, 0, TX_WHITE);

                if (txMouseX() > xgo + 41  && txMouseX() < xgo + 92  &&          //����� ������� ����� ������
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
        txMouseY() < 100       &&                 //� ��� �������...
        txMouseButtons() == 1) ||                 //� ��� ���������
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



         //�������� ����


         if (txGetPixel (xMan + 20, yMan + 75) == TX_WHITE ||
             txGetPixel (     xMan,      yMan) == TX_WHITE)
         {
             //yMan = yManOld;
             jump = 0;
             vyMan = 0;
         }


        for (int nomer = 0; nomer < 3; nomer++)
        {
            bul[nomer].x = bul[nomer].x + bul[nomer].v;                                  //���� ������
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
        txTextOut (100, 150, "���������");

        if (GetAsyncKeyState (VK_SPACE))
        {
            bulFly (&bul[0], manRight, manLeft, man, xMan, yMan);
        }
    }

    if (fireMode == 2)
    {
        txTextOut (100, 150, "�������");

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

    for (int i = 0; i < n_floor; i++)
        txBitBlt (txDC(),  floor[i].x, floor[i].y, floor[i].x2 - floor[i].x, 8, floor[i].pic);




            if (xMan > 1130)
            {
                xMan = 1130;
            }

            if (xMan < 20)
            {
                xMan = 20;
            }

            //������� �������
            if (xMan > 1100 && yMan > 350)
            {
                xMan = 0;
                yMan = 300;
                level = level + 1;

                if (level == 2)
                {
                    //monster1=...
                    n_floor = 4;
                    floor[0] = {-500, 300, 650, txLoadImage ("��������/gjk.bmp")};
                    floor[1] = { 850, 300, 1150, floor[0].pic};
                    floor[2] = {   0, 430,  500, floor[0].pic};
                    floor[3] = { 500, 450, 1150, floor[0].pic};
                }
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
//    txDeleteDC(floor);
    txDeleteDC(monsterA);
    txDeleteDC(monsterD);
    txDeleteDC(restart);
    txDeleteDC(gameover);

    return 0;

}
