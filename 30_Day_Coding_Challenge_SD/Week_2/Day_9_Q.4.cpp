int beautifulDays(int i, int j, int k) {
    int ans=0;
    
    for(int l=i; l<=j; l++){
        string stringOfI = to_string(l);
        int strSize=stringOfI.size();
        
        reverse(stringOfI.begin(), stringOfI.end());
        int iRev=stoi(stringOfI);
        int diff = abs(l-iRev);
        if(diff%k==0) ans++;
    }
    
    return ans;

}