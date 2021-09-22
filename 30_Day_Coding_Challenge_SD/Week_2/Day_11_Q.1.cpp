int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {
    int d=d1-d2;
    int m=m1-m2;
    int y=y1-y2;
    int diff[3] = {d,m,y};
    int fine=0;
    
    for(int i=2; i>=0; i--){
        if(i==2){
            if(diff[i]>0) return 10000;
            else if(diff[i]<0) return 0;
        }
        else if(i==1){
            if(diff[i]>0) return fine += diff[i]*500; 
            else if(diff[i]<0) return 0;
        }
        else if(i==0){
            if(diff[i]>0) return fine += diff[i]*15; 
            else if(diff[i]<0) return 0;
        } 
    }
    
    return 0;
    
    // if(d>0 || m>0 || y>0){
    //     if(d>0 && m==0 && y==0) fine += d*15;
    //     else if(m>0 && y==0) fine += m*500;
    //     else fine += 10000;
    // }
    // else return 0;
    
    // cout<<d<<" "<<m<<" "<<y<<endl;
    // return fine;
}