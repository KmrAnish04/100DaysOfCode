// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/abbreviation-suing-backtracking-official/ojquestion
        nados: https://nados.io/question/abbreviation-using-backtracking?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/




#include<bits/stdc++.h>
using namespace std;


void solve(string str, int cc, int idx, string asf){
    if(idx==str.length()){
        if(cc==0){
            cout<<asf<<endl;
        }
        else{
            string ccChr=to_string(cc);
            cout<<asf+ccChr<<endl;
        }
        
        return;
    }
    
    char chr=str[idx];
    string yesStr="";
    if(cc!=0){
        string ccChr=to_string(cc);
        yesStr+=asf+ccChr+chr;
    }
    else{
        yesStr+=asf+chr;
    }
    solve(str, 0, idx+1, yesStr);
    solve(str, cc+1, idx+1, asf);
}


int main(){
    string str;
    cin>>str;
    
    solve(str, 0, 0, "");
    
    return 0;
}


