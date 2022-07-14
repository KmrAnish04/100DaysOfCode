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



void wordsk4(string str, map<char,int> maps, int k, int idx, int cs, string asf){
    
    if(cs>k){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=idx; i<str.length(); i++){
        if(maps[str[i]]>0){
            char ch = str[i];
            maps[ch]--;
            wordsk4(str, maps, k, i, cs+1,asf+ch);   
            maps[ch]++;
        }
        
    }
}
 
 
int main(){
    string str;
    cin>>str; 
    int k;
    cin>>k;
     
    string uqStr; 
    map<char,int> maps; 
    for(int i=0; i<str.size(); i++){ 
        maps[str[i]]++; 
    }  
    for(auto i: maps){
        char ch=i.first;
        uqStr+=ch;
    }
    // cout<<uqStr<<endl;
    // for(auto i: maps){
    //     cout<<i.first<<": "<<i.second<<endl;
    // }
    wordsk4(uqStr, maps, k, 0, 1,"");
    
    
    return 0;
}


