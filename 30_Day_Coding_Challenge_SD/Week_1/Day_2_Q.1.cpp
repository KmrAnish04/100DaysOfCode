int diagonalDifference(vector<vector<int>> arr) {
    int diagL=0;
    int diagR=0;
    int j=arr.size()-1;
    for(int i=0; i<arr.size(); i++){
        diagL += arr[i][i];
        diagR += arr[i][j];
        j--;
    }
    
    int ans=diagL-diagR;
    if(ans<0) ans *= -1;
    
    return ans;;
}
