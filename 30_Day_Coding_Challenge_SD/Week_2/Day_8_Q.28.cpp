int hurdleRace(int k, vector<int> height) {
    int maxHg=k;
    int ans;
    
    for(int i=0; i<height.size(); i++){
        maxHg=max(maxHg, height[i]);
    }
    
    ans=abs(k-maxHg);
    
    return ans;

}