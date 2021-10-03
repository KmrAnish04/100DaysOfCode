int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int gCount=0;
    while(p>m){
        int curPrice=p;
        if(s>=curPrice){
            gCount++;
            s -= curPrice;
            p-=d;
        }
        else{
            return gCount;
        } 
    }
    gCount += s/m;
    
    return gCount;

}