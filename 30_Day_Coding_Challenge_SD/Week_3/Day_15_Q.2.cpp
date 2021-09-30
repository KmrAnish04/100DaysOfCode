void kaprekarNumbers(int p, int q)
{
    vector<int> ans;

    for (int i = p; i <= q; i++)
    {
        string str = to_string(i);
        long long sqNum = (long long)i * i;
        string sqStr = to_string(sqNum);
        int strLen = str.size();
        int sqStrLen = sqStr.size();

        if (strLen < 2)
        {
            if (i == 1 || i == 9)
                ans.push_back(i);
        }
        else
        {
            string r = sqStr.substr(sqStrLen - strLen, strLen);
            string l = sqStr.substr(0, sqStrLen - strLen);
            int sum = stoi(l) + stoi(r);

            if (i == sum)
            {
                ans.push_back(i);
            }
        }
    }
    if (ans.size() > 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i != ans.size() - 1)
                cout << " ";
        }
    }
    else
        cout << "INVALID RANGE";
}