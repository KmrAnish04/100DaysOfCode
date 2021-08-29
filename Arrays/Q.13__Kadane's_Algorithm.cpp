long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long tempSum=arr[0];
        long long finalSum=arr[0];
        
        for(int i=1; i<n; i++){
            if(tempSum>=0){
                tempSum+=arr[i];
            }
            else{
                tempSum=arr[i];
            }
            finalSum=max(tempSum, finalSum);
        }
        
        return finalSum;
    }