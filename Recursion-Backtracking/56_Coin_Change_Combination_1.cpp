// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/coin-change-combinations-1-official/ojquestion
        nados: https://nados.io/question/coin-change-combinations-1?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

void coinChComb1(vector<int>&coins, int amt, int idx, int ssf, string asf){
    
    if(idx==coins.size()){
        if(ssf==amt){
            cout<<asf+"."<<endl;
        }
        return;
    }
    
    
    int ch=coins[idx];
    string chr=to_string(ch);
    coinChComb1(coins, amt, idx+1, ssf+ch, asf+chr+"-");
    coinChComb1(coins, amt, idx+1, ssf, asf);
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
    coinChComb1(coins, amt, 0, 0, "");
    
    return 0;
}

