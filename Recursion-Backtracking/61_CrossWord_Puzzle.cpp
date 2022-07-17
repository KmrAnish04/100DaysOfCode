// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding:
        nados:

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

bool isCellValidHor(vector<vector<char>>&board, string word, int row, int col){
    if(col-1>=0 && board[row][col-1]!='+'){
        return false;
    }
    else if(col+word.length()<board[0].size() && board[row][col+word.length()]!='+'){
        return false;
    }
    
    for(int j=0; j<word.length(); j++){
        if(col+j>=board[0].size()) return false;
        if(board[row][col+j]=='-' || board[row][col+j]==word[j]){
            continue;
        }
        else{
            return false;
        }
    }
     
    return true;
}


bool isCellValidVer(vector<vector<char>>&board, string word, int row, int col){
    if(row-1>=0 && board[row-1][col]!='+'){
        return false;
    }
    else if(row+word.length()<board.size() && board[row+word.length()][col]!='+'){
        return false;
    }
    
    for(int j=0; j<word.length(); j++){
        if(row+j>=board.size()) return false;
        if(board[row+j][col]=='-' || board[row+j][col]==word[j]){
            continue;
        }
        else{
            return false;
        }
    }
    
    return true;
}

vector<bool> placeHor(vector<vector<char>>&board, string word, int row, int col){
    vector<bool> wePlace(word.length());
    for(int i=0; i<word.length(); i++){
        if(board[row][col+i]=='-'){
            board[row][col+i]=word[i];
            wePlace[i]=true;
        }
    }
    
    return wePlace;
}

vector<bool> placeVer(vector<vector<char>>&board, string word, int row, int col){
    vector<bool> wePlace(word.length());
    for(int i=0; i<word.length(); i++){
        if(board[row+i][col]=='-'){
            board[row+i][col]=word[i];
            wePlace[i]=true;
        }
    }
    
    return wePlace;
}

void unPlaceHor(vector<vector<char>>&board, vector<bool>&wePlace, int row, int col){
    for(int i=0; i<wePlace.size(); i++){
        if(wePlace[i]==true){
            board[row][col+i]='-';
        }
    }
}

void unPlaceVer(vector<vector<char>>&board, vector<bool>&wePlace, int row, int col){
    for(int i=0; i<wePlace.size(); i++){
        if(wePlace[i]==true){
            board[row+i][col]='-';
        }
    }
}




void crossWrd(vector<vector<char>>&board, vector<string>words, int vidx){
    
    if(vidx==words.size()){
        /*
        // Added this manually....
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j]=='-') return;
            }
        }
        */
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    } 
    
    string word=words[vidx];
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(isCellValidHor(board, word, i, j) || board[i][j]==word[0]){
                vector<bool> wePlace = placeHor(board, word, i, j);
                crossWrd(board, words, vidx+1);
                unPlaceHor(board, wePlace, i, j);
            }
            if(isCellValidVer(board, word, i,j) || board[i][j]==word[0]){
                vector<bool> wePlace = placeVer(board, word, i, j);
                crossWrd(board, words, vidx+1);
                unPlaceVer(board, wePlace, i, j);
            }
        }
    }
}


int main(){
    int wordsCnt=0;
    vector<vector<char>> crsWrd(10, vector<char>(10));
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){ 
            char chr;
            cin>>chr;
            crsWrd[i][j]=chr; 
        }
    }
     
    cin>>wordsCnt; 
    vector<string> words(wordsCnt);
    for(int i=0; i<wordsCnt; i++){
        string str;
        cin>>str;
        words[i]=str;
    }
    
    crossWrd(crsWrd, words, 0);
    
    // for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++){ 
    //         cout<<crsWrd[i][j]<<" "; 
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<"wordsCnt: "<<wordsCnt<<endl;
    // for(int i=0; i<words.size(); i++){
    //     cout<<words[i]<<endl;
    // }
    
    return 0;
}


