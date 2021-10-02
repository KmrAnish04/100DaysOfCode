int minimumDistances(vector<int> a) {
    int ans=MIN_MAX;
    
    for(int i=0; i<a.size()-1; i++){
        for(int j=i+1; j<a.size(); j++){
            if(a[i]==a[j]){
                int tmpMin=j-i;
                ans=min(tmpMin, ans);
            }
        }
    }
    
    return ans;

}