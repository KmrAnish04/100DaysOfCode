int squares(int a, int b) {
    float sqtAf=sqrt(a);
    int sqtAi=sqrt(a);
    int diff= sqtAf-sqtAi;
    int fstNum;
    int cnt=0;
    
    if(diff==0) cnt++;
    while(diff!=0 && a<=b){
        a++;
        diff=sqtAf-sqtAi;
        if(diff==0) cnt++;
    }
    if(a>b) return 0;
    else if(a==b) return 1;
    fstNum=a;
    
    if(fstNum<b){
        int sqt = sqrt(fstNum);
        while((sqt+1)*(sqt+1)<=b){
            cnt++;
            sqt++;
        }
    }
    
    return cnt;
}
