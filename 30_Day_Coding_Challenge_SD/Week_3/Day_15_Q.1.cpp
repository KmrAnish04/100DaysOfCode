string encryption(string s) {
    int sLen=s.length();
    string actualStr;
    string res="";
    
    for(int i=0; i<sLen; i++){
        int ascVal=int(s[i]);
        if(s[i]!=32) actualStr+=s[i];;
    }
    
    int actualLen=actualStr.length();
    float sqrtVal=sqrt(actualLen);
    int flr=floor(sqrtVal);
    int cel=ceil(sqrtVal);
    
    int row=flr;
    int col=cel;
    int i=1;
    
    while(row*col<actualLen){
        if(i%2!=0 && col<cel) col++;
        else if(i%2==0 && row<col) row++;
        i++;
    }
    
    for(int i=0; i<col; i++){
        int tmprow=i;
        while(tmprow<actualLen){
            res+=actualStr[tmprow];
            tmprow+=col;
        }
        if(i!=col-1) res+=" ";
    }
    
    return res;
}
