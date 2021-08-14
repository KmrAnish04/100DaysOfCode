#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n) {
	    // code here
	    int i=0;
	    
	    while(arr[i]==0) i++;
	    
	    long long oP=arr[i];
	    long long cP=arr[i];
	    
	    for(int j=i+1; j<n; j++){
	        
	        if(arr[j] != 0){
	            cP *= arr[j];
	            oP = max(cP, oP);
                cout<<"In if, cp and op is:"<<cP<<"and"<<oP;
	        }
	        else if(i<n-1){
	            while(arr[j]==0) j++;
	            cP = 1;
	            
	        }
	    }
	    
	    return oP;
}

int main(){

    int n;
    cin>>n;
    factorials(n);

    return 0;
}