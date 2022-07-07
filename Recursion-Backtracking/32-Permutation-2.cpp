// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/permutations-ii-official/ojquestion
        nadio: https://nados.io/question/permutations-2?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

void perm(vector<int>&cont, int items, int currItm){
    if(currItm>items){
        for(int i=0; i<cont.size(); i++){
            cout<<cont[i];
        }
        cout<<endl;
        return;
    }
    
    
    for(int i=0; i<cont.size(); i++){
        if(cont[i]==0){
            cont[i]=currItm;
            perm(cont, items, currItm+1); 
            cont[i]=0;  
        }
    }
    
}
 
int main(){ 
    int noOfBoxes;
    int noOfItems; 
    cin>>noOfBoxes;
    cin>>noOfItems;
    
    vector<int> cont(noOfBoxes,0);
    perm(cont, noOfItems, 1);
    
    return 0;
}



