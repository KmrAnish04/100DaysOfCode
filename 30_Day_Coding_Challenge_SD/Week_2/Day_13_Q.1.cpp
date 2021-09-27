/*
    Time Complexity: O(NlogN)
    Space Complexity: O(1)

    This solution can also be done using hash maps in O(N) Time Complexity but Space Complexity will be also O(N) 
*/

int equalizeArray(vector<int> arr) {
    int maxs=1;
    int tempMx=1;
    
    sort(arr.begin(), arr.end());
    for(int i=1; i<arr.size(); i++){
        if(arr[i-1]==arr[i]) tempMx++;
        else tempMx=1;
        maxs=max(maxs, tempMx);
    }
    
    return arr.size()-maxs;
}