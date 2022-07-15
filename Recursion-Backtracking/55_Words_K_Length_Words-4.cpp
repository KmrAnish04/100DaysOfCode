// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/words-klength-words-4-official/ojquestion
        nados: https://nados.io/question/words-k-length-words-4?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void wordsKLen4(string str, int k, map<char,int>&maps, int ssf, string asf){
    
    if(ssf>k){
        cout<<asf<<endl;
        return;
    }
    // if(asf.length()>k) return; 
    
    for(int i=0; i<str.length(); i++){
        char ch=str[i];
        if(maps[ch]>0){
            maps[ch]--;
            wordsKLen4(str, k, maps, ssf+1,asf+ch);
            maps[ch]++;
        }
    }
}

int main(){
    string str;
    int k;
    cin>>str;
    cin>>k;
     
    string uqStr=""; 
    map<char,int> maps;
    for(int i=0; i<str.length(); i++){ 
        if(maps[str[i]]<=0){
            uqStr+=str[i];
        }
        maps[str[i]]++;
    } 
    // cout<<"uqString: "<<uqStr<<endl;
    // for(auto it: maps){
    //     cout<<it.first<<": "<<it.second<<endl;
    // }
    
    wordsKLen4(uqStr, k, maps, 1,"");
    return 0;
}

