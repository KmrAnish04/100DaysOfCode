vector<int> solve(vector<vector<int>> mat){

    map<int,vector<int>> scores;
    for(int i=0; i<mat.size(); i++){
        int id=mat[i][0];
        int score=mat[i][1];

        scores[score].push_back(id);
    }

    int i=1;
    vector<int> ans; 
    for(auto it: scores){
        if(i==2){
            ans=it.second;
        }
        i++;
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}