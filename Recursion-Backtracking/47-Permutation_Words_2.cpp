// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/permutations-words-2-official/ojquestion
        nados: https://nados.io/question/permutations-words-2?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



#include<bits/stdc++.h>
using namespace std;

void permWords(string str, map<char,int>&mp, vector<char> &ans, int cc){
    if(cc==str.length()){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }
    
    char currChr=str[cc];
    int lo = mp[currChr];
    
    for(int i=lo+1; i<str.length(); i++){
        if(ans[i]=='-'){
            ans[i]=currChr;
            mp[currChr]=i;
            permWords(str, mp, ans, cc+1);
            mp[currChr]=-1;
            ans[i]='-';
            
        }
    }
}


int main(){  
    string str;  
    cin>>str;
    
    vector<char> ans(str.length(), '-'); 
    
    map<char,int> mp;
    for(int i=0; i<str.length(); i++){
        mp[str[i]]=-1;
    }
    
    permWords(str, mp, ans, 0);
    
    
    return 0;
}



