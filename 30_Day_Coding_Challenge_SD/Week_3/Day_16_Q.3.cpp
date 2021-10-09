vector<int> serviceLane(int n, vector<vector<int>> cases, vector<int> width) {
    vector<int> ans;
    // cout<<cases[0][1];
    for(int i=0; i<cases.size(); i++){
        int minE=INT_MAX;
        for(int j=cases[i][0]; j<=cases[i][1]; j++){
            minE = min(minE, width[j]);
        }
        ans.push_back(minE);
    }
    
    return ans;
}