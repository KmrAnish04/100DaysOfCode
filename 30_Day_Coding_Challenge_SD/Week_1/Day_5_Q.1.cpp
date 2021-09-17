int migratoryBirds(vector<int> arr) {
    int frqArr[5]={0,0,0,0,0};
    int ans=0;
    
    for(int i=0; i<arr.size(); i++){
        frqArr[arr[i]-1]++;
    }
    
    int maxfrq = frqArr[0];
    int minInd = INT_MAX;
    
    for(int i=i; i<5; i++){
        if(frqArr[i]>maxfrq){
            maxfrq=frqArr[i];
            minInd = i;
        }
        else if(frqArr[i]==maxfrq) minInd = min(i, minInd);
    }
    
    ans = minInd+1;
    
    return ans;
}

// Time Complexity --> O(N)
// Space Complexity --> O(1)
