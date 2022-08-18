// *************************** Dynamic Programming ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: Not Available , N/A
        Leetcode: N/A
        pepcoding: 
        nados: 

        Didn't find question link, so wrote the code from scratch, Solution given below.

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:

    
*/



#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    string LCS(string s1, string s2){
        int n=s1.length();
        int m=s2.length();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<n+1; i++) dp[i][0]=0;
        for(int i=0; i<m+1; i++) dp[0][i]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        int i=n, j=m;
        string ans="";
        
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i--; j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                }
                else i--;
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    
};


int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    
    Solution ob;
    cout<<ob.LCS(s1,s2)<<endl;
    
    return 0;
    
}



// Code Ends Here