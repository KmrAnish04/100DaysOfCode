// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/permutation-i-official/ojquestion
        nadio.io: https://nados.io/question/permutation-1

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void permBoxItems(int noOfBoxes, int itms, int currItm, string asf){
    
    if(currItm>itms){
        cout<<asf<<endl;
        return;
    }
    
    for(int i=0; i<noOfBoxes; i++){
        if(asf[i]=='0'){
            // asf[i] = to_string(currItm);
            asf[i] = '0'+currItm;
            permBoxItems(noOfBoxes, itms, currItm+1, asf);
            asf[i] = '0';
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
        asf+="0";
    }
    
    permBoxItems(noOfBoxes, noOfItems, 1, asf);
    
    return 0;
}

