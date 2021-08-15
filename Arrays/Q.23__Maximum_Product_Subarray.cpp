#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long maxProduct(int *arr, int n){
    long long ma=arr[0];
	   long long mi=arr[0];
	   long long product=arr[0];
	   
	   for(int i=1; i<n; i++){
	       if(arr[i]<0){
	           swap(ma, mi);
	       }
	       
	       ma=max((long long)arr[i], arr[i]*ma);
	       mi=min((long long)arr[i], arr[i]*mi);
	       
	       if(ma>product){
	           product=ma;
	       }
	   }
	   
	   return product;


}