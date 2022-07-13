// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/words-kselection-1-official/ojquestion
        nados: https://nados.io/question/words-k-selection-1

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void wordsK(string str, int k, int prefixIdx, string asf, string calls){
    if(asf.length()==k){
        cout<<asf<<endl;
        // cout<<"Idx value during ans print..."<<prefixIdx<<endl;
        return;
    }
    if(prefixIdx>=str.length()){
        // cout<<"idx out of range.."<<endl;
        return;
    }
    
    // cout<<calls<<endl;
    
    char chr=str[prefixIdx];
    // cout<<"idx value before yes calls"<<prefixIdx<<endl;
    wordsK(str, k, prefixIdx+1, asf+chr, "Yes call");
    // cout<<"idx value before no calls"<<prefixIdx<<endl;
    wordsK(str, k, prefixIdx+1, asf, "No call");
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
    
    wordsK(uqStr, k, 0,"", "Initial call");
    return 0;
}


