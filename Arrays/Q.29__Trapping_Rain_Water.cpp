


long long trappingWater(int arr[], int n){
        // code here
        int maxL[n];
        int maxR[n];
        int water[n];
        long long ans=0;
        
        maxL[0]=arr[0];
        maxR[n-1]=arr[n-1];
        
        for(int i=1; i<n; i++){
            maxL[i] = max(maxL[i-1], arr[i]);
        }
        
        for(int j=n-2; j>=0; j--){
            maxR[j] = max(maxR[j+1], arr[j]);
        }
        
        for(int k=0; k<n; k++){
            water[k] = min(maxL[k], maxR[k]) - arr[k];
        }
        
        for(int l=0; l<n; l++){
            ans += water[l];
        }
        
        return ans;
    }