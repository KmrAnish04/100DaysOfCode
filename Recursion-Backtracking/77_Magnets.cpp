#include<bits/stdc++.h>
using namespace std;

void print2dVec(vector<vector<char>> arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


void print1dVec(vector<int> arr){
    cout<<endl;
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int cntInRow(vector<vector<char>>&ans, vector<int>frq, char sign, int row){
    int cnt=0;
    
    for(int i=0; i<ans[0].size(); i++){
        if(ans[row][i]==sign) cnt++;
    }
    
    return cnt;
}


int cntInCol(vector<vector<char>>&ans, vector<int>frq, char sign, int col){
    int cnt=0;
    
    for(int i=0; i<ans.size(); i++){
        if(ans[i][col]==sign) cnt++;
    }
    
    return cnt;
}


bool isSignValid(vector<vector<char>>&ans, vector<int>top, vector<int>left, vector<int>right, vector<int>bottom, int row, int col, char sign){
    
    if( (col-1>=0 && ans[row][col-1]==sign) || (row-1>=0 && ans[row-1][col]==sign) || (col+1<ans[0].size() && ans[row][col+1]==sign) ){
        return false;
    }
    
    if(sign=='+'){
        int cinc = cntInCol(ans, top, sign, col);
        int cinr = cntInRow(ans, left, sign, row);
        
        if(top[col]!=-1 && cinc>=top[col]){
            return false;
        }
        if(left[row]!=-1 && cinr>=left[row]){
            return false;
        }
    }
    else{
        int cinc = cntInCol(ans, bottom, sign, col);
        int cinr = cntInRow(ans, right, sign, row);
        
        if(bottom[col]!=-1 && cinc>=bottom[col]){
            return false;
        }
        if(right[row]!=-1 && cinr>=right[row]){
            return false;
        }
        
    }
    
    
    return true;
}


bool isAnsValid(vector<vector<char>>&ans, vector<int>top, vector<int>left, vector<int>right, vector<int>bottom){
    
    for(int i=0; i<top.size(); i++){
        int cinc = cntInCol(ans, top, '+', i);
        if(top[i]!=-1 && cinc!=top[i]){
            return false;
        }
    } 
     
    for(int i=0; i<left.size(); i++){
        int cinr = cntInRow(ans, left, '+', i);
        if(left[i]!=-1 && cinr!=left[i]){
            return false;
        }
    }
     
    for(int i=0; i<bottom.size(); i++){
        int cinc = cntInCol(ans, bottom, '-', i); 
        if(bottom[i]!=-1 && cinc!=bottom[i]){
            return false; 
        }
    }
    
    for(int i=0; i<right.size(); i++){
        int cinr = cntInRow(ans, right, '-', i);
        if(right[i]!=-1 && cinr!=right[i]){
            return false;
        }
    }
    
    
    return true;
}


bool solution(vector<vector<char>>&cont, vector<vector<char>>&ans, vector<int>top, vector<int>left, vector<int>right, vector<int>bottom, int row, int col){
    
    if(col==cont[0].size()){
        col=0;
        row++;
    } 
    
    if(row==cont.size()){
        if(isAnsValid(ans, top, left, right, bottom)){
            return true;
        }
        return false;
    }
    
    
    
    if(cont[row][col]=='L'){
        
        // +,-
        if(isSignValid(ans, top, left, right, bottom, row, col, '+') && isSignValid(ans, top, left, right, bottom, row, col+1, '-')){
            ans[row][col]='+';
            ans[row][col+1]='-';
            if(solution(cont, ans, top, left, right, bottom, row, col+2)){
                return true;
            }
            ans[row][col]='X';
            ans[row][col+1]='X';
        }
        
        // -,+
        if(isSignValid(ans, top, left, right, bottom, row, col, '-') && isSignValid(ans, top, left, right, bottom, row, col+1, '+')){
            ans[row][col]='-';
            ans[row][col+1]='+';
            if(solution(cont, ans, top, left, right, bottom, row, col+2)){
                return true;
            }
            ans[row][col]='X';
            ans[row][col+1]='X';
            
        }
        
    }
    else if(cont[row][col]=='T'){
        
        // +,-
        if(isSignValid(ans, top, left, right, bottom, row, col, '+') && isSignValid(ans, top, left, right, bottom, row+1, col, '-')){
            ans[row][col]='+';
            ans[row+1][col]='-';
            if(solution(cont, ans, top, left, right, bottom, row, col+1)){
                return true;
            }
            ans[row][col]='X';
            ans[row+1][col]='X';
        }
        
        // -,+
        if(isSignValid(ans, top, left, right, bottom, row, col, '-') && isSignValid(ans, top, left, right, bottom, row+1, col, '+')){
            ans[row][col]='-';
            ans[row+1][col]='+';
            if(solution(cont, ans, top, left, right, bottom, row, col+1)){
                return true;
            }
            ans[row][col]='X';
            ans[row+1][col]='X';
            
        }
    }
    
    bool noCall=solution(cont, ans, top, left, right, bottom, row, col+1);
    if(noCall==true){
        return true;
    }
    
    return false;
    
}

int main(){
    int m;
    int n;
    cin>>m;
    cin>>n;
    
    vector<vector<char>> ans(m, vector<char>(n,'X'));
    vector<vector<char>> container(m, vector<char>(n));
    vector<int> top(n);
    vector<int> left(m);
    vector<int> right(m); 
    vector<int> bottom(n);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            char ele;
            cin>>ele;
            container[i][j]=ele;
        }
    }
    
    for(int i=0; i<n; i++){
        int ele; 
        cin>>ele;
        top[i]=ele;
    }
    for(int i=0; i<m; i++){
        int ele;
        cin>>ele;
        left[i]=ele; 
    } 
    for(int i=0; i<m; i++){
        int ele;
        cin>>ele;
        right[i]=ele;
    }
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        bottom[i]=ele;
    }  
    
    if(!solution(container, ans, top, left, right, bottom, 0, 0)){
        cout<<"No Solution";
        return 0;
    }
    
    print2dVec(ans);    
    
    return 0;
}