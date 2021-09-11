void bonAppetit(vector<int> bill, int k, int b) {
    int commonEat=0;
    int actualPrice;
    
    for(int i=0; i<bill.size(); i++){
        if(i != k){
            commonEat += bill[i];
        }
    }
    actualPrice = commonEat/2;
    if(b-actualPrice != 0) cout<<b-actualPrice;
    else cout<<"Bon Appetit";
}