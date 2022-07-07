// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/combinations-2-official/ojquestion#!
        nados: https://nados.io/question/combinations-2

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

void permBoxItems(vector<char> &cont, int noOfBoxes, int itms, int currItm, int idx){
    
    if(currItm>itms){
        for(int i=0; i<noOfBoxes; i++){
            cout<<cont[i];
        }
        cout<<endl;
        return;
    }
    
    for(int i=idx+1; i<noOfBoxes; i++){
        cont[i] = 'i';
        permBoxItems(cont ,noOfBoxes, itms, currItm+1, i);
        cont[i] = '-';
    }
}

 
int main(){
    int noOfBoxes;
    int noOfItems; 
    string asf="";  
    cin>>noOfBoxes;    
    cin>>noOfItems;
    
    vector<char> cont(noOfBoxes,'-');
    
    permBoxItems(cont, noOfBoxes, noOfItems, 1, -1);
    
    return 0;
}




