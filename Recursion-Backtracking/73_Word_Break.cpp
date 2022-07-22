// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/wordbreak1official/ojquestion
        nados: https://nados.io/question/word-break-i?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



#include<bits/stdc++.h>
using namespace std;


void solve(string sent, map<string,bool>&frq, string asf){
    if(0==sent.length()){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=0; i<sent.length(); i++){
        string word=sent.substr(0,i+1);
        string remStr=sent.substr(i+1);
        if(frq[word]){
            solve(remStr, frq, asf+word+" "); 
        }
    }
} 
 


int main(){
    int n; 
    map<string,bool> frq;
    cin>>n; 
    for(int i=0; i<n; i++){
        string word;
        cin>>word;
        frq[word]=true;
    }
     
    string sentence;
    cin>>sentence; 
    
    solve(sentence, frq, "");
    
    return 0;
}

