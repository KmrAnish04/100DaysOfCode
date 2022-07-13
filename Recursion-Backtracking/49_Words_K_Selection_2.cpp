// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/word-kselection-2-official/ojquestion
        nados: https://nados.io/question/words-k-selection-2

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void wordsK(string str, int k, int prefixIdx, string asf){
    if(asf.length()==k){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=prefixIdx; i<str.length(); i++)
        wordsK(str, k, i+1, asf+str[i]);
}

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    string uqStr;
    unordered_map<char,int> map;
    
    for(int i=0; i<str.length(); i++){
        if(map.find(str[i])==map.end()){
            map[str[i]]=1;
            uqStr+=str[i];
        }
    }
    
    wordsK(uqStr, k, 0, "");
    return 0;
}


