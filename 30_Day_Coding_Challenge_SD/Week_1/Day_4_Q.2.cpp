vector<int> breakingRecords(vector<int> scores) {
    int max=scores[0];
    int min=scores[0];
    vector<int> ans={0,0};
    
    for(int i=1; i<scores.size(); i++){
        if(scores[i]>max){
            ans[0]++;
            max=scores[i];
        }
        else if(scores[i]<min){
            ans[1]++;
            min=scores[i];
        }
        else{
            continue;
        }
    }
    
    return ans;    
}