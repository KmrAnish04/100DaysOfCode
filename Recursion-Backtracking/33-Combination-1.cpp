// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/combinations-i-official/ojquestion#! 
        nados: https://nados.io/question/combinations-1?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void permBoxItems(int noOfBoxes, int itms, int currItm, int idx,string asf){
    
    if(currItm>itms){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=idx; i<noOfBoxes; i++){
        if(asf[i]=='-'){
            asf[i] = 'i';
            permBoxItems(noOfBoxes, itms, currItm+1, i,asf);
            asf[i] = '-';
        }
    }
}


int main(){
    int noOfBoxes;
    int noOfItems; 
    string asf="";
    cin>>noOfBoxes;   
    cin>>noOfItems;
    
    for(int i=0; i<noOfBoxes; i++){
        asf+="-";
    }
    
    permBoxItems(noOfBoxes, noOfItems, 1, 0,asf);
    
    return 0;
}




