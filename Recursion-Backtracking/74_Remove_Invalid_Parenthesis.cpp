// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/remove-invalid-parenthesis-official/ojquestion
        nados: https://nados.io/question/remove-invalid-parenthesis?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



#include<bits/stdc++.h>
using namespace std;

int minRemoval(string str){
    stack<char> stk;
    
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch=='('){
            stk.push(ch);
        }
        else{
            if(stk.empty() || stk.top()==')'){
                stk.push(ch);
            }
            else if(stk.top()=='('){
                stk.pop();
            }
        }
    } 
     
    return stk.size();
}

void solution(string str, int minRmAlw, unordered_map<string,bool>&frq){
    if(minRmAlw==0){
        int minRmNow = minRemoval(str);
        if(minRmNow==0){
            if(!frq[str]){
                cout<<str<<endl;
                frq[str]=true;
            }
        }
        return;
    }
    
    for(int i=0; i<str.length(); i++){
        string prefix = str.substr(0,i);
        string remStr = str.substr(i+1);
        solution(prefix+remStr, minRmAlw-1, frq);
    }
}

int main(){
    string str;
    cin>>str;
    
    unordered_map<string,bool> frq;
    
    int minRm = minRemoval(str);
    // cout<<minRm;
    solution(str, minRm, frq);
    
    
    return 0;
}


