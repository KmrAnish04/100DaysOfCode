int sockMerchant(int n, vector<int> ar) {
    
    unordered_map<int, int> map;
    int socksCnt=0;
    
    for(int i=0; i<ar.size(); i++){
        map[ar[i]]++;
    }
    
    for(auto it: map){
        if(it.second%2 == 0) socksCnt += it.second/2;
        else socksCnt += (it.second-1)/2;
    }
    
    return socksCnt;
}
