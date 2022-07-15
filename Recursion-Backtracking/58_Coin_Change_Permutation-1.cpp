// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/coin-change-permutations-1-official/ojquestion
        nados: https://nados.io/question/coin-change-permutations-1?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

void coinChPerm1(vector<int>&coins, map<int,int>&maps, int amt, int ssf, string asf){
    
    if(ssf==amt){
        cout<<asf+"."<<endl;
        return;
    }
    if(ssf>amt) return;
    
    
    for(int i=0; i<coins.size(); i++){
        if(maps[coins[i]]==1){
            int ch=coins[i];
            string chr=to_string(ch);
            maps[coins[i]]=0;
            coinChPerm1(coins, maps, amt, ssf+ch, asf+chr+"-");
            maps[coins[i]]=1;
        }
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
    
    map<int,int> maps;
    for(int i=0; i<coins.size(); i++){
        maps[coins[i]]=1;
    }
    coinChPerm1(coins, maps, amt, 0, "");
    
    return 0;
}



