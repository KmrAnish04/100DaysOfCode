// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/permutations-words-1-official/ojquestion#
        nados: https://nados.io/question/permutations-words-1?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

void permWords(map<char,int>& map, int ts,int cs, string asf){
    if(cs>ts){
        cout<<asf<<endl;
        return;
    }
    
    for(auto it: map){
        if(it.second>0){
            char currChar=it.first;
            map[currChar]--;
            permWords(map, ts, cs+1, asf+currChar);
            map[currChar]++;
        }
    }
}

int main(){
    string str;
    cin>>str;
    
    map<char,int> mp;
    for(int i=0; i<str.length(); i++){
        mp[str[i]]++;
    }
    
    permWords(mp, str.length(), 1, "");
    
    
    return 0;
}


