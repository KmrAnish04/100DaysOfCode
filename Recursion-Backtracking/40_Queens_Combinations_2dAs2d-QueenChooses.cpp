// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/queens-combinations-2das2d-official/ojquestion
        nados: https://nados.io/question/queens-combinations-2d-as-2d-queen-chooses?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void queensComb(vector<vector<string>>& chess, int noOfQns, int curQn, int row, int col){
    
    if(curQn==noOfQns){
        for(int i=0; i<noOfQns; i++){
            for(int j=0; j<noOfQns; j++){
                string qn=chess[i][j];
                cout<<qn+"\t";
            }
            cout<<"\n";
        }
        cout<<endl;
        return;
    }
     
    for(int j=col+1; j<noOfQns; j++){
        if(chess[row][j]=="-"){   
            
            chess[row][j]='q';
            queensComb(chess, noOfQns, curQn+1, row, j);
            chess[row][j]="-";   
        }  
    }
    for(int i=row+1; i<noOfQns; i++){
        for(int j=0; j<noOfQns; j++){
            if(chess[i][j]=="-"){   
                
                chess[i][j]='q';
                queensComb(chess, noOfQns, curQn+1, i, j);
                chess[i][j]="-";   
            }  
        } 
    }
}

int main(){
    int size;
    cin>>size;
    vector<vector<string>> chess(size, vector<string>(size, "-"));
    queensComb(chess, size, 0, 0, -1);
    
    return 0;
}


