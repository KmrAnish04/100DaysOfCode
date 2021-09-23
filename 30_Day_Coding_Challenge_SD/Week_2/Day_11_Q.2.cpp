vector<int> cutTheSticks(vector<int> arr) {
    vector<int> ans;
    sort(arr.begin(), arr.end());
    ans.push_back(arr.size());
    for(int i=1; i<arr.size(); i++){
        if(arr[i-1]!=arr[i]){
            ans.push_back((arr.size()-1)-(i-1));
        }
    }
    return ans;

}