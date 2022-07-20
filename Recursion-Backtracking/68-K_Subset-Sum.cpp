// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/k-subsets-with-equal-sum-official/ojquestion
        nados: https://nados.io/question/k-subsets-with-equal-sum?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:
 
    
*/

#include<bits/stdc++.h>
using namespace std;

bool isSumEqual(vector<int> ss){
    vector<int> cp(ss.size(), ss[0]);
    if(cp!=ss) return false; 
    return true;
} 
 
void print(vector<vector<int>>ans, int k){
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

void solve(vector<int>&nums, int n, int k, int idx, int ssf, vector<int>&ss, vector<vector<int>>&ans){
     
    if(idx==nums.size()){
        if(ssf==k){
            if(isSumEqual(ss)){
                print(ans, k);  
            }
        }
        return; 
    }
     

    for(int i=0; i<ans.size(); i++){
        if(ans[i].size()>0){ 
            ans[i].push_back(nums[idx]);
            ss[i]+=nums[idx];
            solve(nums, n, k, idx+1, ssf, ss, ans);
            ss[i]-=nums[idx]; 
            ans[i].pop_back(); 
        }
        else{
            ans[i].push_back(nums[idx]);
            ss[i]+=nums[idx];
            solve(nums, n, k, idx+1, ssf+1, ss, ans);
            ans[i].pop_back();
            ss[i]-=nums[idx]; 
            break;
        } 
    } 
} 
 
int main(){ 
    int n;
    int k;  
    cin>>n;
    
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int ele;    
        cin>>ele;
        nums[i]=ele;  
    }  
      
    cin>>k;  
    
    vector<int> subsetSum(k,0); 
    vector<vector<int>> ans(k); 
    
    solve(nums, n, k, 0, 0, subsetSum,ans);
    
    return 0;
}

