// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
        Leetcode: https://leetcode.com/problems/n-queens/
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-combinations-2das1d-queen-chooses-official/ojquestion
        nados: https://nados.io/question/nqueens-combinations-2d-as-1d-queen-chooses?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/


// Pepcoding and Nados Solution
#include <bits/stdc++.h>
using namespace std;

bool isCellSafe(vector<vector<int>>&chess, int row, int col){
    //vectical up
    for(int i=row-1, j=col; i>=0; i--){
        if(chess[i][j]>0) return false;
    }
    
    //horizontal left
    for(int i=row, j=col-1; j>=0; j--){
        if(chess[i][j]>0) return false;
    }
    
    
    //daigonal up left
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
        if(chess[i][j]>0) return false;
    }
    
    //daigonal up right
    for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){ 
        if(chess[i][j]>0) return false;
    } 
    
    return true;
}


void nQnsComb(vector<vector<int>> &chess, int noOfQns, int curQn, int preCell){
    if(curQn==noOfQns){
        for(int i=0; i<noOfQns; i++){
            for(int j=0; j<noOfQns; j++){
                if(chess[i][j]==1){
                    cout<<"q\t";
                }
                else{
                    cout<<"-\t";
                }
            } 
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int i=preCell+1; i<noOfQns*noOfQns; i++){
        int row=i/noOfQns;
        int col=i%noOfQns; 
        if(isCellSafe(chess, row, col)){
            chess[row][col]=1;
            nQnsComb(chess, noOfQns, curQn+1, row*chess.size()+col);  
            chess[row][col]=0;
        }
    }
}


int main(){
    int size;
    cin>>size;
    vector<vector<int>> chess(size, vector<int>(size, 0));
    nQnsComb(chess, size, 0, -1);
    
    return 0;
}





// GFG Solution


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isCellSafe(vector<vector<int>>&chess, int row, int col){
        //vectical up
        for(int i=row-1, j=col; i>=0; i--){
            if(chess[i][j]>0) return false;
        }
        
        //horizontal left
        for(int i=row, j=col-1; j>=0; j--){
            if(chess[i][j]>0) return false;
        }
        
        
        //daigonal up left
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
            if(chess[i][j]>0) return false;
        }
        
        //daigonal up right
        for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){ 
            if(chess[i][j]>0) return false;
        } 
        
        return true;
    }
    
    void nQnsPerm(vector<vector<int>>&chess, vector<vector<int>>&ans,  vector<int>&asf, int QnNum, int row){
        if(row==chess.size()){
            ans.push_back(asf);
            return;
        }
        
        // Taken colums as options and queens on levels of recursion
        for(int col=0; col<chess.size(); col++){
            
            if(isCellSafe(chess, row, col)){
                chess[row][col]=QnNum;
                asf.push_back(col+1);
                
                nQnsPerm(chess, ans, asf, QnNum+1, row+1);
                
                chess[row][col]=0;
                asf.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> ans;
        
        vector<int> tmpAns;
        nQnsPerm(board, ans, tmpAns, 1, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}







// Leetcode Solution
class Solution {
public:
    bool isCellSafe(vector<vector<char>>&chess, int row, int col){
        //vectical up
        for(int i=row-1, j=col; i>=0; i--){
            if(chess[i][j]=='Q') return false;
        }
        
        //horizontal left
        for(int i=row, j=col-1; j>=0; j--){
            if(chess[i][j]=='Q') return false;
        }
        
        
        //daigonal up left
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j--){
            if(chess[i][j]=='Q') return false;
        }
        
        //daigonal up right
        for(int i=row-1, j=col+1; i>=0 && j<chess.size(); i--,j++){ 
            if(chess[i][j]=='Q') return false;
        } 
        
        return true;
    }
    
    void nQnsPerm(vector<vector<char>>&chess, vector<vector<string>>&ans, int QnNum, int row){
        if(row==chess.size()){
            vector<string> tmpAns;
            for(int i=0; i<chess.size(); i++){
                string str="";
                for(int j=0; j<chess.size(); j++){
                    str+=chess[i][j];
                }
                tmpAns.push_back(str);
            }
            
            ans.push_back(tmpAns);
            return;
        }
        
        // Taken colums as options and queens on levels of recursion
        for(int col=0; col<chess.size(); col++){
            
            if(isCellSafe(chess, row, col)){
                chess[row][col]='Q';
                
                nQnsPerm(chess, ans, QnNum+1, row+1);
                
                chess[row][col]='.';
            }
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        vector<vector<string>> ans;
        
        
        nQnsPerm(board, ans, 1, 0);
        
        return ans;
    }
};


// } Driver Code Ends






