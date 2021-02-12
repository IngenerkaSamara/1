#include "TXLib.h"
#include "snake.cpp"
#include "tennis.cpp"
#include "mai.cpp"
#include "bomb it.cpp"
#include "tanks.cpp"
#include "shotgame.cpp"
void menu(int g, int g2, int g3, int g4, int g5, int g6, int g7, int xMenu)
{
    txSetColour(TX_BLACK);
    txSetFillColour(TX_BLACK);
    txRectangle(0, 0, 1600, 1000);
    //
    if(g == 0)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu, 200, xMenu + 200, 400);
    }
    if(g == 1)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu - 10, 210, xMenu + 210, 390);
    }

    txSetColour(TX_GREEN);
    txSetFillColour(TX_GREEN);
    txRectangle(xMenu + 20, 380, xMenu + 80, 360);

    txSetColour(TX_GREEN);
    txSetFillColour(TX_GREEN);
    txRectangle(xMenu + 60, 360, xMenu + 80, 340);

    txSetColour(TX_RED);
    txSetFillColour(TX_RED);
    txRectangle(xMenu + 125, 320, xMenu + 140, 335);

    //
    if(g2 == 0)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 300, 200, xMenu + 500, 400);
    }
    if(g2 == 1)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 290, 210, xMenu + 510, 390);
    }

    txSetColour(TX_WHITE);
    txSetFillColour(TX_WHITE);
    txRectangle(xMenu + 310, 250, xMenu + 320, 300);

    txSetColour(TX_WHITE);
    txSetFillColour(TX_WHITE);
    txRectangle(xMenu + 310, 250, xMenu + 320, 300);

    txSetColour(TX_WHITE);
    txSetFillColour(TX_WHITE);
    txRectangle(xMenu + 490, 320, xMenu + 480, 370);

    txSetColour(TX_WHITE);
    txSetFillColour(TX_WHITE);
    txCircle(xMenu + 430, 310, 10);


    //
    if(g3 == 0)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 600, 200, xMenu + 800, 400);
    }
    if(g3 == 1)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 590, 210, xMenu + 810, 390);
    }

    txSetColour(TX_ORANGE);
    txSetFillColour(TX_ORANGE);
    txCircle(xMenu + 620, 300, 10);

    txSetColour(TX_WHITE, 5);
    txSetFillColour(TX_WHITE);
    txLine(xMenu + 650, 230, xMenu + 650, 260);
    txLine(xMenu + 700, 290, xMenu + 700, 320);
    txCircle(xMenu + 750, 340, 20);

    //
    if(g4 == 0)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 900, 200, xMenu + 1100, 400);
    }
    if(g4 == 1)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 890, 210, xMenu + 1110, 390);
    }

    txSetColour(TX_WHITE, 3);
    txSetFillColour(TX_BLACK);
    POINT sam[4] =
    {
        {xMenu + 915, 300},
        {xMenu + 920, 290},
        {xMenu + 970, 300},
        {xMenu + 920, 310}
    };
    txPolygon (sam, 4);

    txSetColour(TX_WHITE);
    txSetFillColour(TX_WHITE);
    txCircle(xMenu + 925, 320, 3);

    //
    if(g5 == 0)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu, 500, xMenu + 200, 700);
    }
    if(g5 == 1)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu - 10, 510, xMenu + 210, 690);
    }

    //
    if(g6 == 0)
    {
    txSetColour(TX_RED, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 300, 500, xMenu + 500, 700);
    }
    if(g6 == 1)
    {
    txSetColour(TX_RED, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 290, 510, xMenu + 510, 690);
    }

    //
    if(g7 == 0)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 600, 500, xMenu + 800, 700);
    }
    if(g7 == 1)
    {
    txSetColour(TX_WHITE, 2);
    txSetFillColour(TX_BLACK);
    txRectangle(xMenu + 590, 510, xMenu + 810, 690);
    }

    txSetColour(RGB(255, 255, 0), 5);
    txSetFillColour(RGB(255, 255, 0));
    txRectangle(xMenu + 620, 640, xMenu + 640, 660);
    txLine(xMenu + 630, 640,xMenu + 630, 625);

    txSetColour(RGB(150, 150, 150), 5);
    txSetFillColour(RGB(150, 150, 150));
    txRectangle(xMenu + 730, 520, xMenu + 710, 540);
    txLine(xMenu + 720, 540, xMenu + 720, 555);
    //


    txSetColour(TX_WHITE);
    txSetFillColour(TX_WHITE);
    txTextOut(xMenu + 3000, 500, "ЧЕ СМОТРИШЬ??");

    txSetColour(TX_WHITE);
    txSetFillColour(TX_WHITE);
    txTextOut(xMenu - 3000, 500, "ЧЕ СМОТРИШЬ??");


}

int GameButtonOpen(int xgbo, int ygbo)
{
    int Game = 0;
    if (txMouseX() >= xgbo &&
        txMouseX() <= xgbo + 200 &&
        txMouseY() >= ygbo &&
        txMouseY() <= ygbo + 200 &&
        txMouseButtons() & 2)
    {
        Game = 1;
    }
}

int GameButtonFocus(int xgbo, int ygbo)
{
    int Game = 0;
    if (txMouseX() >= xgbo &&
        txMouseX() <= xgbo + 200 &&
        txMouseY() >= ygbo &&
        txMouseY() <= ygbo + 200)
    {
        Game = 1;
    }
}


struct Brick
{
    int x;
    int y;
    HDC picture;
    bool visible;
};


int main()
{
    txCreateWindow(1600, 1000);

    //змейка
    int xSnake = 10;
    int ySnake = 10;
    int xEda = random(200, 1400);
    int yEda = random(0, 800);
    int napravlenieSnake = 1;
    int snakeSpeed = 5;

    //tennis
    int yRocket1 = 350;
    int yRocket2 = 350;
    int xBall = 150;
    int yBall = 350;
    int napravlenieBallY = 1;
    int napravlenieBallX = 2;
    int scoreTennis1 = 0;
    int scoreTennis12 = 0;
    int speedBall = 0;

    //mai
    int xMai = 10; int yMai = 400;
    int xStena1 = 300; int yStena1 = random(100, 600);
    int xStena2 = 500; int yStena2 = random(100, 600);
    int xStena3 = 700; int yStena3 = random(100, 600);
    int xStena4 = 900; int yStena4 = random(100, 600);
    int xStena5 = 1100; int yStena5 = random(100, 600);
    int xStena6 = 1450; int yStena6 = random(100, 600);
    int xStena7 = 50; int yStena7 = random(400, 600);
    int xStena8 = 1250; int yStena8 = random(100, 600);

    //bomp it
    int xSamolet = 100;
    int ySamolet = 200;
    int xBomb = xSamolet;
    int yBomb = ySamolet;
    int xBoom = -100;
    int yBoom = -100;
    int positionSnaradSamolet = 0;
    int positionSamoletY = 300;
    int xBuilding1 = random(300, 1400); int yBuilding1 = 800;
    int xBuilding2 = random(800, 1400); int yBuilding2 = 750;
    int xBuilding3 = random(600, 1400); int yBuilding3 = 700;
    int GameOver = 0;
    int scoreBoom = 0;
    int victory = 0;
    int bompShot = 0;

    //tanks
    int xTankTrack1 = 682;
    int yTankTrack1 = 757;
    int xTankTrack2 = xTankTrack1 + 36;
    int yTankTrack2 = yTankTrack1 + 36;
    int napravlenieTank = 1;
    int xSnaradTank = xTankTrack1;
    int ySnaradTank = yTankTrack1;
    int snaradTankShot = 0;
    int snaradTankVragShot = 0;
    int xTankVrag = 575;
    int yTankVrag = 200;
    int xTankVragTower = 575;
    int yTankVragTower = 175;
    int napravlenieTankVrag = 1;
    int xSnaradTankVrag = xTankVragTower;
    int ySnaradTankVrag = yTankVragTower;
    int napravlenieSnaradTankShot = 0;
    int napravlenieSnaradTankVragShot = 0;
    int hearthTank = 3;
    int hearthTankVrag = 10;
    int turnTankVrag = 0;
    int turnTankVrag2 = 0;
    int skinSnaradTank = 0;
    int brockenBrick = 0;
    int buttonPiu = 0;
    Brick brick[100];
    brick[0] = {536, 716, txLoadImage("fon_.bmp")};
    brick[1] = {536, 668};
    brick[2] = {536, 620};
    brick[3] = {632, 716};
    brick[4] = {632, 668};
    brick[5] = {632, 620};

    brick[6] = {728, 620};
    brick[7] = {824, 620};
    brick[8] = {728, 572};
    brick[9] = {824, 572};

    brick[10] = {920, 716};
    brick[11] = {920, 668};
    brick[12] = {920, 620};
    brick[13] = {1016, 716};
    brick[14] = {1016, 668};
    brick[15] = {1016, 620};

    brick[16] = {536, 236};
    brick[17] = {536, 284};
    brick[18] = {536, 332};
    brick[19] = {536, 380};
    brick[20] = {632, 236};
    brick[21] = {632, 284};
    brick[22] = {632, 332};
    brick[23] = {632, 380};

    brick[24] = {920, 236};
    brick[25] = {920, 284};
    brick[26] = {920, 332};
    brick[27] = {920, 380};
    brick[28] = {1016, 236};
    brick[29] = {1016, 284};
    brick[30] = {1016, 332};
    brick[31] = {1016, 380};

    brick[32] = {728, 236};
    brick[33] = {728, 284};
    brick[34] = {728, 332};
    brick[35] = {824, 236};
    brick[36] = {824, 284};
    brick[37] = {824, 332};

    brick[38] = {584, 500};
    brick[39] = {632, 500};
    brick[40] = {920, 500};
    brick[41] = {968, 500};

    brick[42] = {728, 452};
    brick[43] = {824, 452};

    for (int nomer = 0; nomer < 44; nomer = nomer + 1)
    {
        brick[nomer].picture =  brick[0].picture;
        brick[nomer].visible =  true;
    }




    //shotgame
    int xShooterMan = 100;
    int yShooterMan = 800;
    int xGun1 = xShooterMan + 50;
    int yGun1 = yShooterMan;
    int xGun2 = xShooterMan + 50;
    int yGun2 = yShooterMan;
    int xSnaradGun1 = xShooterMan;
    int ySnaradGun1 = yShooterMan;
    int snaradGun1Shot = 0;
    int snaradGun2Shot = 0;
    int napravlenieShooterMan = 1;
    int napravlenieSnaradGun1 = 0;
    int Gun = 1;
    int yGun2Hatchet = yGun2;
    int chop = 0;
    int returnGun2Hatchet = 0;
    int jumpShooterMan = 0;
    int turnVragShooter = 1;
    int turnVragShooter2 = 1;
    //int napravlenieVragShooter = 1;
    int destroyVragShooter = 0;
    VragShooterMan shooterVrag1 = {800, 800, 1};
    int yGun12 = yGun1;

    //menu
    int xMenu = 200;
    int Game = 0;
    int g = 0;
    int g2 = 0;
    int g3 = 0;
    int g4 = 0;
    int g5 = 0;
    int g6 = 0;
    int g7 = 0;

    //картинки
    HDC tankUp = txLoadImage("tankUp.bmp");
    HDC tankDown = txLoadImage("tankDown.bmp");
    HDC tankRight = txLoadImage("tankRight.bmp");
    HDC tankLeft = txLoadImage("tankLeft.bmp");
    HDC snaradUp = txLoadImage("snaradUp.bmp");
    HDC snaradDown = txLoadImage("snaradDown.bmp");
    HDC snaradRight = txLoadImage("snaradRight.bmp");
    HDC snaradLeft = txLoadImage("snaradLeft.bmp");

    HDC tankVragUp = txLoadImage("tankVragUp.bmp");
    HDC tankVragDown = txLoadImage("tankVragDown.bmp");
    HDC tankVragRight = txLoadImage("tankVragRight.bmp");
    HDC tankVragLeft = txLoadImage("tankVragLeft.bmp");
    HDC snaradVragUp = txLoadImage("snaradVragUp.bmp");
    HDC snaradVragDown = txLoadImage("snaradVragDown.bmp");
    HDC snaradVragRight = txLoadImage("snaradVragRight.bmp");
    HDC snaradVragLeft = txLoadImage("snaradVragLeft.bmp");

    HDC button1 = txLoadImage("button.bmp");
    HDC button2 = txLoadImage("button2.bmp");

    HDC hearth = txLoadImage("hearth.bmp");
    HDC base = txLoadImage("base.bmp");
    HDC build1 = txLoadImage("building1.bmp");
    HDC build2 = txLoadImage("building2.bmp");
    HDC build3 = txLoadImage("building3.bmp");



    while(!GetAsyncKeyState (VK_ESCAPE))
    {
        txSetColour(TX_BLACK);
        txSetFillColour(TX_BLACK);
        txClear();

        Game = 0;

        if (Game == 0)
    {
        txClear();

        txSetColour(TX_WHITE);
        txSetFillColour(TX_WHITE);
        txTextOut(10, 10, "БЕТА 1.12");

        menu(g, g2, g3, g4, g5, g6, g7, xMenu);

        g = 0;
        g2 = 0;
        g3 = 0;
        g4 = 0;
        g5 = 0;
        g6 = 0;
        g7 = 0;

        if (GameButtonOpen(200, 200))             Game = 1;
        else if (GameButtonOpen(500, 200))        Game = 2;
        else if (GameButtonOpen(800, 200))        Game = 3;
        else if (GameButtonOpen(1100, 200))       Game = 4;
        else if (GameButtonOpen(200, 500))       Game = 5;
        else if (GameButtonOpen(500, 500))       Game = random(1, 7);
        else if (GameButtonOpen(800, 500))       Game = 7;
        else if (GameButtonOpen(1000, 500))       Game = 8;

        if (GameButtonFocus(200, 200))              g = 1;
        if (GameButtonFocus(500, 200))              g2 = 1;
        if (GameButtonFocus(800, 200))              g3 = 1;
        if (GameButtonFocus(1100, 200))              g4 = 1;
        if (GameButtonFocus(200, 500))              g5 = 1;
        if (GameButtonFocus(500, 500))              g6 = 1;
        if (GameButtonFocus(800, 500))              g7 = 1;





    }

        else if(Game == 1)
    {
        txSetColour(TX_WHITE);
        txRectangle(1500, 100, 1550, 150);
        txSetColour(TX_WHITE);
        txTextOut(1500, 105, "выход");

        if(txMouseX() >= 1500 &&
        txMouseX() <= 1550 &&
        txMouseY() >= 100 &&
        txMouseY() <= 150&&
        txMouseButtons() & 1)
        {
            Game = 0;
        }

        snake(xSnake, ySnake);
        eda(xEda, yEda);

        if(GetAsyncKeyState ('0'))
        {
            Game = 0;
        }


        if(GetAsyncKeyState ('W'))
        {
            napravlenieSnake = 1;
        }
        if(GetAsyncKeyState ('S'))
        {
            napravlenieSnake = 2;
        }
        if(GetAsyncKeyState ('A'))
        {
            napravlenieSnake = 3;
        }
        if(GetAsyncKeyState ('D'))
        {
            napravlenieSnake = 4;
        }

        if(napravlenieSnake == 1)
        {
            ySnake = ySnake - snakeSpeed;
        }

        if(napravlenieSnake == 2)
        {
            ySnake = ySnake + snakeSpeed;
        }


        if(napravlenieSnake == 3)
        {
            xSnake = xSnake - snakeSpeed;
        }


        if(napravlenieSnake == 4)
        {
            xSnake = xSnake + snakeSpeed;
        }

        if(snakeSpeed >= 10)
        {
            snakeSpeed = 10;
        }



        if(xSnake >= 1600)
        {
            xSnake = 10;
        }
        if(xSnake <= 0)
        {
            xSnake = 1590;
        }
        if(ySnake >= 1000)
        {
            ySnake = 10;
        }
        if(ySnake <= 0)
        {
            ySnake = 990;
        }

        COLORREF color = txGetPixel (100, 200);

        if (txGetPixel (xBomb, yBomb) == TX_RED)
        {
            xEda = random(100, 700) + random(300, 900) - 500;
            yEda = random(100, 700) + random(300, 900) - 500;
            snakeSpeed = snakeSpeed + 1;
        }

        if(xEda > 1500)
        {
            xEda = 1300;
        }
        if(xEda < 100)
        {
            xEda = 100;
        }
        if(yEda > 900)
        {
            yEda = 700;
        }
        if(yEda < 100)
        {
            yEda = 100;
        }

    }

        else if(Game == 2)
    {
        txSetColour(TX_WHITE);
        txRectangle(1500, 100, 1550, 150);
        txSetColour(TX_WHITE);
        txTextOut(1500, 105, "выход");

        if(txMouseX() >= 1500 &&
        txMouseX() <= 1550 &&
        txMouseY() >= 100 &&
        txMouseY() <= 150&&
        txMouseButtons() & 1)
        {
            Game = 0;
        }

        rocket1(yRocket1);

        rocket2(yRocket2);

        txSetColour(TX_WHITE);
        txSetFillColour(TX_WHITE);

        char str[100];
        sprintf(str, "%d", scoreTennis12);
        txTextOut(100, 30, str);


        sprintf(str, "%d", scoreTennis1);
        txTextOut(1300, 30, str);

        if(GetAsyncKeyState ('0'))
        {
            Game = 0;
        }

        if(napravlenieBallX == 2)
        {
            xBall = xBall + 5 + speedBall;
        }

        if(napravlenieBallX == 1)
        {
            xBall = xBall - 5 - speedBall;
        }
        if(speedBall >= 10)
        {
            speedBall = 10;
        }
        if(napravlenieBallY == 2)
        {
            yBall = yBall + 5;
        }
        if(napravlenieBallY == 1)
        {
            yBall = yBall - 5;
        }

        if(GetAsyncKeyState('W'))
        {
            yRocket1 = yRocket1 - 20;
        }
        if(GetAsyncKeyState ('S'))
        {
            yRocket1 = yRocket1 + 20;
        }
        if(GetAsyncKeyState ('O'))
        {
            yRocket2 = yRocket2 - 20;
        }
        if(GetAsyncKeyState ('L'))
        {
            yRocket2 = yRocket2 + 20;
        }
        if(yRocket1 >= 850)
        {
            yRocket1 = 850;
        }
        if(yRocket1 <= 0)
        {
            yRocket1 = 10;
        }
        if(yRocket2 >= 850)
        {
            yRocket2 = 850;
        }
        if(yRocket2 <= 0)
        {
            yRocket2 = 10;
        }
        if(yBall >= 1000)
        {
            napravlenieBallY = 1;
        }
        if(yBall <= 0)
        {
            napravlenieBallY = 2;
        }
        COLORREF color = txGetPixel (100, 200);

        if (txGetPixel (xBall, yBall) == RGB(254, 254, 254) ||
            txGetPixel (xBall - 5, yBall) == RGB(254, 254, 254) ||
            txGetPixel (xBall + 5, yBall) == RGB(254, 254, 254))
        {
            napravlenieBallY = 1;
            napravlenieBallX = 1;
            scoreTennis1 = scoreTennis1 + 30;
            speedBall = speedBall + 3;
        }
        else if (txGetPixel (xBall, yBall) == RGB(255, 255, 255) ||
            txGetPixel (xBall - 5, yBall) == RGB(255, 255, 255) ||
            txGetPixel (xBall + 5, yBall) == RGB(255, 255, 255))
        {
            napravlenieBallY = 2;
            napravlenieBallX = 2;
            scoreTennis12 = scoreTennis12 + 30;
            speedBall = speedBall + 3;
        }
        Ball(xBall, yBall);

        if(xBall >= 1600)
        {
            xBall = 30;
            scoreTennis1 = scoreTennis1 - 15;
        }
        if(xBall <= 0)
        {
            xBall = 1570;
            scoreTennis12 = scoreTennis12 - 15;
        }

    }

        else if(Game == 3)
    {
        txSetFillColour(RGB(133,464, 967));
        txRectangle(1500, 100, 1600, 150);

        txSetColour(TX_WHITE);
        txTextOut(1500, 105, "выход");



        if(txMouseX() >= 1500 &&
        txMouseX() <= 1550 &&
        txMouseY() >= 100 &&
        txMouseY() <= 150&&
        txMouseButtons() & 1)
        {
            Game = 0;
        }

        mai(xMai, yMai);

        xMai = xMai + 10;


        stena(xStena1, yStena1);
        stena(xStena2, yStena2);
        stena(xStena3, yStena3);
        stena(xStena4, yStena4);
        stena5(xStena5, yStena5);
        stena6(xStena6, yStena6);
        stena6(xStena7, yStena7);
        dstena(xStena8, yStena8);

        if(!GetAsyncKeyState ('R'))
        {
        yStena1 = yStena1 - 50;
        yStena2 = yStena2 + 50;
        yStena3 = yStena3 - 50;
        yStena4 = yStena4 + 50;
        yStena5 = yStena5 - 50;
        xStena6 = xStena6 - 50;
        xStena7 = xStena7 + 50;
        yStena8 = yStena8 + 50;
        }



        if(GetAsyncKeyState ('W'))
        {
            yMai = yMai - 15;
        }
        if(GetAsyncKeyState ('S'))
        {
            yMai = yMai + 15;
        }

        if(xMai >= 1600)
        {
            xMai = 10;
        }
        if(xMai <= 0)
        {
            xMai = 1590;
        }
        if(xMai <= 0)
        {
            xMai = 990;
        }
        COLORREF color = txGetPixel (100, 200);

        if (txGetPixel (xMai, yMai) == TX_WHITE)
        {
            xMai = 10;
        }
        if (txGetPixel (xMai, yMai) == (RGB(382, 162, 685)))
        {
            xMai = 10;
        }
        if (txGetPixel (xMai, yMai) == (RGB(121, 96, 35)))
        {
            xMai = 10;
        }


        if(yMai >= 980)
        {
            yMai = 970;
        }
        if(yMai <= 20)
        {
            yMai = 10;
        }

        if(yStena1 >= 1100)
        {
            yStena1 = -100;
        }
        if(yStena2 >= 1100)
        {
            yStena2 = -100;
        }
        if(yStena3 >= 1100)
        {
            yStena3 = -100;
        }
        if(yStena4 >= 1100)
        {
            yStena4 = -100;
        }
        if(yStena5 >= 1100)
        {
            yStena5 = -100;
        }
        if(yStena8 >= 1100)
        {
            yStena8 = -100;
        }


        if(yStena1 <= -150)
        {
            yStena1 = 1050;
        }
        if(yStena2 <= -150)
        {
            yStena2 = 1050;
        }
        if(yStena3 <= -150)
        {
            yStena3 = 1050;
        }
        if(yStena4 <= -150)
        {
            yStena4 = 1050;
        }
        if(yStena5 <= -150)
        {
            yStena5 = 1050;
        }
        if(yStena8 <= -150)
        {
            yStena8 = 1050;
        }

        if(xStena6 <= -150)
        {
            xStena6 = 1650;
        }

        if(xStena7 >= 1750)
        {
            xStena7 = -50;
        }

    }

        else if(Game == 4)
    {
        txSetColour(TX_WHITE);
        txSetFillColour(TX_WHITE);
        txClear();

        txSetColour(TX_BLACK);
        txRectangle(1500, 100, 1550, 150);
        txSetColour(TX_BLACK);
        txTextOut(1500, 105, "выход");

        txSetColour(RGB(2, 2, 2));
        txSetFillColour(RGB(2, 2, 2));
        txRectangle(0, 900, 1600, 1000);

        if(txMouseX() >= 1500 &&
        txMouseX() <= 1550 &&
        txMouseY() >= 100 &&
        txMouseY() <= 150&&
        txMouseButtons() & 1)
        {
            Game = 0;
        }

        samolet(xSamolet, ySamolet);
        bomb(xBomb, yBomb, positionSnaradSamolet);

        boom(xBoom, yBoom);

        building1(xBuilding1, yBuilding1, build1);
        building2(xBuilding2, yBuilding2, build2);
        building3(xBuilding3, yBuilding3, build3);

        txSetColour(TX_BLACK);
        char str[100];
        sprintf(str, "%d", scoreBoom);
        txTextOut(100, 50, str);



        xSamolet = xSamolet + positionSnaradSamolet;
        xSamolet = xSamolet + 5;
        ySamolet = positionSamoletY;

        if(bompShot == 0)
        {
            xBomb = xSamolet + positionSnaradSamolet;
            yBomb = ySamolet + positionSnaradSamolet;
            xBoom = -100;
            yBoom = -100;
        }


        if(xSamolet >= 1600)
        {
            xSamolet = -10;
            positionSnaradSamolet = positionSnaradSamolet + 3;
            positionSamoletY = positionSamoletY + 50;
        }

        if(positionSnaradSamolet >= 15)
        {
            positionSnaradSamolet = 15;
        }



        if(txMouseButtons () & 1)
        {
            bompShot = 1;
        }
        if(bompShot == 1)
        {
            yBomb = yBomb + 15;
            xBomb = xBomb - 1;
        }

        if(xBomb >= 1600)
        {
            xBomb = 1600;
        }
        if(xBomb <= 0)
        {
            xBomb = 0;
        }


        COLORREF color = txGetPixel (100, 200);

        if(yBomb >= 900)
        {
            bompShot = 0;
            xBoom = xBomb;
            yBoom = yBomb;
        }


        if (txGetPixel (xBomb, yBomb) == RGB(0, 0, 0))
        {
            yBuilding1 = yBuilding1 + 20;
            bompShot = 0;
            xBoom = xBomb;
            yBoom = yBomb;
            scoreBoom = scoreBoom + random(50, 150);
        }
        if (txGetPixel (xBomb, yBomb) == RGB(3, 3, 3))
        {
            yBuilding2 = yBuilding2 + 20;
            bompShot = 0;
            xBoom = xBomb;
            yBoom = yBomb;
            scoreBoom = scoreBoom + random(50, 150);
        }
        if (txGetPixel (xBomb, yBomb) == RGB(4, 4, 4))
        {
            yBuilding3 = yBuilding3 + 20;
            bompShot = 0;
            xBoom = xBomb;
            yBoom = yBomb;
            scoreBoom = scoreBoom + random(50, 150);
        }




    }

        else if(Game == 7)
    {
        txSetColour(RGB(160, 160, 160));
        txRectangle(1500, 100, 1550, 150);
        txSetColour(TX_WHITE);
        txTextOut(1500, 105, "выход");

        backend();

        for (int nomer = 0; nomer < 44; nomer = nomer + 1)
        {
            if (brick[nomer].visible)
                txTransparentBlt(txDC(), brick[nomer].x, brick[nomer].y, 48, 48, brick[nomer].picture, 0, 0, TX_BLACK);

            if (brick[nomer].x + 48 > xSnaradTank &&
                brick[nomer].x      < xSnaradTank + 48 &&
                brick[nomer].y + 48 > ySnaradTank &&
                brick[nomer].y      < ySnaradTank + 48)
            {
                brick[nomer].visible = false;
                snaradTankShot = 0;
            }
        }
        if(buttonPiu == 0)
            txTransparentBlt(txDC(), 1200, 800, 100, 100, button1, 0, 0, TX_BLACK);

        if(buttonPiu == 1)
            txTransparentBlt(txDC(), 1200, 800, 100, 100, button2, 0, 0, TX_BLACK);

        if(txMouseX() >= 1200 &&
            txMouseY() >= 800 &&
            txMouseX() <= 1300 &&
            txMouseY() <= 900 &&
            txMouseButtons() & 1)
        {
            buttonPiu = 1;
        }

        if(turnTankVrag2 == 0)
        {
            turnTankVrag = turnTankVrag + 1;
        }
        if(turnTankVrag >= 40)
        {
            turnTankVrag2 = 1;
        }
        if(turnTankVrag <= 0)
        {
            turnTankVrag2 = 0;
        }
        if(turnTankVrag2 == 1)
        {
            turnTankVrag = turnTankVrag - 1;
        }

        if(turnTankVrag == 10)
        {
            napravlenieTankVrag = 1;
        }
        if(turnTankVrag == 20)
        {
            napravlenieTankVrag = 2;
        }
        if(turnTankVrag == 30)
        {
            napravlenieTankVrag = 3;
        }
        if(turnTankVrag == 40)
        {
            napravlenieTankVrag = 4;
        }

        if(txMouseX() >= 1500 &&
        txMouseX() <= 1550 &&
        txMouseY() >= 100 &&
        txMouseY() <= 150&&
        txMouseButtons() & 2)
        {
            Game = 0;
        }

        if(hearthTank <= 0)
        {
            snaradTankShot = 0;
            xTankTrack1 = 400;
            yTankTrack1 = 900;
        }

        if(hearthTankVrag >= 1)
        {
            tankVrag(xTankVrag, yTankVrag, xTankVragTower, yTankVragTower, napravlenieTankVrag, tankVragUp, tankVragDown, tankVragRight, tankVragLeft);
            snaradVragTank(xSnaradTankVrag + 14, ySnaradTankVrag + 14, napravlenieTankVrag, snaradVragUp, snaradVragDown, snaradVragRight, snaradVragLeft);
        }

        tank(xTankTrack1, yTankTrack1, xTankTrack2, yTankTrack2, napravlenieTank, tankUp, tankDown, tankRight, tankLeft);

        snaradTank(xSnaradTank + 14, ySnaradTank + 14, snaradUp, snaradDown, snaradRight, snaradLeft, skinSnaradTank);


        txSetColour(TX_BLACK);
        txSetFillColour(TX_BLACK);
        txTextOut(1340, 800, "HEARTH");

        char str[100];
        sprintf(str, "%d", hearthTank);
        txTextOut(1410, 800, str);

        txSetColour(TX_BLACK);
        txRectangle(1500, 100, 1550, 150);
        txSetColour(TX_WHITE);
        txTextOut(1500, 105, "выход");

        COLORREF color = txGetPixel (100, 200);

        if(hearthTank <= 0)
        {
            hearthTank = 0;
            txSetColour(TX_ORANGE);
            txTextOut(550, 480, "GAME/nOVER");
        }



        if (GetAsyncKeyState ('W'))
        {
            napravlenieTank = 1;
            yTankTrack1 = yTankTrack1 - 10;
            yTankTrack2 = yTankTrack2 - 10;
            if(!txGetPixel (xTankTrack1, yTankTrack1 - 36) == TX_BLACK &&
               !txGetPixel (xTankTrack2, yTankTrack2 - 36) == TX_BLACK)
            {
                yTankTrack1 = yTankTrack1 + 10;
                yTankTrack2 = yTankTrack2 + 10;
            }
        }
        else if(GetAsyncKeyState ('S'))
        {
            napravlenieTank = 2;
            yTankTrack1 = yTankTrack1 + 10;
            yTankTrack2 = yTankTrack2 + 10;
            if(!txGetPixel (xTankTrack1, yTankTrack1) == TX_BLACK &&
               !txGetPixel (xTankTrack2, yTankTrack2) == TX_BLACK)
            {
                yTankTrack1 = yTankTrack1 - 10;
                yTankTrack2 = yTankTrack2 - 10;
            }
        }
        else if(GetAsyncKeyState ('D'))
        {
            napravlenieTank = 3;
            xTankTrack1 = xTankTrack1 + 10;
            xTankTrack2 = xTankTrack2 + 10;
            if(!txGetPixel (xTankTrack1, yTankTrack1) == TX_BLACK &&
               !txGetPixel (xTankTrack2, yTankTrack2) == TX_BLACK)
            {
                xTankTrack1 = xTankTrack1 - 10;
                xTankTrack2 = xTankTrack2 - 10;
            }
        }
        else if(GetAsyncKeyState ('A'))
        {
            napravlenieTank = 4;
            xTankTrack1 = xTankTrack1 - 10;
            xTankTrack2 = xTankTrack2 - 10;
            if(!txGetPixel (xTankTrack1 - 36, yTankTrack1) == TX_BLACK &&
               !txGetPixel (xTankTrack2 - 36, yTankTrack2) == TX_BLACK)
            {
                xTankTrack1 = xTankTrack1 + 10;
                xTankTrack2 = xTankTrack2 + 10;
            }
        }


        if (napravlenieSnaradTankShot == 0 &&
            buttonPiu == 1)
        {
            if (napravlenieTank >= 1 &&
                napravlenieTank <= 4)
            {
                snaradTankShot = napravlenieTank;
                napravlenieSnaradTankShot = 1;
            }
        }



        if(snaradTankShot == 0)
        {
            napravlenieSnaradTankShot = 0;
            xSnaradTank = xTankTrack1;
            ySnaradTank = yTankTrack1;
        }
        if(snaradTankShot == 1)
        {
            ySnaradTank = ySnaradTank - 10;
            skinSnaradTank = 1;
        }
        if(snaradTankShot == 2)
        {
            ySnaradTank = ySnaradTank + 10;
            skinSnaradTank = 2;
        }
        if(snaradTankShot == 3)
        {
            xSnaradTank = xSnaradTank + 10;
            skinSnaradTank = 3;
        }
        if(snaradTankShot == 4)
        {
            xSnaradTank = xSnaradTank - 10;
            skinSnaradTank = 4;
        }

        if(napravlenieSnaradTankVragShot == 0)
        {
            if(napravlenieTankVrag == 1)
            {
                snaradTankVragShot = 1;
                napravlenieSnaradTankVragShot = 1;
                yTankVrag = yTankVrag - 10;
            }
            if(napravlenieTankVrag == 2)
            {
                snaradTankVragShot = 2;
                napravlenieSnaradTankVragShot = 1;
                yTankVrag = yTankVrag + 10;
            }
            if(napravlenieTankVrag == 3)
            {
                snaradTankVragShot = 3;
                napravlenieSnaradTankVragShot = 1;
                xTankVrag = xTankVrag + 10;
            }
            if(napravlenieTankVrag == 4)
            {
                snaradTankVragShot = 4;
                napravlenieSnaradTankVragShot = 1;
                xTankVrag = xTankVrag - 10;
            }
        }

        if(napravlenieTank == 1 &&
        !txGetPixel(xSnaradTank, ySnaradTank) == TX_BLACK)
        {
            snaradTankShot = 0;
            buttonPiu = 0;
        }
        if(napravlenieTank == 2 &&
        !txGetPixel(xSnaradTank, ySnaradTank + 36) == TX_BLACK)
        {
            snaradTankShot = 0;
            buttonPiu = 0;
        }
        if(napravlenieTank == 3 &&
        !txGetPixel(xSnaradTank + 36, ySnaradTank) == TX_BLACK)
        {
            snaradTankShot = 0;
            buttonPiu = 0;
        }
        if(napravlenieTank == 4 &&
        !txGetPixel(xSnaradTank, ySnaradTank) == TX_BLACK)
        {
            snaradTankShot = 0;
            buttonPiu = 0;

        }

        if(snaradTankVragShot == 0)
        {
            xSnaradTankVrag = xTankVragTower;
            ySnaradTankVrag = yTankVragTower;
            napravlenieSnaradTankVragShot = 0;
        }
        if(snaradTankVragShot == 1)
        {
            ySnaradTankVrag = ySnaradTankVrag - 10;
        }
        if(snaradTankVragShot == 2)
        {
            ySnaradTankVrag = ySnaradTankVrag + 10;
        }
        if(snaradTankVragShot == 3)
        {
            xSnaradTankVrag = xSnaradTankVrag + 10;
        }
        if(snaradTankVragShot == 4)
        {
            xSnaradTankVrag = xSnaradTankVrag - 10;
        }

        if(!txGetPixel (xSnaradTankVrag, ySnaradTankVrag) == TX_BLACK)
        {
            snaradTankVragShot = 0;
        }




        //Вывод жизней на экран
        for (int nomer = 0; nomer < hearthTankVrag; nomer = nomer + 1)
        {
            int y = 200 + 30 * nomer;
            txTransparentBlt(txDC(), 1200, y, 21, 30, hearth, 0, 0, RGB(160, 160, 160));
        }


    }

        else if(Game == 8)
    {
        txSetFillColour(TX_WHITE);
        txRectangle(0, 0, 1600, 1000);
        txSetColour(TX_BLACK);
        txTextOut(1500, 105, "выход");




        xGun1 = xShooterMan;
        yGun1 = yShooterMan;
        xGun2 = xShooterMan;
        yGun2 = yShooterMan;
        yGun12 = yShooterMan;

        if(GetAsyncKeyState ('1'))
        {
            Gun = 1;
        }
        if(GetAsyncKeyState ('2'))
        {
            Gun = 2;
        }
        if(GetAsyncKeyState ('3'))
        {
            Gun = 3;
        }


        if(GetAsyncKeyState ('A'))
        {
            xShooterMan = xShooterMan - 10;
            napravlenieShooterMan = 2;
        }
        if(GetAsyncKeyState ('D'))
        {
            xShooterMan = xShooterMan + 10;
            napravlenieShooterMan = 1;
        }

        if(GetAsyncKeyState (VK_SPACE) &&
        yShooterMan == 800)
        {
            jumpShooterMan = 1;
        }
        if(jumpShooterMan == 0)
        {
            yShooterMan = yShooterMan + 20;
            yGun2Hatchet = yGun2Hatchet + 20;
        }
        if(jumpShooterMan == 1)
        {
            yShooterMan = yShooterMan - 10;
            yGun2Hatchet = yGun2Hatchet - 10;
        }
        if(jumpShooterMan == 2)
        {
            yShooterMan = 800;
        }
        if(yShooterMan <= 650)
        {
           jumpShooterMan = 0;
        }
        if(yShooterMan >= 800)
        {
           jumpShooterMan = 2;
        }


        if(Gun == 1)
        {
        snaradGun1(xSnaradGun1, ySnaradGun1);
        if(txMouseButtons() & 1 && snaradGun1Shot == 0)
        {
            if(napravlenieShooterMan == 1)
            {
                snaradGun1Shot = 1;
                napravlenieSnaradGun1 = 1;
            }
            if(napravlenieShooterMan == 2)
            {
                snaradGun1Shot = 2;
                napravlenieSnaradGun1 = 1;
            }
        }

        if(snaradGun1Shot == 0)
        {
            xSnaradGun1 = xGun1;
            ySnaradGun1 = yGun1;
        }
        if(snaradGun1Shot == 1)
        {
            xSnaradGun1 = xSnaradGun1 + 30;
        }
        if(snaradGun1Shot == 2)
        {
            xSnaradGun1 = xSnaradGun1 - 30;
        }

        if(xSnaradGun1 >= 1600)
        {
            snaradGun1Shot = 0;
        }
        if(xSnaradGun1 <= 0)
        {
            snaradGun1Shot = 0;
        }

        if(snaradGun1Shot == 0)
        {
            xSnaradGun1 = xGun1;
            ySnaradGun1 = yGun1;
        }
        }

        if(Gun == 2)
        {
            snaradGun1Shot = 0;
            if(txMouseButtons() & 1)
            {
                snaradGun2Shot = 1;
            }

            if(snaradGun2Shot == 1)
            {
                yGun2Hatchet = yGun2Hatchet + 15;
            }
            if(yGun2Hatchet >= (yShooterMan + 80))
            {
                yGun2Hatchet = yShooterMan;
                snaradGun2Shot = 0;
            }
        }

        if(xShooterMan >= 1600)
        {
            xShooterMan = 10;
        }
        if(xShooterMan <= 0)
        {
            xShooterMan = 1590;
        }

        wallCollisionShooterMan(&shooterVrag1);



        if(turnVragShooter >= 40)
        {
            turnVragShooter2 = 2;
        }
        if(turnVragShooter <= 0)
        {
            turnVragShooter2 = 1;
        }
        if(turnVragShooter2 == 1)
        {
            turnVragShooter = turnVragShooter + 1;
        }
        if(turnVragShooter2 == 2)
        {
            turnVragShooter = turnVragShooter - 1;
        }

        if(shooterVrag1.napravlenie == 1)
        {
            shooterVrag1.x = shooterVrag1.x + 5;
        }
        if(shooterVrag1.napravlenie == 2)
        {
            shooterVrag1.x = shooterVrag1.x - 5;
        }

        if(turnVragShooter == 10)
        {
            shooterVrag1.napravlenie = 1;
        }
        if(turnVragShooter == 30)
        {
            shooterVrag1.napravlenie = 2;
        }

        if (txGetPixel (xSnaradGun1, ySnaradGun1) == RGB(254, 254, 254))
        {
            destroyVragShooter = 1;
            snaradGun1Shot = 0;
        }
        if (txGetPixel (xGun2, yGun2Hatchet) == RGB(254, 254, 254) &&
        txMouseButtons() & 1)
        {
            destroyVragShooter = 1;
        }

        if(GetAsyncKeyState (VK_UP) &&
        yGun1 >= (yShooterMan - 100))
        {
            yGun1 = yGun1 - 5;
        }


        if(GetAsyncKeyState (VK_UP))
        {
            yGun12 = yShooterMan - 50;
        }
        if(GetAsyncKeyState (VK_DOWN))
        {
            yGun12 = yShooterMan;
        }


    }

    txSleep(20);

    }
    return 0;
}
