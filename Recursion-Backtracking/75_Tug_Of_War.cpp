// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/tug-of-war-official/ojquestion
        nados: https://nados.io/question/tug-of-war?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

int minDiff=INT_MAX;
vector<int> ans1;
vector<int> ans2;
void printVecs(vector<int>v1, vector<int>v2){
    cout<<"["; 
    for(int i=0; i<v1.size(); i++){
        if(i==v1.size()-1){
            cout<<v1[i];
        }
        else{
            cout<<v1[i]<<", ";
        }
    }
    cout<<"] ";
    cout<<"[";
    for(int i=0; i<v2.size(); i++){ 
        if(i==v2.size()-1){
            cout<<v2[i]; 
        }
        else{
            cout<<v2[i]<<", ";
        }
    }
    cout<<"] "; 
} 
 
void solve(vector<int>nums, int n, int idx, vector<int>&set1, vector<int>&set2, int sos1, int sos2){
    
    if(idx==nums.size()){
        int delta = abs(sos1-sos2);
        if(delta < minDiff){
            minDiff=delta;
            ans1=set1;
            ans2=set2;
        }
        return;
    }
    
    if(set1.size()<(nums.size()+1)/2){
        set1.push_back(nums[idx]);
        solve(nums, n, idx+1, set1, set2, sos1+nums[idx], sos2);
        set1.pop_back();
    }
    if(set2.size()<(nums.size()+1)/2){
        set2.push_back(nums[idx]);
        solve(nums, n, idx+1, set1, set2, sos1, sos2+nums[idx]);
        set2.pop_back();
    } 
    
}


int main(){
    int n;
    cin>>n; 
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        nums[i]=ele;
    }
    
    
    vector<int> set1;
    vector<int> set2;
    solve(nums, n, 0, set1, set2, 0, 0);
    printVecs(ans1, ans2);
    
    return 0;
}




