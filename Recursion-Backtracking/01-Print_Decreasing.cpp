// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding.com: https://pepcoding.com/resources/online-java-foundation/introduction-to-recursion/print-decreasing-official/ojquestion
        nados.io: https://nados.io/question/print-decreasing?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



// Solution
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printDecreasing(int n){
    // write your code here
    if (n==0) return;
    cout<<n<<endl;
    printDecreasing(n-1);
    
}

int main(){
    int n;
    cin >> n;
    printDecreasing(n);
}

