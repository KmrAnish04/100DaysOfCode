// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: 
        Leetcode: https://leetcode.com/problems/scramble-string/
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/


// Leetcode Solution
class Solution {
public:
    unordered_map<string,bool> mp;
    
    bool solve(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.length() != s2.length()) return false;
        
        string tmp = s1 + "-" + s2;
        
        if(mp.find(tmp)!=mp.end()) return mp[tmp];
        
        int n = s1.length();
        bool flag = false;
        
        for(int k=1; k<=n-1; k++){
            if( (solve(s1.substr(0,k), s2.substr(n-k, k)) && solve(s1.substr(k, n-k), s2.substr(0, n-k)) ) || 
              (solve(s1.substr(0,k), s2.substr(0, k)) && solve(s1.substr(k, n-k), s2.substr(k, n-k)) )) {
                
                flag = true;
                break;
            }
        }
        
        mp[tmp]=flag;
        return flag;
        
    }

    bool isScramble(string s1, string s2) {
        
        return solve(s1, s2);
    }
};





// Code Ends Here