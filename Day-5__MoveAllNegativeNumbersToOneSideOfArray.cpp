#include <stdio.h>

void sorter(int arr[], int n){
    int temp;
    int start=0;
    int end = n;
    for(int i=0; i<n; i++){
        if(arr[i]<0){
            arr[start]=arr[i];
            start++;
        }
        else{
            arr[end]=arr[i]
        }
    }
}

int main() {
	//code
	return 0;
}