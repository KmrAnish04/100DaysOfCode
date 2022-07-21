// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/all-palindromic-permutations-official/ojquestion
        nados: https://nados.io/question/all-palindromic-permutations?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



#include<bits/stdc++.h>
using namespace std;

void solve(map<char,int>&mp, int len, char oddChr, int cs, string asf){
    if(cs>len){
        string sufix=asf;
        reverse(sufix.begin(), sufix.end());
        if(oddChr!='-'){
            cout<<asf+oddChr+sufix<<endl;
            return;
        }
        cout<<asf+sufix<<endl;
        return;
    }
    
    for(auto it: mp){
        char chr=it.first;
        int frq=it.second;
        if(frq>0){
            mp[chr]--;
            solve(mp, len, oddChr, cs+1, asf+chr);
            mp[chr]++;
        }
    } 
}


int main(){
    string str; 
    cin>>str;
    
    map<char,int> frq;
    for(int i=0; i<str.length(); i++){
        frq[str[i]]++;
    }
    
    char oddChr='-';
    int odds=0;
    int len=0;
     
    for(auto it: frq){
        char chr=it.first; 
        int chrFrq=it.second;
          
        if(chrFrq%2!=0){ 
            oddChr=it.first;  
            odds++; 
        }
        
        frq[chr]=chrFrq/2;
        len+=chrFrq/2;
    }
    
    if(odds>1){
        cout<<-1<<endl;
        return 0;
    }
    
    solve(frq, len, oddChr, 1, "");
    
    return 0;
}


