// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void queensPerm(vector<vector<int>> chess, int curQn){
    int n = chess.size();
    if(curQn>n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(chess[i][j]>0){
                    string qnNum=to_string(chess[i][j]);
                    cout<<"q" + to_string(chess[i][j]) + "  ";
                }
                else{
                    cout<<"-    ";
                }
            }
            cout<<endl;
        }

        cout<<endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { 
            if(chess[i][j]==0){
                chess[i][j]=curQn;
                queensPerm(chess, curQn+1);
                chess[i][j]=0; 
            }
        }
    }
}


int main(){
    int size;
    cin>>size;
    vector<vector<int>> chess(size, vector<int>(size, 0));

    queensPerm(chess, 1);

    return 0;
}
