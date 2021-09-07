void miniMaxSum(vector<int> arr) {
    long int minSum=0;
    long int maxSum=0;
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<arr.size()-1; i++){
        minSum += arr[i];
    }
    
    for(int j=1; j<arr.size(); j++){
        maxSum += arr[j];
    }
    
    cout<<minSum<<" "<<maxSum;

}