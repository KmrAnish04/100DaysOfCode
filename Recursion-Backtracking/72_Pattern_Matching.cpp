// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/pattern-matching-official/ojquestion
        nados: https://nados.io/question/pattern-matching?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string str, string patt, string pattern, map<char,string>mp){
    
    if(patt.length()==0){
        if(str.length()==0){
            map<char,int> printed;
            for(int i=0; i<pattern.length(); i++){
                char chr = pattern[i];
                if(printed[chr]==0){
                    string rst = mp[chr];
                    cout<<chr<<" -> "<<rst<<", ";
                    printed[chr]++;
                }  
            }
            cout<<"."<<endl;
        }
        return;
    }
    
    
    char chr = patt[0]; 
    string remPatt=patt.substr(1);
    
    if(mp.find(chr)!=mp.end()){ 
        string mpdStr = mp[chr];
        
        if(str.length()>=mpdStr.length()){
            string curStrcr = str.substr(0, mpdStr.length());
            string remStr = str.substr(mpdStr.length());
            
            if(curStrcr == mpdStr){
                solve(remStr, remPatt, pattern, mp);  
            }
        }
        
    }
    else{
        for(int i=0; i<str.length(); i++){
            string strcr = str.substr(0,i+1);
            string remStr = str.substr(i+1);
            mp[chr]=strcr;
            solve(remStr, remPatt, pattern, mp);
            mp.erase(chr);
             
        } 
    }
} 
 

int main(){
    string str;
    string pattern;
    
    cin>>str;
    cin>>pattern;
    
    map<char,string> mapping;
    
    solve(str, pattern, pattern, mapping);
    
    
    return 0;
}

