int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    int maxAmt=0;
    int i=keyboards.size()-1;
    int j=drives.size()-1;
    
    sort(keyboards.begin(), keyboards.end());
    sort(drives.begin(), drives.end());
    
    if(keyboards.size()>1) while(keyboards[i]>=b && i>=0) i--;
    if(drives.size()>1) while(drives[j]>=b && j>=0) j--;
    
    int tempMxAmt=0;
    for(int k=i; k>=0; k--){
        for(int l=j; l>=0; l--){
            tempMxAmt=0;
            tempMxAmt = max(keyboards[k]+drives[l], maxAmt);
            if(tempMxAmt<=b){
                maxAmt = tempMxAmt;
            }
        }
    }
    
    if(maxAmt == 0) return -1;
    
    return maxAmt;
}