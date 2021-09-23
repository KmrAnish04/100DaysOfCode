/*
    Solution by Anish.
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

long repeatedString(string s, long n) {
    int len=s.size();
    long ans=0;
    vector<int> aPos; // aPos represents the positions of a's in array.
    
    for(int i=0; i<len; i++){
        if(s[i]=='a') aPos.push_back(i+1);
    }
    
    long strOcc=n/len; // number of strings repeated.
    long charLeft=n%len; // letters left after proper no. of strings repeated.
    ans += strOcc * aPos.size(); // no. of a's from repeated strings.
    
    for(int i=0; i<aPos.size(); i++){
        if(aPos[i]<=charLeft) ans++; // no. of a's from left letters. 
        else break;
    }
    
    return ans;

}

