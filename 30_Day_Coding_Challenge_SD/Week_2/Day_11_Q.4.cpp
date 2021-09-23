int jumpingOnClouds(vector<int> c)
{
    int jmpCnt = 0;
    int mxJmp = 2;
    int curPos = 0;

    if (c.size() == 1)
        return 0;
    if (c.size() == 2)
        return 1;

    while (curPos != c.size() - 1)
    {
        if (c[mxJmp] == 0)
        {
            curPos = mxJmp;
            jmpCnt++;
            mxJmp += 2;
        }
        else
        {
            curPos = mxJmp - 1;
            jmpCnt++;
            mxJmp = curPos + 2;
        }

        if (curPos == c.size() - 2 || curPos == c.size() - 3)
        {
            jmpCnt += 1;
            curPos = c.size() - 1;
        }
    }

    return jmpCnt;
}
