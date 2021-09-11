int countingValleys(int steps, string path)
{
    int up = 0;       // uphill
    int dw = 0;       // downhill
    int vallyCnt = 0; // vally count
    bool isSL = true; // current position of hiker

    for (int i = 0; i < steps; i++)
    {
        if (path[i] == 'D')
        {
            if (isSL == true && up == 0)
            {
                dw++;
                vallyCnt++;
                isSL = false;
            }
            else if (up == 0)
            {
                dw++;
            }
            else
            {
                up--;
            }
            if (up == 0 && dw == 0)
                isSL = true;
        }
        else
        {
            if (dw == 0)
            {
                up++;
                isSL = false;
            }
            else
            {
                dw--;
            }
            if (up == 0 && dw == 0)
                isSL = true;
        }
    }

    return vallyCnt;
}