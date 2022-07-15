// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/wors-klength-words-3-official/ojquestion#
        nados: https://nados.io/question/words-k-length-words-3?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void wordsKLen3(string str, map<char,int>&maps, int k, int idx, int cc,vector<char>&ans){
    
    if(idx==str.length()){
        if(cc==k){
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
        if(ans[i]=='\0'){
            ans[i]=ch; 
            maps[ch]=i;
            // cout<<"\nYes call: idx val: "<<idx<<endl;
            // cout<<"current string: ";
            // for(int i=0; i<ans.size(); i++){
            //     cout<<ans[i];
            // }
            wordsKLen3(str, maps, k, idx+1, cc+1, ans);
            ans[i]='\0';
            maps[ch]=lo;
             
        }
    }
    if(lo==-1){
        // cout<<"\nNo call: idx val: "<<idx<<endl;
        // cout<<"current string: ";
        // for(int i=0; i<ans.size(); i++){
        //     cout<<ans[i];
        // }
        // cout<<endl;
        wordsKLen3(str, maps, k, idx+1, cc, ans);
    }
}
  
int main(){ 
    string str; 
    int k;
    cin>>str>>k; 
     
    vector<char> ans(k,'\0');
    map<char,int> maps;
    for(int i=0; i<str.length(); i++){
        maps[str[i]]=-1;
    }
    
    wordsKLen3(str, maps, k, 0, 0, ans);
    // cout<<str<<endl;
    // cout<<k<<endl;
    
    return 0;
}


