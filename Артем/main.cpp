#include "TXLib.h"
#include "Block.cpp"

struct Dragon
{
    int Dragonx;
    int y;
    int frameX;
    int frameY;
    int frame;
    int speed;
    int hpp;
    int posL;
    int posR;
    HDC picture;
    HDC hp;
    HDC hpEmpty;
};
const int STATE_LEFT = 0;
//������ ��� ����, ��������, ���� � �������...
void camers(int *cameraX, int *heroX, int *objcam, int *floorCam)
{
    if (*heroX < 940)
    {
        *cameraX = *cameraX + 13;                          //���
        *heroX = *heroX + 13;                              //�����
        *objcam = *objcam + 13;                            //�������
        *floorCam = *floorCam - 13;                        //���(�����)
    }
    else if (*heroX > 980)
    {
        *cameraX = *cameraX - 13;                          //���
        *heroX = *heroX - 13;                              //�����
        *objcam = *objcam - 13;                            //�������
        *floorCam = *floorCam + 13;                        //���(�����)
    }
 }
int main()
{
    txCreateWindow (1920, 1080);

    txDisableAutoPause();

    int MAX_HP = 300;
  //-----------------------------------------------------                          x - ���������� �� �����������, 0 - ������������� �� ������-�������� ����
  //����������:                                                                    y - ���������� �� ���������, 0 - ������������� �� ������ �������� ����
  //�����
    HDC main_hero = txLoadImage ("hero2.bmp");
    int heroY = 485;
    int heroX = 900;
    int vy = 3;  //v - �������� y - ���������� �� ��������� (�������� �� ���������)
    int heroFrameY = 0;  //�������� �������� ��������� ����
    int heroWidth = 200; //������ ���������� �����
    int frame = 0; //�������� ����� �� ����������� �� ���������� "cornercrop", �� ���� ��������� 1) 210 * 0 = 0, 2) 210 * 1 = 210, 3) 210 * 2 = 420 � ��� �����...
    int cornercrop = 210; //^ - ��� �� ��������
    int frameCount = 4; //���������� ��������� ������
  //COLORREF color = TX_GREEN; ����� �����
  //-----------------------------------------------------
    //�������� ������
    int cameraX = 2700;//�������� ������
    int objcam = 1500; //�������
    int floorCam = 400; //�������� ������ ���� (�����)
    //�����
    HDC block1 = txLoadImage ("floor_earth.bmp");
    int nBlocks = 3;
    Block blocks[nBlocks];
    blocks[0] = {-180, 800, 700, 212, block1};
    blocks[1] = {880, 800, 700, 212, block1};
    blocks[2] = {880, 300, 700, 102, block1};
    //���
    HDC thorn = txLoadImage ("thorn.bmp");
    int nThorns = 4;
    Thorn thorns[nThorns];
    thorns[0] = {100, 690, thorn};
    thorns[1] = {150, 690, thorn};
    thorns[2] = {1200, 690, thorn};
    thorns[3] = {1250, 690, thorn};
    //�������
    HDC tree1 = txLoadImage ("tree_kind_1.bmp");
    HDC tree2 = txLoadImage ("tree_kind_2.bmp");
    //�����
    HDC bush_berries = txLoadImage ("bush_kind_1.bmp");
    HDC bush1 = txLoadImage ("bush_kind_2.bmp");
    //������ ���
    HDC background = txLoadImage ("background_earth.bmp");
    //�������� ����� � ���
    HDC floor = txLoadImage ("floor_earth.bmp");
    HDC left_wall_earth = txLoadImage ("left_wall_earth.bmp");
    HDC wall_fill_earth = txLoadImage ("wall_fill_earth.bmp");
    int WBlock = 700;
    int HBlock = 212;
    //������ ��������
    HDC hp_barbg = txLoadImage ("hp_barbg.bmp");
    HDC hp_bar = txLoadImage ("hp_bar.bmp");
    int hp_points = 300;
    //���� ������
    HDC dragon = txLoadImage ("Dragon.bmp");
    HDC enemies_hp_bar = txLoadImage ("enemies_hp_bar.bmp");
    HDC enemies_hp_bar1 = txLoadImage ("enemies_hp_bar1.bmp");
    int nDragons = 3;
    Dragon dragons[nDragons];
    dragons[0] = {500, 750, 230, 0, 0, 15, 336, 500, 700, dragon, enemies_hp_bar, enemies_hp_bar1};
    dragons[1] = {1300, 600, 230, 0, 0, 15, 336, 1300, 1360, dragon, enemies_hp_bar, enemies_hp_bar1};
    dragons[2] = {200, 600, 230, 0, 0, 100, 1000, 200, 350, dragon, enemies_hp_bar, enemies_hp_bar1};
    //����
    HDC skill_bar_empty = txLoadImage ("skill_bar_empty.bmp");
    HDC skill_bar = txLoadImage ("skill_bar.bmp");
    int skill_time = 581;

    HDC attack_magic = txLoadImage ("attack_magic.bmp");
    HDC attack_magic1 = txLoadImage ("attack_magic1.bmp");
    int xbullet = 1000;
    int ybullet = 0;
    int speedbullet = 10;
    bool visiblebullet = false;
    //�������
    int tableX = -400;
    bool visibletabletext = false;
    HDC table = txLoadImage ("table.bmp");
          txPlaySound("run_grass.wav", SND_ASYNC);
    //----------------------------------------------------
    while (!GetAsyncKeyState(VK_ESCAPE))
    {   //���� ��� ������ �������
        txSetFillColor(TX_BLACK);
        txClear();

        camers(&cameraX, &heroX, &objcam, &floorCam);

        //���
        txBitBlt (txDC(), cameraX - 2200, 0, 4280, 1920, background, 0, 0);
        txBitBlt (txDC(), cameraX + 2000, 0, 4280, 1920, background, 0, 0);

        //�����
        for (int nomer1 = 0; nomer1 < nBlocks; nomer1 = nomer1 + 1)
        {
            drawBlock(blocks[nomer1], objcam);
            blockCollision(&heroX, &heroY, objcam, blocks[nomer1]);
        }
        //�������
        txTransparentBlt (txDC(), tableX + objcam, 700, 196, 235, table, 0, 0, TX_WHITE);
        //����
        int nomer = 0;
        while (nomer < nThorns)
        {
            txTransparentBlt (txDC(), objcam + thorns[nomer].x, thorns[nomer].y, 600, 600, thorns[nomer].picture, 0, 0, TX_WHITE);
            if (heroX + heroWidth   > objcam + thorns[nomer].x + 50 &&
                heroX               < objcam + thorns[nomer].x + 10 &&
                heroY + 420         > thorns[nomer].y)
            {
                hp_points = hp_points - 1;
            }
            nomer = nomer + 1;
        }
        //�������
        txTransparentBlt (txDC(), 400 + objcam, 155, 488, 796, tree1, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), -830 + objcam, 35, 486, 920, tree2, 0, 0, TX_WHITE);
        //���(�����)
        txTransparentBlt (txDC(), 0 - floorCam, 900, 7656, 312, floor, 0, 0, TX_WHITE);
        //����� ����� �����
        txTransparentBlt (txDC(), -1200 + objcam, 0, 312, 1840, left_wall_earth, 0, 0, TX_WHITE);
        //������� ����� �����
        if(heroX < -900 + objcam)
         {
            heroX = -900 + objcam;
         }
        //���������� ����� ����� �����
         txTransparentBlt (txDC(), -2270 + objcam, 0, 1080, 1920, wall_fill_earth, 0, 0, TX_WHITE);
         txTransparentBlt (txDC(), -2270 + objcam, 100, 1080, 1920, wall_fill_earth, 0, 0, TX_WHITE);
        //�����
        txTransparentBlt (txDC(), heroX, heroY, heroWidth, 440, main_hero, cornercrop * frame, heroFrameY, TX_WHITE);
        //�����
        //����� �� ������ ���� �����
        txTransparentBlt (txDC(), -200 + objcam, 677, 201, 136, bush_berries, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), -600 + objcam, 790, 223, 123, bush1, 0, 0, TX_WHITE);
        //������ �� ������ ���� �����
        txTransparentBlt (txDC(), 230 + objcam, 690, 223, 123, bush1, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), 120 + objcam, 690, 223, 123, bush1, 0, 0, TX_WHITE);
        //������ �������� ������� � ��������
        txTransparentBlt (txDC(), heroX - 45, heroY, 300, 20, hp_barbg, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), heroX - 45, heroY, hp_points * 300 / MAX_HP, 20, hp_bar, 0, 0, TX_WHITE);

        char str[100];
        sprintf(str, "HP: %d", hp_points);
        txTextOut(heroX - 10, heroY + 3, str);
        //������
        if(hp_points == 0)
          {
            return 0;
          }

        for (int nomer2 = 0; nomer2 < nDragons; nomer2 = nomer2 + 1)
        {
        txTransparentBlt (txDC(), dragons[nomer2].Dragonx + objcam, dragons[nomer2].y, 220, 148, dragons[nomer2].picture, dragons[nomer2].frameX * dragons[nomer2].frame, dragons[nomer2].frameY, TX_WHITE);

        dragons[nomer2].Dragonx = dragons[nomer2].Dragonx + dragons[nomer2].speed;

        if(dragons[nomer2].Dragonx + objcam < dragons[nomer2].posL + objcam)
          {
            dragons[nomer2].speed = 15;
            dragons[nomer2].frame = 0;
          }
        else if(dragons[nomer2].Dragonx + objcam > dragons[nomer2].posR + objcam)
          {
           dragons[nomer2].speed = -15;
           dragons[nomer2].frame = 1;
          }
        //������ �� ������
        txTransparentBlt (txDC(), dragons[nomer2].Dragonx + objcam + 80, dragons[nomer2].y - 30, 100, 27, dragons[nomer2].hpEmpty, 0, 0, TX_WHITE);
        txTransparentBlt (txDC(), dragons[nomer2].Dragonx + objcam + 80, dragons[nomer2].y - 30, dragons[nomer2].hpp /* * 100 / MAX_HP*/, 27, dragons[nomer2].hp, 0, 0, TX_WHITE);

        char str1[100];
        sprintf(str1, "HP: %d", dragons[nomer2].hpp);
        txTextOut(dragons[nomer2].Dragonx + objcam + 85, dragons[nomer2].y - 27, str1);

        if (dragons[nomer2].Dragonx + objcam < heroX + 150 && dragons[nomer2].Dragonx + objcam + 9 > heroX && dragons[nomer2].y - 455 < heroY)
        {
            hp_points = hp_points - 1;
        }
        //�������� �����
        if(xbullet < dragons[nomer2].Dragonx + objcam + 100 && xbullet > dragons[nomer2].Dragonx + objcam - 400 && visiblebullet)
         {
           dragons[nomer2].hpp = dragons[nomer2].hpp - 40;
         }
        if(dragons[nomer2].hpp < 0)
          {
            dragons[nomer2].y = 2000;
          }
        //�������� ����� �����
        if (txMouseButtons() == 1)
          {
            if(heroFrameY == 2000 && dragons[nomer2].Dragonx + objcam - 350 < heroX
             && dragons[nomer2].Dragonx + objcam + 150 > heroX  && dragons[nomer2].y - 455 < heroY)
              {
                 dragons[nomer2].hpp = dragons[nomer2].hpp - 10;
              }
            else if(heroFrameY == 2500 && dragons[nomer2].Dragonx + objcam - 150 < heroX
            && dragons[nomer2].Dragonx + objcam + 150 > heroX  && dragons[nomer2].y - 455 < heroY)
              {
                 dragons[nomer2].hpp = dragons[nomer2].hpp - 10;
             }
          }
        }

        //max hp
        if (hp_points >= MAX_HP)
            hp_points = MAX_HP;
        //����
         if (visiblebullet && heroFrameY == 2000 || visiblebullet && heroFrameY == 1000 || visiblebullet && heroFrameY == 0 && frame == 0)
         txTransparentBlt (txDC(), xbullet, ybullet + heroY, 125, 393, attack_magic, 0, 0, TX_WHITE);
         else if (visiblebullet && heroFrameY == 2500 || visiblebullet && heroFrameY == 500 || visiblebullet && heroFrameY == 0 && frame == 1)
         txTransparentBlt (txDC(), xbullet, ybullet + heroY, 125, 393, attack_magic1, 0, 0, TX_WHITE);
         if (visiblebullet)
         xbullet = xbullet + speedbullet;

         if (xbullet > 1700 || xbullet < 300)
         {
         visiblebullet = false;
         }
       //������ ������ ������� � ��������
        txTransparentBlt (txDC(), heroX - 45, heroY + 23, skill_time - 281, 10, skill_bar, 0, 0, TX_WHITE);

         if(GetAsyncKeyState('F') && !visiblebullet && skill_time > 580)
           {
             visiblebullet = true;
         if(heroFrameY == 2000 || heroFrameY == 1000 || heroFrameY == 0 && frame == 0)
           {
             speedbullet = 70;
           }
         else if(heroFrameY == 2500 || heroFrameY == 500 || heroFrameY == 0 && frame == 1)
           {
             speedbullet = -70;
           }
             skill_time = 270;
             xbullet = heroX + 50;
           }
         if(skill_time < 581)
           {
             skill_time = skill_time + 1;
           }
        //����� ������� 1
        if (visibletabletext)
        {
            txSetColor(TX_WHITE);
            txSetFillColor(TX_BLACK);
            POINT tTriangle[3] = {
            {-390 + objcam, 650},
            {-220 + objcam, 650},
            {-300 + objcam, 690}
            };
            txPolygon (tTriangle, 3);
            txRectangle(-500 + objcam, 450, -100 + objcam, 650);

            txSetFillColor (TX_WHITE);
            txSelectFont ("Arial", 20, 0, FW_BOLD);
            txDrawText  (-500 + objcam, 450, -100 + objcam, 650, "���������� (��� ������ ����������):\n"
                                                                 "\n"
                                                                 "������ ����� (A ��� ������� �����); \n"
                                                                 "������ ������ (D ��� ������� ������);\n"
                                                                 "������ (������(SPACE));\n"
                                                                 "�����(���)(��������� ����� ������ ������: ���� ������ � ���������); \n"
                                                                 "�����(�������)(F);\n");
        }

        visibletabletext = (heroX < tableX + 200 + objcam &&
                            heroX > tableX + objcam - 200);
        //--------------------------------------------------------------------------------------------------------
        //�������� ������
        //���� ����������
        if (heroY < 1000)
            heroY = heroY + vy;
            vy = vy + 1;
        //������ ������
        if(GetAsyncKeyState(VK_SPACE) && vy > 25)
        {   //��������
        if (heroY > 300)
              vy = -17;
            heroY = heroY + vy;
        }
        //�������� ������
        if(GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT))
        {
          //��������
          heroX = heroX + 13;
          //��������
          frame = frame + 1;
          heroFrameY = 1000;
          heroWidth = 200;
          cornercrop = 210;
          frameCount = 4;
        }
        //�������� �����
        else if(GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT))
        {
           //��������
           heroX = heroX - 13;
           //��������
           frame = frame + 1;
           heroFrameY = 500;
           heroWidth = 200;
           cornercrop = 210;
           frameCount = 4;
        }
        //���� �����
        else if (txMouseButtons() == 1)//GetAsyncKeyState('F'))
        {
            //��������
             frame = frame + 1;

             if (txMouseX() > heroX)//heroFrameY == 1000 || heroFrameY == 0 && frame == 0)
                heroFrameY = 2000;
             else if (txMouseX() < heroX)//heroFrameY == 500 || heroFrameY == 0 && frame == 1)
                heroFrameY = 2500;

             heroWidth = 325;
             cornercrop = 325;
             frameCount = 3;
        }

        //���� ������� ����� ����� � �� ���������, �� �������� �������� � ������� �� �������
        else
        {   //��������
            if (heroFrameY == 2500 || heroFrameY == 500)
               {
                frame = 1;
                frameCount = 2;
                heroFrameY = 0;
               }
            else if (heroFrameY == 2000 || heroFrameY == 1000)
               {
                frame = 0;
                frameCount = 1;
                heroFrameY = 0;
               }
            heroFrameY = 0;
            heroWidth = 210;
            cornercrop = 210;
            txPlaySound(NULL);
          txPlaySound("run_grass.wav", SND_ASYNC);
        }

        //������������ �������� - ����������� �� ������ ����
        if (frame >= frameCount)
           {
            frame = 0;
           }
        //���������
        if(GetAsyncKeyState(VK_LSHIFT))
          {
            if(GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT))
             {
              heroX = heroX - 15;
              objcam = objcam + 10;
              floorCam = floorCam - 10;
              cameraX = cameraX + 10;
             }
            else if(GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT))
             {
              heroX = heroX + 15;
              objcam = objcam - 10;
              floorCam = floorCam + 10;
              cameraX = cameraX - 10;
             }
          }
        // if(heroFrameY == 500 || heroFrameY == 1000)
        //  txPlaySound("run_grass.wav", SND_ASYNC);
        // else
          //  txPlaySound(NULL);
        //������� �������� ����� �������� �� ������� �� �����
        //������� ������ ��� ������
        if(heroX > 1000)
        {
            heroX = 1000;
        }
        //������� ����� ��� ������
        if(heroX < 900)
        {
            heroX = 900;
        }
        //������� ������ ��� ������
        if(heroY < 50)
        {
            heroY = 50;
        }
        //������� ����� ��� ������
        if(heroY > 485)
        {
            heroY = 485;
        }
//----------------------------------------------------------------------------------------------------------

        txSleep(20);
    }

     txDeleteDC (background);
    return 0;
}

