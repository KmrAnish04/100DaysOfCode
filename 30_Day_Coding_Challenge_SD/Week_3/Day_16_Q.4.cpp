int workbook(int n, int k, vector<int> arr) {
    int count,pg;
    count=pg=0;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=arr[i];j++)
        { 
            if(k==1 || j%k==1)
                pg++;
            if(j==pg)
                count++;
            }
    }
    cout<<count;
    return count;
}
