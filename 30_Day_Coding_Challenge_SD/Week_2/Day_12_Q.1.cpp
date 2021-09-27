/*
    Solution by Anish.
*/

int jumpingOnClouds2(vector<int> c, int k) {
    int size=c.size();
    int Eng=100;
    int curPos=0;
    bool reached=false;
    
    while(!reached){
        int nxtJmpIdx=(curPos+k)%size;
        curPos=nxtJmpIdx;
        Eng--;
        if(c[curPos]==1) Eng -= 2;
        if(curPos==0) reached=true;        
    }
    
    return Eng;
}