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






// Improving space complexity.....continue
string encryption(string s) {
    
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    string res="";
    
    int sLen=s.length();
    float sqrtVal=sqrt(sLen);
    int flr=floor(sqrtVal);
    int cel=ceil(sqrtVal);
    
    int row=flr;
    int col=cel;
    int i=1;
    
    while(row*col<sLen){
        if(i%2!=0) col++;
        else row++;
        i++;
    }
    
    // cout<<sLen<<endl;
    // cout<<actualLen<<endl;
    // cout<<sqrtVal<<endl;
    // cout<<flr<<endl;
    // cout<<cel<<endl;
    // cout<<row<<endl;
    // cout<<col<<endl;
    // cout<<"res= "<<res<<endl;
     
    // int col=0;
    for(int i=0; i<col; i++){
        int tmprow=i;
        res+=s[i];
        while(tmprow<sLen){
            res+=s[tmprow+col];
            tmprow+=col;
        }
        if(i==col-1) break;
        res+="";
    }
    cout<<res;
    return res;

}
