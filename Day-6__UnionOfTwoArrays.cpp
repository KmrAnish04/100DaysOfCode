#include<iostream>
using namespace std;

//User function template in C++

// a and b : given array with n and m size respectively

int doUnion(int a[], int n, int b[], int m)  {
    //code here
    int count = 0;
    
    
    for(int i=0; i<n; i++){
        bool flag;
        for(int j=0; j<m; j++){
            if(a[i]!=b[j]){
                flag=false;
            }
            else{
                flag=true;
                break;
            }
        }
        if(flag==false){
                count++;
            }
    }
    
    if(n>m){
        count = m+count;
    }
    else if(m>n){
        count = n+count;
    }
    else{
        count = n+count;
    }
    
    return count;
}

int main(){
    
}