// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/all-palindromic-partitions-official/ojquestion
        nados: https://nados.io/question/all-palindromic-partitions?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



#include<bits/stdc++.h>
using namespace std;

bool isStrPalindrome(string str){
    
    for(int i=0; i<str.length()/2; i++){
        if(str[i]!=str[str.length()-1-i]) return false;
    }
    
    return true;
}

void solve(string str, string asf){
    
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=0; i<str.length(); i++){
        string prefix = str.substr(0,i+1);
        string remStr = str.substr(i+1); 
        if(isStrPalindrome(prefix)){
            solve(remStr, asf + "(" + prefix + ") ");
        }
    }
}

int main(){
    string str;
    cin>>str;
    
    solve(str, "");
    
    return 0;
}



