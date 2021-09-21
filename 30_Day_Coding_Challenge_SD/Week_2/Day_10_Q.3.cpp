/*
    Anish's solution
        Time Complexity = O(N)
        Space Complexity = O(N)
*/

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    int aLength = a.size();
    int rot = k%aLength;
    int arr[aLength];
    int j=aLength-1;
    vector<int> ans;
    
    for(int i=rot-1; i>=0; i--){
        arr[i] = a[j];
        j--;    
    }
    
    for(int i=aLength-1; i>=rot; i--){
        arr[i] = a[j];
        j--;
    }
    
    for(int i=0; i<queries.size(); i++){
        ans.push_back(arr[queries[i]]);
    }
    
    return ans;
    
}