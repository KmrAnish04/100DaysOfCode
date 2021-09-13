vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    map<int, int> mapArr;
    vector<int> res;
    for(int i=0; i<ranked.size(); i++){
        mapArr[ranked[i]]++;
    }
    
    int j=0;
    int rank=mapArr.size();
    map<int, int>::iterator i;
    // cout<<it<<endl;
    for(i = mapArr.begin(); i != mapArr.end(); ){
        // cout<<i->first;
        if(player[j]<(i->first)){
            res.push_back(rank+1);
            // cout<<"line 34,,"<<i->first<<" "<<player[j]<<endl;
            j++; 
            // i--;
            // cout<<"line 36,,"<<i->first<<" "<<player[j]<<endl;
            
        }
        else if(player[j]==(i->first)){
            res.push_back(rank);
            j++; rank--; i++;
            // cout<<"line 40"<<endl;
        }
        else if(player[j]>=(i->first) && rank==1){
            res.push_back(1);
            // cout<<"line 43"<<endl;
            break;
        }
        else{
            rank--; i++;
            // cout<<"line 49"<<endl;
            continue;
        }
    }
    
    return res;
}
