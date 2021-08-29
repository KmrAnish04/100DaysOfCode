int minSwap(int *arr, int n, int k) {
    // Complet the function
    int good=0;
    int bad=0;
    int count=0;
    int start=0;
    int end;
    
    for(int i=0; i<n; i++){
        if(arr[i]<=k){
            good++;
        }
    }
    
    for(int j=0; j<good; j++){
        if(arr[j]>k) bad++;
    }
    end=good; count=bad;
    
    while(end<n){
        if(arr[start]>k) bad--;
        if(arr[end]>k) bad++;
        count=min(bad, count);
        start++;end++;
    }
    
    return count;
    
}
