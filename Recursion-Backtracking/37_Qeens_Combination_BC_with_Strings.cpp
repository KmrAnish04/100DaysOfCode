// *************************** RECURSION-BACKTRACKING ***************************

/*
    Problem Description: 
    Question Link: 
        GFG:
        Leetcode:
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/queens-combinations-2das2d-box-chooses-official/ojquestion
        nados: https://nados.io/question/queens-combinations-2d-as-2d-box-chooses?zen=true

    Complexity Analysis:
        Time:
        Space:

    Algorithm:

    
*/

#include<bits/stdc++.h>
using namespace std;

void queensPerm(string asf, int curQn, int noOfQn,int row, int col){
    if(row==noOfQn){
        if(curQn==noOfQn){
            cout<<asf<<endl;
        }
        return;
    }
    
    int nr=0;
    int nc=0;
    string yasf="";
    string nasf="";
    if(col==noOfQn-1){
        nr=row+1;
        nc=0;
        yasf = asf+"q\n"; 
        nasf = asf+"-\n";
        
    } 
    else{  
        nr=row; 
        nc=col+1; 
        yasf=asf+"q"; 
        nasf=asf+"-";
    }
    
    queensPerm(yasf, curQn+1, noOfQn, nr, nc);
    queensPerm(nasf, curQn, noOfQn, nr, nc);
}  
 

int main(){
    int size;
    cin>>size;

    queensPerm("", 0, size, 0, 0);

    return 0;
}


