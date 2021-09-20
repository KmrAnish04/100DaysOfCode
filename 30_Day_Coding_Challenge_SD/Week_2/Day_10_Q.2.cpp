int saveThePrisoner(int n, int m, int s) {
    int pris=s;
    int candy=m;
    
    cout<<"starting"<<endl;
    for(int i=pris; i<=n; i++){
        cout<<"i="<<i<<endl;
        if(candy!=0){
            cout<<"line 24"<<endl;
            if(i==n){
                cout<<"line 26"<<endl;
                i=0;
                candy--;
            }
            else{
                candy--;
                cout<<"line 30"<<endl;
            }
        }
        else{
            cout<<"line 32,"<<"i="<<i<<endl; 
            return i-1;
            // break;
        }
    }
    
    return -1;

}