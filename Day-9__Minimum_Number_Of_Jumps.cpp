#include<iostream>
using namespace std;

int minJumps(int arr[], int n){
        // Your code here
        int jumps = 0;
        int indexer1 = arr[0];
        int indexer2 = 0;
        jumps++;

	jump++;
    if(i>=maxReach)
       return -1;
    step = maxReach - i;
	}
        
        for(int i=indexer1; i<n; i++){
            i--;
            indexer2 = arr[i];
            
            if(indexer2 >= n-1-indexer1){
                jumps++;
                cout<<"in if"<<indexer1<<indexer2<<"\n";
                break;
            }
            else{
                indexer1 = indexer1 + indexer2;
                i = indexer1;
                cout<<"in else"<<indexer1<<indexer2<<"\n";
                jumps++;
            }
        }
        
        cout<<jumps;
        return jumps;
    }

int main(){
    int n = 11;
    int arr[11] = {1,3,5,8,9,2,6,7,6,8,9};

    minJumps(arr, n);
}