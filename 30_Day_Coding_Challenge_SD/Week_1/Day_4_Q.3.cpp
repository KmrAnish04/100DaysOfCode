int birthday(vector<int> s, int d, int m) {
    int i, j;
    i=0; j=m-1;
    int cnt=0;
    
    while(j<s.size()){
        int temp=0;
        for(int k=i; k<=j; k++){
            temp += s[k];
        }
        
        if(temp==d) cnt++;
        i++; j++;        
    }
    
    return cnt;
}


// Time Complexity --> O(NM) (not sure) (Here 'N' is size of array)
// Space Complexity --> O(1)
