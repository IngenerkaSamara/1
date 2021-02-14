#include "TXLib.h"
#include "stolknovenie.cpp"

int checkWallX(int xPers)
{
   if(xPers < 0)
        {
            xPers = 0;
        }
        if(xPers > 1200)
        {
            xPers = 1200;
        }
return xPers;
}

struct Pers
{
    HDC pic;
    int x;
    int y;
    bool visible;
};

struct Pers1
{
    HDC pic;
    int x;
    int y;
    bool visible;
};

void drawPers(Pers vrag)
{
    if (vrag.visible)
        txTransparentBlt(txDC(),vrag.x,vrag.y,99,99,vrag.pic, 0, 0, TX_WHITE);
}

void drawPers1(Pers stary)
{
    if(stary.visible)
      txTransparentBlt(txDC(),stary.x,stary.y,68,68,stary.pic, 0, 0, TX_WHITE);

}

int main()
{
    txCreateWindow (1200, 800);

//Переменные
    //Главный герой
    HDC persShiroki = txLoadImage("Lv13.bmp");
    HDC persUlybka = txLoadImage("pictures/Lv12.bmp");
    HDC persTixo = txLoadImage("Lv11.bmp");
    HDC persKrutoi = txLoadImage("Lvl21.bmp");
    HDC pers1 = txLoadImage("pictures/Lvl1.bmp");
    HDC pers2 = txLoadImage("Lv14.bmp");
    HDC pers3 = persShiroki;
    HDC pers4 = persUlybka;
    HDC pers5 = persTixo;
    HDC pers6 = persKrutoi;
    Pers pers = {pers1, 100, 200};

    HDC Star = txLoadImage("star.bmp");
    Pers1 stary[2];
    stary[0] = {Star, -200, 200, true};
    stary[1] = {Star, -200, 300, true};

    //Враги
    HDC vrag = txLoadImage("Vrag.bmp");
    Pers vragi[11];
    vragi[0] = {vrag, 300, 300, true};
    vragi[1] = {vrag, 600, 300, true};
    vragi[2] = {vrag, 900, 300, true};
    vragi[3] = {vrag, 300, 100, true};
    vragi[4] = {vrag, 600, 100, true};
    vragi[5] = {vrag, 900, 100, true};
    vragi[6] = {vrag, 300, 500, true};
    vragi[7] = {vrag, 600, 500, true};
    vragi[8] = {vrag, 900, 500, true};
    vragi[9] = {vrag, -100, -100, true};
    vragi[10] = {vrag,-200, -200, true};
    vragi[11] = {vrag,-200, -200, true};



    int level = 1;
    int Fonx = 0;

    int xvor = 300;  int yvor = 700;
    int xvor2 = 600; int yvor2 = 700;
    int xvor3 = -300; int yvor3 = -300;
    int xvor33 = -400; int yvor33 = -400;
    int xvixod = 1090; int xvixod2 = -1000;
    int yvixod = 680;  int yvixod2 = -100;
    int xLife1 = -1000; int yLife1 = -1000;
    int xTextL = 98;    int yTextL = 52;
    int xlvl1 = -2000;  int ylvl1 = -100;
    int xFon = 0;       int yFon = 0;

    bool visibleLife1 = true;
    bool visibleStar1 = true;
    int life = 5;

        HDC vorota = txLoadImage("Vorota.bmp");
        HDC vixod = txLoadImage("Vixod.bmp");
        HDC heart = txLoadImage("Heart.bmp");
        HDC Vor3 = txLoadImage("Vlr3.bmp");
        HDC Heart = txLoadImage("Life.bmp");
        HDC Lvl1 = txLoadImage("Lvl-1.bmp");
        HDC Fon = txLoadImage("Ащт.bmp");
        HDC vixod2 = txLoadImage("vixod2.bmp");
        //HDC ExitK = txLoadImage("ExitK.bmp");
        HDC Knopka4 = txLoadImage("Knopka4.bmp");
        HDC Knopka6 = txLoadImage("Knopka6.bmp");

    HDC knopka = txLoadImage("Pictures/knopka.bmp");
    HDC setting = txLoadImage("Settings.bmp");
    HDC meny1 = txLoadImage("Facem1.bmp");
    HDC meny2 = txLoadImage("Facem2.bmp");
    HDC vixodG = txLoadImage("Exit.bmp");
    HDC nasad = txLoadImage("nasad.bmp");

    bool gameStart = false;
    bool settings = false;
    bool mneNadoelo = false;

//Выбор персонажа
    while(!gameStart)
    {
        txSetFillColor(TX_BLACK);
        txClear();

        if (!settings)
        {
            txSetColour(TX_WHITE);
            txSelectFont("Times New Roman",35);
            txTextOut(500,40, "Смайлики");
            txTextOut(40,740, "beta");
            txTextOut(500,500, "Выберите персонажа:");

            txTransparentBlt(txDC(),450,350,227,84,knopka, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),1050,550,90,90,setting, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),1120,50,49,49,vixodG, 0, 0, TX_WHITE);



            txTransparentBlt(txDC(),480,580,72,72,pers3, 0, 0, TX_WHITE); //persShiroki
            txTransparentBlt(txDC(),600,580,72,72,pers4, 0, 0, TX_WHITE); //persUlybka
            txTransparentBlt(txDC(),720,580,72,72,pers5, 0, 0, TX_WHITE);   //persTixo
            txTransparentBlt(txDC(),840,580,72,72,pers6, 0, 0, TX_WHITE);

        //Выбор персонажа
            if (txMouseButtons() == 1 &&
                    txMouseX() >= 480 &&                 txMouseX() <= 552 &&
                    txMouseY() >= 580 &&                 txMouseY() <= 652)
            {
                //gameStart = true;
                pers1 = persShiroki;
            }

            if (txMouseButtons() == 1 &&
                    txMouseX() >= 600 &&                txMouseX() <= 672 &&
                    txMouseY() >= 580 &&                txMouseY() <= 652)
            {
                //gameStart = true;
                pers1 = persUlybka;
            }

            if (txMouseButtons() == 1 &&
                    txMouseX() >= 720 &&                txMouseX() <= 792 &&
                    txMouseY() >= 580 &&                txMouseY() <= 652)
            {
                //gameStart = true;
                pers1 = persTixo;
            }

            if (txMouseButtons() == 1 &&
                    txMouseX() >= 720 &&                txMouseX() <= 792 &&
                    txMouseY() >= 580 &&                txMouseY() <= 652)
            {
                //gameStart = true;
                pers1 = persTixo;
            }

            if (txMouseButtons() == 1 &&
                    txMouseX() >= 840 &&                txMouseX() <= 912 &&
                    txMouseY() >= 580 &&                txMouseY() <= 652)
            {
                //gameStart = true;
                pers1 = persKrutoi;
            }




        //Переход в настройки
            if (txMouseButtons() == 1 &&
                txMouseX() >= 1050 &&               txMouseX() <= 1140 &&
                txMouseY() >= 550 &&                txMouseY() <= 640)
            {
                settings = true;
            }

        //Начать игру
            if (txMouseButtons() == 1 &&
                txMouseX() >= 450 &&                txMouseX() <= 580 &&
                txMouseY() >= 350 &&                txMouseY() <= 420)
            {
                gameStart = true;
            }

        //Выход
            if (txMouseButtons() == 1 &&
                txMouseX() >= 1120 &&               txMouseX() <= 1169 &&
                txMouseY() >= 50 &&                 txMouseY() <= 99)
            {
                mneNadoelo = true;
            }
        }
        else if (settings)
        {
            txSetColour(TX_WHITE);
            txSelectFont("Times New Roman",35);
            txTextOut(240,250, "Всем привет! Это моя первая игра");
            txTransparentBlt(txDC(),100,650,87,87,nasad, 0, 0, TX_WHITE);

            if (txMouseButtons() == 1 &&
                txMouseX() >= 100 &&                txMouseX() <= 187 &&
                txMouseY() >= 650 &&                 txMouseY() <= 737)
            {
                settings = false;
            }

        }
        txSleep(10);
    }



//Игра
mneNadoelo = false;
bool menu = false;
    while(life > 0 && !mneNadoelo)
    {
        //Фон
        txBegin();

        txClear();
        txSetColour(TX_BLACK);
        txSetFillColour(TX_BLACK);

   //меню выхода
        if (menu)
        {
            txSetColour(TX_WHITE);
            txSelectFont("Times New Roman",35);
            txTextOut(450,40, "Меню паузы");
            txTransparentBlt(txDC(),300,400,123,36,Knopka6, 0, 0, TX_WHITE);
           // txTransparentBlt(txDC(),1100,100,72,72,Knopka4, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),80,50,49,49,vixodG, 0, 0, TX_WHITE);
           if (txMouseButtons() == 1 &&
                txMouseX() >= 300 &&
                txMouseX() <= 423 &&
                txMouseY() >= 400 &&
                txMouseY() <= 436)
            {
                menu = false;
                //gameStart = true;
            }
           if (txMouseButtons() == 1 &&
                txMouseX() >= 80 &&
                txMouseX() <= 129 &&
                txMouseY() >= 50 &&
                txMouseY() <= 99)
            {
                mneNadoelo = true;
                //gameStart = true;



            }
        }

        else
        {
           if (txMouseButtons() == 1 &&
                txMouseX() >= 1120 &&
                txMouseX() <= 1169 &&
                txMouseY() >= 50 &&
                txMouseY() <= 99)
            {
                menu = true;
                //gameStart = true;



            }



            txBitBlt(txDC(),xFon,yFon,1200,800,Fon);
            //txTransparentBlt(txDC(),1050,550,90,90,setting, 0, 0, TX_WHITE);
            //Жизни
            txTransparentBlt(txDC(),50,50,42,42,heart, 0, 0, TX_WHITE);
            txSelectFont("Times New Roman",35);
            char str1[100];
            sprintf(str1, "%d", life);
            txSetColour(TX_WHITE);
            txTextOut(100,50, str1);
            //Уровень
            txSelectFont("Times New Roman",35);
            char str[100];
            sprintf(str, "Уровень %d", level);
            txTextOut(500,40, str);

            txTransparentBlt(txDC(),1120,50,49,49,vixodG, 0, 0, TX_WHITE);





            if(txMouseX() > xvixod)
            if(txMouseY() > yvixod)
            if(txMouseX() < xvixod  + 100)
            if(txMouseY() < yvixod + 100)
            if(txMouseButtons() == 1)
            {
               life = 5;
            }

            //Рожа персонажа в зависимости от уровня
            if (life == 5)        pers.pic = pers1;
         //   else if (life == 4)   pers.pic = pers2;
          //  else if (life == 3)   pers.pic = pers3;
         //   else if (life == 2)   pers.pic = pers4;
          //  else if (life == 1)   pers.pic = pers5;


            txTransparentBlt(txDC(),pers.x-36,pers.y-36,72,72,pers.pic, 0, 0, TX_WHITE);

            for (int i = 0; i < 2; i = i + 1)
            {
                txTransparentBlt(txDC(),stary[i].x-36,stary[i].y-36,68,68,stary[i].pic, 0, 0, TX_WHITE);
                stary[i].x = checkWallX(stary[i].x);
            }


            pers.x = checkWallX(pers.x);



            if(pers.y < 0)
            {
                pers.y = 0;
            }
            if(pers.y > 800)
            {
                pers.y = 800;
            }
    //пЕРСОНАЖИ
      /*
        txSetColour(TX_WHITE);
        txSetFillColour(TX_GREEN);
        //txSelectFont("Times New Roman",37);
        //txTextOut(1090,730,"Финиш");   */
        txSetColour(TX_WHITE);
        txSetFillColour(TX_WHITE);
        //txTextOut(xtext,ytext, "Уровень 1");

            if(GetAsyncKeyState(VK_RIGHT))
            {
              pers.x = pers.x + 10;
            }

             if(GetAsyncKeyState(VK_LEFT))
            {
              pers.x = pers.x - 10;
            }
            if(GetAsyncKeyState(VK_UP))
            {
             pers.y = pers.y - 10;
            }
            if(GetAsyncKeyState(VK_DOWN))
            {
             pers.y = pers.y + 10;
            }

            for (int i = 0; i < 11; i++)
                drawPers(vragi[i]);

            for (int i = 0; i < 2; i++)
              Pers1(stary[i]);


            txTransparentBlt(txDC(),xvor,yvor,84,84,vorota, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),xvor2,yvor2,84,84,vorota, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),xvor3,yvor3,84,84,vorota, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),xvixod,yvixod,90,90,vixod, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),xvixod2,yvixod2,90,90,vixod, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),xvor33,yvor33,84,84,Vor3, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),xvor33,yvor33,84,84,Vor3, 0, 0, TX_WHITE);


            if (visibleLife1)
                txTransparentBlt(txDC(),xLife1,yLife1,84,84,Heart, 0, 0, TX_WHITE);
            txTransparentBlt(txDC(),xlvl1,ylvl1,90,90,Lvl1, 0, 0, TX_WHITE);

        /*
            int life1 = 0;
            while(life1 < life)
            {
                txTransparentBlt(txDC(),xhear + 42 * life1,yhear,42,42,heart, 0, 0, TX_WHITE);
                life1 = life1 + 1;
            }
            //(x2,y2,x2+99,y2+99);
            //txRectangle(xPers - 36,yPers - 36,xPers + 36,yPers + 36);
            */

      /*  txSetColour(TX_WHITE);
        txSetFillColour(TX_WHITE);
        txTextOut(xTextL,yTextL, "5");
        txSelectFont("Times New Roman",35);
        char str2[100];
        sprintf(str2, "%d", life);
        txTextOut(xtext,ytext, str);
        txSetColour(TX_WHITE);
        txSetFillColour(TX_GREEN); */
        //txSelectFont("Times New Roman",37);
        //txTextOut(1090,730,"Финиш");   */



       if(pers.x + 30 > xvixod)
       if(pers.y + 30 > yvixod)
       if(pers.x - 30 < xvixod + 100)
       if(pers.y - 30 < yvixod + 100)
       {
            //txSetFillColour(TX_BLACK);
            //txSetColour(TX_WHITE);
            //txSetFillColour(TX_WHITE);
            txSetFillColour(TX_BLACK);
            txClear();
            txSetColour(TX_WHITE);
            txTextOut(450, 200, "Уровень пройден");

            txSleep(4000);
            level = level + 1;

       //переход с 1 на 2 уровень
            if (level == 2)
            {
             //   pers1 = txLoadImage("Lvl21.bmp");
             //   pers2 = txLoadImage("222.bmp");
             //   pers3 = txLoadImage("Lvl23.bmp");
             //   pers4 = txLoadImage("Lvl24.bmp");
                life = 5;
                pers.x = 50;
                pers.y = 600;
                vragi[0].x = 500;    vragi[0].y = 300;
                vragi[1].x = 200;    vragi[1].y = 300;
                vragi[2].x = 700;    vragi[2].x = 300;
                vragi[3].x = 1000;   vragi[3].y = 300;
                vragi[4].x = 200;    vragi[4].y = 100;
                vragi[5].x = 500;    vragi[5].y = 100;
                vragi[6].x = 800;    vragi[6].y = 100;
                vragi[7].x = 350;    vragi[7].y = 600;
                vragi[8].x = 1000;  vragi[8].y = 600;
                vragi[9].x = 500;   vragi[9].y = 300;
                vragi[10].x = 700;   vragi[10].y = 600;
                vragi[11].x = -200;  vragi[11].y = 120;
                stary[0].x = 120;    stary[0].y = 200;
                stary[1].x = -220;   stary[1].y = 200;
                xvor = 300;  yvor = 700;
                xvor2 = 870; yvor2 = 700;
                xvor3 = 300; yvor3 = 300;
                xvor33 = -250; yvor33 = 100;
               // xhear = 50;  yhear = 50;
                xvixod = 1090; xvixod2 = 100;
                yvixod = 150;  yvixod2 = 100;
                xLife1 = 500;   yLife1 = 680;
                int xFon = 0;   int yFon = 800;
                life = 5;
               // xtext = 500;
               // ytext = 40;
                txSelectFont("Times New Roman",35);
               // txTextOut(xtext,ytext, "Уровень 2");
            }


           //переход с 2 на 3 уровень

           if(level == 3)
           {
                life = 5;
                pers.x = 150;
                pers.y = 650;
                vragi[0].x = 200;  vragi[0].y= 200;
                vragi[1].x = 450;  vragi[1].y = 290;
                vragi[2].x = 550;  vragi[2].y = 200;
                vragi[3].x = 670;  vragi[3].y = 290;
                vragi[4].x = 800;    vragi[4].y = 200;
                vragi[5].x = 1000;   vragi[5].y = 200;
                vragi[6].x = 500;    vragi[6].y = 500;
                vragi[7].x = 700;    vragi[7].y = 500;
                vragi[8].x = 490;  vragi[8].y = 800;
                vragi[9].x = 1090; vragi[9].y = 600;
                vragi[10].x = 800;  vragi[10].x = 710;
                vragi[11].x = 110;  vragi[11].y = 350;
                xvor = 1090;  yvor = 270;
                xvor2 = -870; yvor2 = -700;
                xvor3 = -300; yvor3 = -350;
                xvor33 = -340; yvor33 = 670;
                xlvl1 = 1000; ylvl1 = 100;
              //  xhear = 50;  yhear = 50;
                int xFon = 0; int yFon = 800;
                xvixod = 1090;
                yvixod = 150;
                xvixod2 = -100;
                yvixod2 = -100;
                xLife1 = 400;  yLife1 = 200;
                life = 5;
               // xtext = 500;
               // ytext = 40;

            }

           if(level == 4)
           {

                life = 5;
                pers.x = 910;
                pers.y = 300;
                vragi[0].x = 600;   vragi[0].y = 600;
                vragi[1].x = 1000;  vragi[1].y = 600;
                vragi[2].x = 220;   vragi[2].y = 300;
                vragi[3].x = -400;     vragi[3].y = 310;
                vragi[4].x = -600;     vragi[4].y = -100;
                vragi[5].x = -200;     vragi[5].y = -200;
                vragi[6].x = -500;     vragi[6].y = -500;
                vragi[7].x = -700;     vragi[7].y = -900;
                vragi[8].x = -490;    vragi[8].y = -700;
                vragi[9].x = -90;     vragi[9].y = -400;
                vragi[10].x = -300;    vragi[10].x = 298;
                vragi[11].x = -100;   vragi[11].y = 110;
                xvor = -300;  yvor = -700;
                xvor2 = -870;  yvor2 = -700;
                xvor3 = -300;  yvor3 = -350;
                xvor33 = -340; yvor33 = 670;
                xlvl1 = -1090; ylvl1 = -150;
            //    xhear = 50;   yhear = 50;
                int xFon = 0; int yFon = 800;
                xvixod = 800;
                yvixod = 600;
                xvixod2 = -100;
                yvixod2 = -100;
                xLife1 = -200;  yLife1 = -400;
                life = 5;
                //xtext = 500;
               // ytext = 40;

                }



           if(level == 5)
           {

                life = 5;
                pers.x = 910;
                pers.y = 300;
                vragi[0].x = -200;   vragi[0].y = 370;
                vragi[1].x = -200;   vragi[1].y = -300;
                vragi[2].x = -220;   vragi[2].y = 200;
                vragi[3].x = -400;     vragi[3].y = 310;
                vragi[4].x = -600;     vragi[4].y = -100;
                vragi[5].x = -200;     vragi[5].y = -200;
                vragi[6].x = -500;     vragi[6].y = -500;
                vragi[7].x = -700;     vragi[7].y = -900;
                vragi[8].x = -490;    vragi[8].y = -700;
                vragi[9].x = -90;     vragi[9].y = -400;
                vragi[10].x = -300;    vragi[10].x = 298;
                vragi[11].x = -100;   vragi[11].y = 110;
                xvor = 300;  yvor = 700;
                xvor2 = -870;  yvor2 = -700;
                xvor3 = -300;  yvor3 = -350;
                xvor33 = -340; yvor33 = 670;
                xlvl1 = -1090; ylvl1 = -150;
            //    xhear = 50;   yhear = 50;
                int xFon = 0; int yFon = 800;
                xvixod = 800;
                yvixod = 600;
                xvixod2 = -100;
                yvixod2 = -100;
                xLife1 = -200;  yLife1 = -400;
                life = 5;
                //xtext = 500;
               // ytext = 40;

                }
        }

            for (int I = 0; I < 12; I = I + 1)
                life = stolknovenieLife(pers.x, pers.y, vragi[I].x, vragi[I].y, life);

            life = stolknovenie2(pers.x, pers.y, xvor, yvor, life);
            life = stolknovenie2(pers.x, pers.y, xvor2, yvor2, life);
            life = stolknovenie2(pers.x, pers.y, xvor3, yvor3, life);
            life = stolknovenie5(pers.x, pers.y, xvor33, yvor33, life);
            life = stolknovenie9(pers.x, pers.y, xLife1, yLife1, &visibleLife1, life);
            life = stolknovenieM(pers.x, pers.y, xlvl1, ylvl1, life);


            for (int I = 0; I < 12; I = I + 1)
                pers.x = stolknovenie(pers.x, pers.y, vragi[I].x, vragi[I].y);

            pers.x = stolknovenie(pers.x, pers.y, xvor, yvor);
            pers.x = stolknovenie(pers.x, pers.y, xvor2, yvor2);
            pers.x = stolknovenie(pers.x, pers.y, xvor3, yvor3);
            pers.x = stolknovenie(pers.x, pers.y, xvor33,yvor33);
            pers.x = stolknovenie(pers.x, pers.y, xlvl1,ylvl1);

        }

        txSleep(2);
        txEnd();
    }


    return 0;
}

