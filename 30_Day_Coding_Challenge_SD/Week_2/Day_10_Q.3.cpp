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

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> ans;
    int aLen = a.size();
    int rot = k%aLen;
    
    reverse(a.begin()+(aLen-k), a.end());
    reverse(a.begin(),a.end()-rot);
    reverse(a.begin(),a.end());
    

    for(int i=0; i<queries.size(); i++) ans.push_back(a[queries[i]]);
    
    return ans;
    
}