string appendAndDelete(string s, string t, int k) {
    int slen=s.size();
    int tlen=t.size();
    int i=0;
    
    while(s[i]==t[i] && i<slen && i<tlen) i++;
    
    int del=slen-i;
    int app=tlen-i;
    int total=del+app;
    
    if(total>k) return "No";
    else if(total==k) return "Yes";
    else if(total<k){
        int minOp=total;
        int extraOp=k-total;
        int ovcm=(slen-del)+(tlen-app);
        
        if(extraOp<slen && extraOp%2==0) return "Yes";
        else if(extraOp>=ovcm) return "Yes";
    }
    
    return "No";

}