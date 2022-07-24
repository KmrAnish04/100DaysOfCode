// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/largest-number-at-most-k-swaps-official/ojquestion
        nados: https://nados.io/question/largest-number-possible-after-at-most-k-swaps?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/



#include<bits/stdc++.h>
using namespace std;

string maxM;

void printMap(unordered_map<int,int>map){
    cout<<endl;
    for(auto it: map){
        cout<<"Key: "<<it.first<<", "<<"Value: "<<it.second<<endl;
    }
    
}


string swapss(string str, int i, int j){
    char ith=str[i];
    char jth=str[j];
    
    string left=str.substr(0, i);
    string mid=str.substr(i+1, j-i-1);
    
    string right=str.substr(j+1); 
    
    return left +jth+ mid +ith+ right;
}


void solution(string str, int k){
    
    int strInt=stoi(str); 
    int  maxInt=stoi(maxM); 
    if(str>maxM){  
        maxM=str;
    }
     
    if(k==0){
        return;
    }
     
    
    for(int i=0; i<str.length()-1; i++){
        for(int j=i+1; j<str.length(); j++){
            if(str[i]<str[j]){
                str=swapss(str, i, j);
                solution(str, k-1);
                str=swapss(str, i, j);
            }
        }
    }
      
} 
 

  
int main() {   
    string str;  
    cin>>str; 
    int k;
    cin>>k;
 
    maxM=str;  
    solution(str, k);
    
    cout<<maxM<<endl;

    return 0;
}


