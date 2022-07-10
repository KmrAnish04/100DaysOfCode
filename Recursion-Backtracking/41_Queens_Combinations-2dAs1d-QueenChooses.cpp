// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/queens-combinations-2das1d-queen-chooses-official/ojquestion
        nados: https://nados.io/question/queens-combinations-2d-as-1d-queen-chooses

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


#include<bits/stdc++.h>
using namespace std;

void queensComb(vector<vector<string>>&chess, int noOfQns, int curQn, int lcno){
    
    if(curQn==noOfQns){
        for(int i=0; i<noOfQns; i++){
            for(int j=0; j<noOfQns; j++){
                string rst=chess[i][j];
                cout<<rst+"\t";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    
    for(int i=lcno+1; i<noOfQns*noOfQns; i++){
        int row=i/noOfQns;
        int col=i%noOfQns;
        
        chess[row][col]="q";
        queensComb(chess, noOfQns, curQn+1, i);
        chess[row][col]="-"; 
    } 
}

int main(){
    int size;
    cin>>size;
    vector<vector<string>> chess(size, vector<string>(size, "-"));
    
    queensComb(chess, size, 0, -1);
    return 0;
}


