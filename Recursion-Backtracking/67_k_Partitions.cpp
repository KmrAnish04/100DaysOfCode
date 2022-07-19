// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/k-partitions-official/ojquestion
        nados: https://nados.io/question/k-partitions?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

int counter=0;
void solve(int n, int k, int idx, int ssf, vector<vector<int>>&ans){
    
    if(idx>n){
        if(ssf==k){
            counter++;
            cout<<to_string(counter)+". ";
            for(int i=0; i<k; i++){
                cout<<"[";
                for(int j=0; j<ans[i].size(); j++){
                    vector<int> set=ans[i];
                    if(j==ans[i].size()-1){
                        cout<<set[j];
                    }
                    else{
                        cout<<set[j]<<", ";
                    }
                }
                cout<<"] ";
            }
            cout<<endl; 
        }
        return; 
    }
     

    for(int i=0; i<ans.size() ; i++){
        if(ans[i].size()>0){
            ans[i].push_back(idx);
            solve(n, k, idx+1, ssf, ans);
            ans[i].pop_back();
        }
        else{
            ans[i].push_back(idx);
            solve(n, k, idx+1, ssf+1, ans);
            ans[i].pop_back();
            break;
        }
    }
} 

int main(){
    int n;
    int k;
    cin>>n>>k;
    
    vector<vector<int>> ans(k);
    
    solve(n, k, 1, 0, ans);
    
    return 0;
}