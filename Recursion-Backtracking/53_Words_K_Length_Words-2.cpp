// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/words-klength-words-2-official/ojquestion
        nados: https://nados.io/question/words-k-length-words-2?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;


void wordskLen2(string str, int k, map<char,int>&maps, int idx, vector<char>&ans){
    
    if(idx==k){
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
        }
        cout<<endl;
        return;
    }
    
    
    for(int i=0; i<str.length(); i++){
        if(maps[str[i]]==1){
            ans[idx]=str[i];
            maps[str[i]]=0;
            wordskLen2(str, k, maps, idx+1, ans);
            ans[idx]='\0';
            maps[str[i]]=1;
        }
    }
}


int main(){
    string str;
    cin>>str;
    int k;
    cin>>k; 
    
    string uqStr=""; 
    map<char,int> maps;
    vector<char> ans(k, '\0');
    for(int i=0; i<str.size(); i++){ 
        if(maps[str[i]]==0){
            uqStr+=str[i]; 
            maps[str[i]]=1; 
        }
    }
    
    wordskLen2(uqStr, k, maps, 0, ans);
    return 0;
}


