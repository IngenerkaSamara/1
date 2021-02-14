#include "TXLib.h"


int stolknovenie (int xPers, int yPers, int x2, int y2)
{
    if(xPers + 30 > x2)
    if(yPers + 30 > y2)
    if(xPers - 30 < x2 + 100)
    if(yPers - 30 < y2 + 100)
    {
        //life = life - 1;
        xPers = 100;
        yPers = 600;
    }
    return xPers;
}


int stolknovenieLife (int xPers, int yPers, int x2, int y2, int life)
{
    if(xPers + 30 > x2)
    if(yPers + 30 > y2)
    if(xPers - 30 < x2 + 100)
    if(yPers - 30 < y2 + 100)
    {
        life = life - 1;
        txPlaySound("Music/hit1.wav");
    }
    return life;
}


int stolknovenie2(int xPers, int yPers, int x2, int y2, int life)
{
    if(xPers + 30 > x2)
    if(yPers + 30 > y2)
    if(xPers - 30 < x2 + 100)
    if(yPers - 30 < y2 + 100)
    {
        life = life - 3;
        txPlaySound("Music/hit1.wav");
    }
    return life;
  }


int stolknovenie5(int xPers, int yPers, int xvor33, int yvor33, int life)
{
    if(xPers + 30 > xvor33)
    if(yPers + 30 > yvor33)
    if(xPers - 30 < xvor33 + 100)
    if(yPers - 30 < yvor33 + 100)
    {
        life = life - 4;

        txPlaySound("Music/hit1.wav");
    }
    return life;
  }

int stolknovenie51(int xPers, int yPers, int xvor33, int yvor33, int life)
{
    if(xPers + 30 > xvor33)
    if(yPers + 30 > yvor33)
    if(xPers - 30 < xvor33 + 100)
    if(yPers - 30 < yvor33 + 100)
    {
        xPers = 100;
        yPers = 600;
    }
    return xPers;
  }

  int stolknovenie9(int xPers, int yPers, int xLife1, int yLife1, bool* visibleLife1, int life)
{
    if(xPers + 30 > xLife1)
    if(yPers + 30 > yLife1)
    if(xPers - 30 < xLife1 + 100)
    if(yPers - 30 < yLife1 + 100)
    if(*visibleLife1)
    {
        life = life + 2;
        *visibleLife1 = false;
    }
    return life;
  }

    int stolknovenieM(int xPers, int yPers, int xlvl1, int ylvl1, int life)
{
    if(xPers + 30 > xlvl1)
    if(yPers + 30 > ylvl1)
    if(xPers - 30 < xlvl1 + 100)
    if(yPers - 30 < ylvl1 + 100)
    {
        life = life - 5;
    }
    return life;
  }
