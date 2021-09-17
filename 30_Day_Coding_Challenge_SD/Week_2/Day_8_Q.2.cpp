int pickingNumbers(vector<int> a) {
    int maxAns=INT_MIN;
    map<int, int> mapArr;
    
    for(int i=0; i<a.size(); i++){
        mapArr[a[i]]++;
    }
    
    int mapSize = mapArr.size();
    int loopCnt = 0;
    int temp;
    map<int, int>::iterator i;
    map<int, int>::iterator j;
    
    for(auto i=mapArr.begin(); i != mapArr.end(); i++){
        j = next(i);
        int currentElement = i->first;
        int nextElement = j->first;
        temp = 0;
        temp = i->second;
        
        if(mapSize>=2){
            if(loopCnt<=mapSize-2){
                if(nextElement-currentElement<=1){
                    temp += j->second;
                    loopCnt++;
                }
                else{ 
                    loopCnt++;
                }
            }
            else break;
        }

        maxAns = max(maxAns, temp);
    }
    
    return maxAns;

}