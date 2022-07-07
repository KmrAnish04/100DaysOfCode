// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/queens-combinations-2das2d-box-chooses-official/ojquestion
        nadoi: https://nados.io/question/queens-combinations-2d-as-2d-box-chooses?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


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

void queensPerm(vector<vector<int>> chess, int curQn, int row, int col){
    int n = chess.size();
    if(curQn>n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(chess[i][j]>0){
                    string qnNum="	";
                    cout<<"q";
                }
                else{
                    cout<<"-";
                }
            }
            cout<<endl;
        }

        cout<<endl;
        return;
    }
    for (int i = row; i < n; i++)
    {
        for (int j = col; j < n; j++)
        { 
            if(chess[i][j]==0){
                chess[i][j]=curQn;
                queensPerm(chess, curQn+1, i, j);
                chess[i][j]=0; 
            }
        }
    }
}


int main(){
    int size;
    cin>>size;
    vector<vector<int>> chess(size, vector<int>(size, 0));

    queensPerm(chess, 1, 0, 0);

    return 0;
}


