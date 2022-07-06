// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/online-java-foundation/recursion-backtracking/target-sum-subsets-official/ojquestion
        nados: https://nados.io/question/target-sum-subsets

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// set is the subset
// sos is sum of subset
// tar is target

/* 
   
   This solution is little optimized as compare to actual pepcoding solution video
   of this question, i.e if we get out target in earlier stage then we will not
   go util all the array elements get included in the sum (which is done in actual
   solution video), there is no point of including other element in the subset, we
   will just print that subset when we got target sum. This optimization reduces
   many unneccassary recursion calls.
   
*/
void printTargetSumSubsets(vector<int> arr, int idx, string set, int sos, int tar) {
    if(idx==arr.size()){
        if(sos==tar){
          cout<<set+"."<<endl;
        }
        return;
    }
//   if(sos==tar){
//       cout<<set+"."<<endl;
//       return;
//   }
//   if(idx==arr.size()) return;
  
  string element = to_string(arr[idx]);
  printTargetSumSubsets(arr, idx+1, set+element+", ", sos+arr[idx], tar);
  printTargetSumSubsets(arr, idx+1, set, sos, tar);

}


int main() {
    int size;
    int target; 
    cin>>size;
    vector<int> arr;
    while (size--)
    {
      int ele;
      cin>>ele;
      arr.push_back(ele);
    }
    cin>>target;
  
  
    printTargetSumSubsets(arr, 0, "", 0, target);
  
  
    return 0;

} 


