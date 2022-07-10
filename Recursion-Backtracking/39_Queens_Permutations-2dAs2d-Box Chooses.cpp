// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/queens-permutations-2das2d-box-chooses-official/ojquestion
        nados: https://nados.io/question/queens-permutations-2d-as-2d-box-chooses?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void queensPerm(vector<int>&chess, int currQn, int row, int col, string asf){
    int n = chess.size();
    if(row==n){
        if(currQn==n){
            cout<<asf<<endl;
        }
        return;
    }
    
    
    for (int j = 0; j < n; j++)
    { 
        if(chess[j]==0){ 
            chess[j]=1;
            string qnNum=to_string(j+1);
            
            if(col==n-1){
                queensPerm(chess, currQn+1, row+1, 0, asf + "q" + qnNum + "\n");
            }
            else{
                queensPerm(chess, currQn+1, row, col+1, asf + "q" + qnNum + "	");
            }
            
            chess[j]=0; 
        }
    }
    
    if(col==n-1){
        queensPerm(chess, currQn, row+1, 0, asf + "    -"+"\n"); 
    }
    else{
        queensPerm(chess, currQn, row, col+1, asf + "-  ");
    }
}


int main(){
    int size;
    cin>>size;
    vector<int> chess(size, 0);

    queensPerm(chess, 0, 0, 0, "");

    return 0;
}


