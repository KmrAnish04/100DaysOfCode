/*
    Time Complexity: O(N log N)
    Space Complexity: O(1)
*/
bool findPair(int arr[], int size, int n){
    //code
    int i=0;
    int j=i+1;
    bool found=false;
    
    sort(arr, arr+size);
    
    while(j<size){
        int diff = abs(arr[i]-arr[j]);
        if(diff<n) j++;
        else if(diff>n) i++;
        else if(diff==n){
            found=true;
            break;
        }
        
        if(i==j) j++;
    }
    return found;
    
}