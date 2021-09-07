


long long trappingWater(int arr[], int n){
        // code here
        int maxL = arr[0]; 
        int maxR[n];
        long long ans=0;
        
        maxR[n-1]=arr[n-1];
        
        for(int j=n-2; j>=0; j--){
            maxR[j] = max(maxR[j+1], arr[j]);
        }
        
        for(int k=0; k<n; k++){
            maxL = max(maxL, arr[k]); // this maxL variable doing the same thing as maxR for left array.
            ans += min(maxL, maxR[k]) - arr[k];
        }
        
        
    }