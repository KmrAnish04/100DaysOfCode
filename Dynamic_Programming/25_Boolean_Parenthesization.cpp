// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
        Leetcode: 
        pepcoding: 
        nados: 

    Complexity Analysis:
        Expected Time Complexity: O(N3)
        Expected Auxiliary Space: O(N2)

    Algorithm:

    
*/



// GFG Solution
class Solution{
public:
    unordered_map<string, int> mp;
    int solve(string &s, int i, int j, bool isTrue){
        
        if(i>j) return 0;
        if(i==j){
            if(isTrue){
                if(s[i]=='T') return true;
                else return false;
            }
            else{
                if(s[i]=='F') return true;
                else return false;
            }
        }
        
        string tmpStr = to_string(i) + "-" + to_string(j) + "-" + to_string(isTrue);
        
        if(mp.find(tmpStr) != mp.end()) return mp[tmpStr];
        
        int ans = 0;
        
        for(int k=i+1; k<=j-1; k=k+2){
            
            int lt = solve(s, i, k-1, true);
            int lf = solve(s, i, k-1, false);
            int rt = solve(s, k+1, j, true);
            int rf = solve(s, k+1, j, false);
            
            if(s[k] == '&'){
                if(isTrue == true){
                    ans = ans + (lt * rt);
                }
                else{
                    ans = ans + (lf*rt) + (lf*rf) + (lt*rf);
                }
            }
            
            else if(s[k] =='|'){
                if(isTrue == true){
                    ans = ans + (lt * rt) + (lt * rf) + (lf * rt);;
                }
                else{
                    ans = ans + (lf * rf);
                }
            }
            
            else if(s[k] == '^'){
                if(isTrue == true){
                    ans = ans + (lf * rt) + (lt * rf);
                }
                else{
                    ans = ans + (lt * rt) + (lf * rf);
                }
            }
        }
        
        return mp[tmpStr]=(ans%1003);
    }
    
    
    int countWays(int N, string S){
        // code here
        return solve(S, 0, N-1, true);
    }
};





// Code Ends Here