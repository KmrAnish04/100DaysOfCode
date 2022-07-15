// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/words-klength-words-1-official/ojquestion
        nados: https://nados.io/question/words-k-length-words-1?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;



void wordskLen(string str, int k, int idx, int csf,vector<char> &ans){
    
    if(idx==str.length()){
        if(csf==k){
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
        return;
    }
     
    for(int i=0; i<ans.size(); i++){
        if(ans[i]=='\0'){
            ans[i]=str[idx];
            wordskLen(str, k, idx+1, csf+1,ans);
            ans[i]='\0';
        } 
         
    }
    wordskLen(str, k, idx+1, csf+0, ans);
    
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
            maps[str[i]]++; 
        }
    }
    
    wordskLen(uqStr, k, 0, 0,ans);
    
    
    return 0;
}


