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

void wordsK(string str, vector<char> &ans, map<char,int> &maps, int idx, int ssf, int k){
    
    if(idx==str.length()){
        if(ssf==k){
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
        return;
    }
    
    
    char ch=str[idx];
    int lo=maps[ch];
    for(int i=lo+1; i<ans.size(); i++){
        if(ans[i]=='-'){
            ans[i]=ch;
            maps[ch]=i;
            wordsK(str, ans, maps, idx+1, ssf+1, k);
            ans[i]='-';
            maps[ch]=lo;
        }
    }
    
    if(lo==-1){
        wordsK(str, ans, maps, idx+1, ssf, k);
    }
}
  
int main(){
    string str;   
    cin>>str;
    int k; 
    cin>>k;
    
    vector<char> ans(k, '-');
    map<char,int> maps;
    for(int i=0; i<str.length(); i++){
        maps[str[i]]=-1;
    }
    
    wordsK(str, ans, maps, 0, 0, k);
    return 0;
}


