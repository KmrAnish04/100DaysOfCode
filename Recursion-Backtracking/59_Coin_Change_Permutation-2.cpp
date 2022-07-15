// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/coin-change-permutations-2-official/ojquestion
        nados: https://nados.io/question/coin-change-permutations-2?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

void coinChComb1(vector<int>&coins, int amt, int ssf, string asf){
    
    if(ssf==amt){
        cout<<asf+"."<<endl;
        return;
    }
    if(ssf>amt) return;
    
    
    for(int i=0; i<coins.size(); i++){
        int ch=coins[i];
        string chr=to_string(ch);
        coinChComb1(coins, amt, ssf+ch, asf+chr+"-");
    }
}


int main(){ 
    int n; 
    int amt;
    cin>>n;  
    vector<int> coins(n);
    for(int i=0; i<n; i++){ 
        int ele; 
        cin>>ele;
        coins[i]=ele;
    }
    cin>>amt;
    
    coinChComb1(coins, amt, 0, "");
    
    return 0;
}


