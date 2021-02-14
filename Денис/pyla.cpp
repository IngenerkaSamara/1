//Штукенция по работе с пулей

struct Pyla
{
    int x;
    int y;
    int Napravl;
    HDC picture;
    bool vidna;
};

void movePyla(Pyla* pyla)
{
    if (pyla->vidna == true)
    {
        if (pyla->Napravl == 1)
            pyla->x = pyla->x - 50;
        if (pyla->Napravl == 2)
            pyla->x = pyla->x + 50;
        if (pyla->Napravl == 3)
            pyla->y = pyla->y - 50;
        if (pyla->Napravl == 4)
            pyla->y = pyla->y + 50;
        if (pyla->Napravl == 5)
        {
            pyla->x = pyla->x + 35;
            pyla->y = pyla->y + 35;
        }
        if (pyla->Napravl == 6)
        {
            pyla->x = pyla->x - 35;
            pyla->y = pyla->y + 35;
        }
        if (pyla->Napravl == 7)
        {
            pyla->x = pyla->x + 35;
            pyla->y = pyla->y - 35;
        }
        if (pyla->Napravl == 8)
        {
            pyla->x = pyla->x - 35;
            pyla->y = pyla->y - 35;
        }
    }

    if (pyla->x > txGetExtentX() or
        pyla->x < -100 or
        pyla->y > txGetExtentY() or
        pyla->y < -100)
    {
        pyla->vidna = false;
    }
}
