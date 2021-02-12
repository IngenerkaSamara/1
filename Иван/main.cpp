#include "TXLib.h"
#include <string>
#include <iostream>
#include <ctime>

void draw_beta(){
    // BETA
    txSetColor(TX_BLACK);
    txSelectFont("Courier New", 40, 20);
    txTextOut(50, 550, "ALPHA 1.9");
}

struct Button
{
    int x;
    int y;
    int x2;
    int y2;
    const char* text;
    HDC picture;
};

void drawButton(Button btn) {
    if(btn.text != ""){
        txDrawText(btn.x, btn.y, btn.x2, btn.y2, btn.text);
    }
    if (btn.picture != nullptr)
        txBitBlt(txDC(), btn.x, btn.y, btn.x2-btn.x, btn.y2 - btn.y, btn.picture);
}

bool clickButton(Button btn)
{
    if (txMouseX() > btn.x && txMouseX() < btn.x2
        && txMouseY() > btn.y && txMouseY() < btn.y2
        && txMouseButtons() == 1){
        return true;
    }
    else
        return false;
}

int main()
    {
    txCreateWindow (800, 600);

    int years = 20;
    string nick = "Anonimys228";
    string player_rank = "beginner";
    int money = 1000;
    int health = 100;
    int month = 1;
    int year = 1;
    //string news = "Сегодня хорошая погода";

    //число
    int weed_count = 0;
    int crack_count = 0;
    int lsd_count = 0;
    int mushrooms_count = 0;
    int cocaine_count = 0;

    int scroll_y = 0;

    //cords
    int y_bag = 50;
    int y2_bag = y_bag + 50;

    // жЭКА БАУНТИ
    HDC zheka = txLoadImage("zhekabaunti.bmp");
    HDC zheka2 = txLoadImage("zheka.bmp");

    HDC vzlom =  txLoadImage("vzlom.bmp");

    // иконки
    HDC crack = txLoadImage("crack.bmp");
    HDC weed = txLoadImage("kanna.bmp");
    HDC lsd = txLoadImage("lsd.bmp");
    HDC grib = txLoadImage("mushroom.bmp");
    HDC cocaine = txLoadImage("cocaine.bmp");

//    HDC coffee = txLoadImage("coffee.bmp");
    HDC weed_real = txLoadImage("kanna_real.bmp");

    HDC ramka = txLoadImage("ramka.bmp");

    HDC coco_real = txLoadImage("coco_real.bmp");
    HDC lsd_real = txLoadImage("lsd_real.bmp");

    HDC kot = txLoadImage("кот.bmp");

    HDC op = txLoadImage("op.bmp");
    HDC gang = txLoadImage("gangsta.bmp");

    // фон меню
    HDC narko = txLoadImage("trava.bmp");
    HDC a = txLoadImage("prof.bmp");
    HDC loko = txLoadImage("lokomoko.bmp");

    // avi
    HDC ava = txLoadImage("ava.bmp");
    HDC vzlom2 = txLoadImage("vzlom2.bmp");

    HDC magnum = txLoadImage("magnum.bmp");
    HDC magnum2 = txLoadImage("magnum2.bmp");

    HDC floppa2 = txLoadImage("floppa2.bmp");
    HDC mama2 = txLoadImage("mama2.bmp");

    HDC floppa = txLoadImage("floppa.bmp");
    HDC mama = txLoadImage("mama.bmp");

    HDC garden = txLoadImage("garden.bmp");
    HDC garden2 = txLoadImage("garden2.bmp");


    HDC menu = a;
    bool nrk = true;

    char str[200];

    int crack_price = 7890;
    int weed_price = 550;
    int lsd_price = 985;
    int mushrooms_price = 431;
    int cocaine_price = 5750;

    // random

    Button menuBtn = {150, 300, 650, 350, "Стать Наркоторговцем", nullptr};

    Button bagpackBtn = {400, 2, 420, 22, "", txLoadImage("Pictures/bag-pack.bmp")};


    Button avasBtn ={500, 2, 520, 22, "", txLoadImage("avas.bmp")};


    Button selects[6];
    selects[0] = {50, 270, 250,  300,  "Выбрать",  nullptr};
    selects[1] = {300, 270, 500, 300, "Выбрать", nullptr};
    selects[2] = {550, 270, 750, 300, "Выбрать", nullptr};
    selects[3] = {50, 500, 250,  550,  "Выбрать",  nullptr};
    selects[4] = {300, 500, 500, 550, "Выбрать", nullptr};
    selects[5] = {550, 500, 750, 550, "Выбрать", nullptr};

    /*Button select1 = {50, 270, 250,  300,  "Выбрать",  nullptr};
    Button select2 = {300, 270, 500, 300, "Выбрать", nullptr};
    Button select3 = {550, 270, 750, 300, "Выбрать", nullptr};
    Button select4 = {50, 500, 250,  550,  "Выбрать",  nullptr};
    Button select5 = {300, 500, 500, 550, "Выбрать", nullptr};
    Button select6 = {550, 500, 750, 550, "Выбрать", nullptr};*/

    Button buy1 = {500, 280 - scroll_y, 600, 315 - scroll_y, "BUY", nullptr};
    Button buy2 = {490, 2, 510, 22, "BUY", nullptr};
    Button buy3 = {490, 2, 510, 22, "BUY", nullptr};
    Button buy4 = {490, 2, 510, 22, "BUY", nullptr};
    Button buy5 = {490, 2, 510, 22, "BUY", nullptr};

    string PAGE = "Menu";

    while(!GetAsyncKeyState(VK_ESCAPE)){
        txBegin();


        // текст
        if(PAGE == "Menu") {
            txSetColor(TX_YELLOW);
            txSelectFont("Arial", 40, 10, 5);
            txDrawText(300, 50, 500, 200, "Кем Вы Станете?");
            txBitBlt(txDC(), 0, 0, 800, 600, menu, 0, 0);

            // быть наркоторговцем
            if(nrk == true){
                txSetFillColor(RGB(212, 212, 212));
                txRectangle(150, 300, 650, 350);
                txSetColor(RGB(181, 230, 29));
                txSelectFont("Courier New", 20, 10);
                drawButton(menuBtn);
            }

            if (txMouseX() > 150 && txMouseX() < 650 && txMouseY() > 300 && txMouseY() < 350){
                menu = narko;
            }
            else{
                menu = a;
            }

            if (clickButton(menuBtn)) {
                PAGE = "market";
            }
        }

        //easteregg
        else if(PAGE == "kot"){
            txBitBlt(txDC(), 0, 0, 800, 600, kot, 0, 0);
            txSelectFont("Arial", 30, 20);
            txDrawText(200, 200, 600, 600,
                "ОПА, ВЫ НАШЛИ СУПЕР \n"
                "РЕДКУЮ ПАСХАЛУ \n ОНА ОЧЕНЬ РЕДКАЯ \n \n  СКРИНЬТЕ");
        }

        else if(PAGE == "Change"){
            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);


        }

        //Рынок
        else if (PAGE == "market") {

            nrk = false;
            txBitBlt(txDC(), 0, 0, 800, 600, loko, 0, 0);
            txSetFillColor(RGB(192, 192, 192));
            txRectangle(0, 0, 800, 600);

            if(GetAsyncKeyState('B')){
                money = money + 10000;
            }

            if (clickButton(bagpackBtn)) {
                PAGE = "Инвентарь";}

            if(clickButton(avasBtn)){
                PAGE = "AVAS" ;
            }

            txSetFillColor(TX_BLACK);
            txRectangle(0, 0, 800, 25);

            txSetFillColor(TX_WHITE);

            txCircle(410, 12, 15);
            drawButton(bagpackBtn);

            txCircle(510, 12, 15);
            drawButton(avasBtn);




            // данные о игроке
            txSetFillColor(TX_WHITE);
            txSetColor(TX_RED);
            txRectangle(50, 25, 750, 125);

            txBitBlt(txDC(), 60, 35, 50, 50, ava, 0, 0);

            txSetColor(TX_BLACK);
            txSelectFont("Arial", 20, 10, 10);
            txTextOut(120, 35, nick.c_str());

            txSetColor(TX_BLACK);
            txSelectFont("Lucida Console", 20, 10, 1);

            sprintf(str, "years: %d", years);
            txTextOut(120, 65, str);

            txTextOut(120, 95, "rank: ");
            txTextOut(180, 95, player_rank.c_str());

            //Здлоровье
            sprintf(str, "Health: %d", health);
            txTextOut(310, 35, str);

            txSetFillColor(RGB(237, 28, 36));
            txRectangle(550, 25, 750, 75);


            sprintf(str, "%d $", money);
            txTextOut(600, 35, str);

            txSetColor(RGB(213, 213, 213));
            txTextOut(600, 55, "Bank Balance");



            // дата и город
            txSetFillColor(TX_WHITE);
            txRectangle(50, 150, 750, 250);



            txSetFillColor(RGB(213, 213, 213));
            txRectangle(50, 150, 750, 175);
            txSetColor(TX_RED);
            txSetFillColor(TX_WHITE);
            txRectangle(50, 175, 750, 200);



            txSetColor(TX_BLACK);
            txSelectFont("Lucida Console", 20, 15);
            sprintf(str, "%d years", year);
            txTextOut(60, 155, str);

            sprintf(str, "%d months", month);
            txTextOut(200, 155, str);

            txTextOut(400, 155, "Kiev, Ukrain");

            txSetColor(TX_BLACK);
            txTextOut(60, 180, "News, Rumors, Etc");

            txTextOut(60, 205, "Сегодня хорошая погода");

            if(money >= 50000){
            player_rank = "zakladik";
            }

            if(GetAsyncKeyState('I')){
                PAGE = "kot";
            }


            // marketplace

            txSetFillColor(TX_WHITE);
            txRectangle(50, 250, 750, 525);
            txSetFillColor(RGB(237, 28, 36));
            txRectangle(50, 250, 750, 275);
            txTextOut(330, 255, "Marketplace");

            // выбор авы
            if(GetAsyncKeyState('N')){
                PAGE = "Change";
            }

            if(GetAsyncKeyState(VK_DOWN)){
                scroll_y = scroll_y + 10;
            }

            if(GetAsyncKeyState(VK_UP)){
                scroll_y = scroll_y - 10;
            }

            // первый товар
            txSetColor(TX_BLACK);
            txSetFillColor(TX_WHITE);
            txSelectFont("Lucida Console", 20, 15);
            txRectangle(50, 275 - scroll_y, 750, 325 - scroll_y);
            txTextOut(120, 280 - scroll_y, "Crack");
            txBitBlt(txDC(), 60, 280 - scroll_y, 50, 50, crack, 0, 0);

            sprintf(str, "%d $", crack_price);
            txTextOut(300, 280 - scroll_y, str);
            txRectangle(500, 280 - scroll_y, 600, 315 - scroll_y);

            drawButton(buy1);
            if(clickButton(buy1) && money >= crack_price){
                crack_count = crack_count + 1;
                money = money - crack_price;}


            //2
            txRectangle(50, 325 - scroll_y, 750, 375 - scroll_y);

            txBitBlt(txDC(), 60, 330 - scroll_y, 50, 50, weed, 0, 0);
            txTextOut(120, 330 - scroll_y, "Weed");

            sprintf(str, "%d $", weed_price);
            txTextOut(300, 330 - scroll_y, str);

            txRectangle(500, 330 - scroll_y, 600, 365 - scroll_y);
            txTextOut(520, 335 - scroll_y, "BUY");

            // третий штук
            txRectangle(50, 375 - scroll_y, 750, 425 - scroll_y);

            txBitBlt(txDC(), 60, 380 - scroll_y, 40, 40, lsd, 0, 0);

            txTextOut(120, 380 - scroll_y, "LSD");

            sprintf(str, "%d $", lsd_price);
            txTextOut(300, 380 - scroll_y, str);

            txRectangle(500, 380 - scroll_y, 600, 415 - scroll_y);
            txTextOut(520, 385 - scroll_y, "BUY");

            //4 грибчански
            txRectangle(50, 425 - scroll_y, 750, 475 - scroll_y);

            txBitBlt(txDC(), 60, 430 - scroll_y, 40, 40, grib, 0, 0);

            txTextOut(120, 430 - scroll_y, "Mushrooms");

            sprintf(str, "%d $", mushrooms_price);
            txTextOut(300, 430 - scroll_y, str);

            txRectangle(500, 430 - scroll_y, 600, 465 - scroll_y);
            txTextOut(520, 435 - scroll_y, "BUY");

            //5
            txRectangle(50, 475 - scroll_y, 750, 525 - scroll_y);

            txBitBlt(txDC(), 60, 480 - scroll_y, 40, 40, cocaine, 0, 0);

            txTextOut(120, 480 - scroll_y, "Cocaine");

            sprintf(str, "%d $", cocaine_price);
            txTextOut(300, 480 - scroll_y, str);

            txRectangle(500, 480 - scroll_y, 600, 515 - scroll_y);
            txTextOut(520, 485 - scroll_y, "BUY");

            draw_beta();


            // кнопка
            txSetFillColor(RGB(237, 28, 36));

            txCircle(350, 560, 20);
            txCircle(450, 560, 20);
            txRectangle(350, 540, 450, 580);

            txSetColor(RGB(237, 28, 36));
            txLine(350, 540, 350, 580);
            txLine(450, 540, 450, 580);

            txSetColor(TX_BLACK);
            txSelectFont("Arial", 20);
            txTextOut(355, 550, "GO");



            if(txMouseX() > 350 && txMouseX() < 450
                && txMouseY() > 545 && txMouseY() < 580
                && txMouseButtons() == 1){
                crack_price = random(5000, 9000);
                weed_price = random(200, 1000);
                lsd_price = random(500, 2000);
                mushrooms_price = random(200, 1000);
                cocaine_price = random(3000, 7000);

                if(month < 12){
                    month = month + 1;}
                else{
                    month = 1;
                    years = years + 1;
                    year = year + 1;
                }
            }                                               //500, 280, 600, 315

            //purchase

            if(txMouseX() > 500 && txMouseX() < 600
            && txMouseY() > 330 && txMouseY() < 365
            && txMouseButtons() == 1 && money >= weed_price){
                weed_count = weed_count + 1;
                money = money - weed_price;
            }

            if(txMouseX() > 500 && txMouseX() < 600
            && txMouseY() > 380 && txMouseY() < 415
            && txMouseButtons() == 1 && money >= lsd_price){
                lsd_count = lsd_count + 1;
                money = money - lsd_price;
            }
            if(txMouseX() > 500 && txMouseX() < 600
            && txMouseY() > 430 && txMouseY() < 465
            && txMouseButtons() == 1 && money >= mushrooms_price){
                mushrooms_count = mushrooms_count + 1;
                money = money - mushrooms_price;
            }
            if(txMouseX() > 500 && txMouseX() < 600
            && txMouseY() > 480 && txMouseY() < 515
            && txMouseButtons() == 1 && money >= cocaine_price){
                cocaine_count = cocaine_count + 1;
                money = money - cocaine_price;
            }


            //бэгпэк

        }

        //Инвентарь
        else if(PAGE == "Инвентарь"){
            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);

            txSetFillColor(TX_WHITE);
            txSetColor(RGB(237, 28, 36));

            txRectangle(50, 50, 750, 550);



            txSetFillColor(RGB(237, 28, 36));
            txRectangle(400, 200, 450, 235);
            txSetColor(TX_BLACK);
            txTextOut(405, 205, "Sell");

            txSetFillColor(RGB(237, 28, 36));
            txRectangle(400, 250, 450, 285);
            txSetColor(TX_BLACK);
            txTextOut(405, 255, "Sell");

            txSetFillColor(RGB(237, 28, 36));
            txRectangle(400, 300, 450, 335);
            txSetColor(TX_BLACK);
            txTextOut(405, 305, "Sell");

            txSetFillColor(RGB(237, 28, 36));
            txRectangle(400, 350, 450, 385);
            txSetColor(TX_BLACK);
            txTextOut(405, 355, "Sell");

            txSetFillColor(RGB(237, 28, 36));
            txRectangle(400, 400, 450, 435);
            txSetColor(TX_BLACK);
            txTextOut(405, 405, "Sell");


            //продажа
            if(txMouseX() > 400 && txMouseX() < 450
            && txMouseY() > 200 && txMouseY() < 235
            && txMouseButtons() == 1 && crack_count >= 1){
                crack_count = crack_count - 1;
                money = money + crack_price;
            }

            if(txMouseX() > 400 && txMouseX() < 450
            && txMouseY() > 250 && txMouseY() < 285
            && txMouseButtons() == 1 && weed_count >= 1){
                weed_count = weed_count - 1;
                money = money + weed_price;
            }

            if(txMouseX() > 400 && txMouseX() < 450
            && txMouseY() > 300 && txMouseY() < 335
            && txMouseButtons() == 1 && lsd_count >= 1){
                lsd_count = lsd_count - 1;
                money = money + lsd_price;
            }

            if(txMouseX() > 400 && txMouseX() < 450
            && txMouseY() > 350 && txMouseY() < 385
            && txMouseButtons() == 1 && mushrooms_count >= 1){
                mushrooms_count = mushrooms_count - 1;
                money = money + mushrooms_price;

            }

            if(txMouseX() > 400 && txMouseX() < 450
            && txMouseY() > 400 && txMouseY() < 435
            && txMouseButtons() == 1 && cocaine_count >= 1){
                cocaine_count = cocaine_count - 1;
                money = money + cocaine_price;

            }

            sprintf(str, "У вас %d килограмм крэка", crack_count);
            txTextOut(200, 200, str);

            sprintf(str, "У вас %d пакетиков травы", weed_count);
            txTextOut(200, 250, str);

            sprintf(str, "У вас %d штучек элесде", lsd_count);
            txTextOut(200, 300, str);

            sprintf(str, "У вас %d грибов", mushrooms_count);
            txTextOut(200, 350, str);

            sprintf(str, "У вас %d грамм кокаина", cocaine_count);
            txTextOut(200, 400, str);



        }

        else if(PAGE == "QA"){
            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);
            y_bag = 100;
            while(y_bag <= 400){
                txSetFillColor(TX_WHITE);
                txSetColor(TX_BLACK);
                txRectangle(50, y_bag, 750, y_bag + 250);
                y_bag = y_bag + 50;
            }

            txSetColor(TX_BLACK);
            txSelectFont("Arial", 30);
            txTextOut(70, 110, "ПОЧЕМУ КРЭК ПО КОНСКОЙ ЦЕНЕ?");
            if(txMouseX() > 50 && txMouseX() < 750
                && txMouseY() > 100 && txMouseY() < 200
                && txMouseButtons() == 1){

                PAGE = "Quest1";

                }
            txTextOut(70, 200, "ПОЧЕМУ НА АВЕ СИДИТ ЖЕКИЧ БАУНТИ И СЕРЕГА СНИКЕРС?");
            if(txMouseX() > 50 && txMouseX() < 750
                && txMouseY() > 205 && txMouseY() < 245
                && txMouseButtons() == 1){

                PAGE = "Quest2";
            }

            txTextOut(70, 250, "Законна ли эта игра?");
            if(txMouseX() > 50 && txMouseX() < 750
                && txMouseY() > 250 && txMouseY() < 300
                && txMouseButtons() == 1){

                PAGE = "Quest3";
            }
        }


        else if(PAGE == "Quest1") {
            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);

            txSetFillColor(TX_WHITE);
            txRectangle(200, 100, 750, 500);

            txDrawText(200, 100, 750, 500, "В 1х Покупка на целый район и банду.\n\n И ваще ЧЕ ХАЧУ ТО И ДеЛАЮ");
        }


        else if(PAGE == "Quest2"){
            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);

            txSetFillColor(TX_WHITE);
            txRectangle(200, 100, 750, 500);

            txDrawText(200, 100, 750, 500,"ОНИ ПРИКОЛЬНЫЕ ПАЦАНЫ \n И ЧЕ ХАЧУ ТО И ДЕЛАЮ!!!!\n И НИКТО МНЕ НЕ ПОМЕШАЕТ!!!!");
        }

        else if(PAGE == "Quest3"){

            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);

            txSetFillColor(TX_WHITE);
            txRectangle(200, 100, 750, 500);


            txDrawText(200, 100, 750, 500,"КОНЕЧНО ЖЕ НЕТ И КОГДА ВЫ ЭТО ЧИТАЕТЕ \n К ВАМ УЖЕ СОБИРАЕТСЯ НАРЯД");
        }
        else if(PAGE == "Quest4"){
            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);

            txSetFillColor(TX_WHITE);
            txRectangle(200, 100, 750, 500);

            txDrawText(200, 100, 750, 500,"КОНЕЧНО ЖЕ ДА и  Вся ИгРа написона Под Кайфом ТЯЖЕЛЫХ НАРКОТИКОВ\n и У АВТОРА ДОМА \n 18 КГ ГЕРОИНА и ПОДДЕЛЬНЫЕ ДЕНЬГИ\n ВОТ АДРЕСС 19414, Сумська область, місто Суми, пров. Володимирська, 89 !!!");
        }

        else if(PAGE == "Police"){

            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);

            txBitBlt(txDC(), 50, 50, 200, 300, gang, 0, 0);

        }

        else if(PAGE == "AVAS"){
            txSetFillColor(RGB(195, 195, 195));
            txRectangle(0, 0, 800, 600);

            txBitBlt(txDC(), 50, 50, 200, 200, vzlom2, 0, 0);
            txBitBlt(txDC(), 300, 50, 200, 200, zheka2, 0, 0);
            txBitBlt(txDC(), 550, 50, 200, 200, magnum2, 0, 0);
            txBitBlt(txDC(), 50, 300, 200, 200, floppa2, 0, 0);
            txBitBlt(txDC(), 300, 300, 200, 200, garden2, 0, 0);
            txBitBlt(txDC(), 550, 300, 200, 200, mama2, 0, 0);

            txSetColor(TX_BLACK);

            txRectangle(50, 270, 250,  300);
            txRectangle(300, 270, 500, 300);
            txRectangle(550, 270, 750, 300);
            txRectangle(50, 500, 250,  550);
            txRectangle(300, 500, 500,  550);
            txRectangle(550, 500, 750,  550);

            drawButton(selects[0]);
            drawButton(selects[1]);
            drawButton(selects[2]);
            drawButton(selects[3]);
            drawButton(selects[4]);
            drawButton(selects[5]);

            if(clickButton(selects[0])){
                ava = vzlom;
            }
            if(clickButton(selects[1])){
                ava = zheka;
            }
            if(clickButton(selects[2])){
                ava = magnum;
            }
            if(clickButton(selects[3])){
                ava = floppa;
            }
            if(clickButton(selects[4])){
                ava = garden;
            }
            if(clickButton(selects[5])){
                ava = mama;
            }


        }



        if(GetAsyncKeyState(VK_SPACE)){
            PAGE = "market";
        }

        txSleep(10);
        txEnd();
    }

    txDeleteDC(menu);
    txDeleteDC(narko);
    txDeleteDC(loko);
    txDeleteDC(a);
    txDeleteDC(ava);
    txDeleteDC(crack);
    txDeleteDC(lsd);
    txDeleteDC(grib);
    txDeleteDC(cocaine);
    txDeleteDC(kot);
    txDeleteDC(floppa);
    txDeleteDC(floppa2);
    txDeleteDC(magnum2);
    txDeleteDC(magnum);
    txDeleteDC(mama2);
    txDeleteDC(mama);

    return 0;
}


