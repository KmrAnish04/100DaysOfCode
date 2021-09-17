void plusMinus(vector<int> arr) {
    double pos=0;
    double neg=0;
    double zero=0;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>0) pos++;
        else if(arr[i]<0) neg++;
        else zero++;
    }
    pos=pos/arr.size();
    neg=neg/arr.size();
    zero=zero/arr.size();
    
    cout<<pos<<endl;
    cout<<neg<<endl;
    cout<<zero<<endl;

}