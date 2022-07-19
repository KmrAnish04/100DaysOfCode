// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/friends-pairing-2-official/ojquestion
        nados: https://nados.io/question/friends-pairing-2?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

int counter=1;
void solve(int num, vector<bool>& isUsed, int idx, string asf){
    if(idx>num){
        string counterChr=to_string(counter);
        cout<<counterChr+"."+asf<<endl;
        counter++;
        return;
    }
    
    if(isUsed[idx]==false){
        isUsed[idx]=true;
        string chr=to_string(idx);
        solve(num, isUsed, idx+1, asf+"("+chr+") ");
        for(int i=idx+1; i<=num; i++){
            if(isUsed[i]==false){
                isUsed[i]=true;
                string chr2=to_string(i);
                solve(num, isUsed, idx+1, asf+"("+chr+","+chr2+") ");  
                isUsed[i]=false;
            }
        } 
        isUsed[idx]=false;
    }
    else{ 
        solve(num, isUsed, idx+1, asf); 
        
    }
    
}

int main(){
    int num;
    cin>>num;
    vector<bool> isUsed(num+1, false);
    
    solve(num, isUsed, 1, "");
    
    return 0;
}

