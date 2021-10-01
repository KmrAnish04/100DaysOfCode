// Solution by Anish
// Brute-force Approach
// Time Complexity: O(N)
// Space Complexity: O(1)
int size=topic.size();
    int strSize=topic[0].size();
    vector<int> ans={};
    int maxSoFar=INT_MIN;
    int intelTeams=0;
    
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            int subCnt=0;
            for(int k=0; k<strSize; k++){
                if(topic[i][k] == '1' || topic[j][k] == '1') subCnt++;
            }
            maxSoFar=max(maxSoFar, subCnt);
        }
    }
    
    for(int i=0; i<size-1; i++){
        for(int j=i+1; j<size; j++){
            int subCnt=0;
            for(int k=0; k<strSize; k++){
                if(topic[i][k] == '1' || topic[j][k] == '1') subCnt++;
            }
            if(subCnt==maxSoFar) intelTeams++;
        }
    }
    
    ans.push_back(maxSoFar);
    ans.push_back(intelTeams);
    
    return ans;

}



// Solution by Hackerrank Editorial
// Brute-force Approach- Same as above but time Complexity is few better than above. 
// Time Complexity: O(N)
// Space Complexity: O(1)
int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int val = 0;
            for (int k = 0; k < m; k++) {
                if (v[i][k] == '1' || v[j][k] == '1') {
                    val++;
                }
            }
            if (ans < val) {
                ans = val;
                cnt = 1;
            } else if (ans == val) {
                cnt++;
            }
        }
    }
    cout << ans << endl << cnt << endl;
    return 0;
}