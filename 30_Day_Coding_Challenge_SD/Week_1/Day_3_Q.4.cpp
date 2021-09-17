void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int cntApp=0;
    int cntOrg=0;
    
    for(int i=0; i<apples.size(); i++){
        if(apples[i]>=0){
            if(a+apples[i]>=s && a+apples[i]<=t) cntApp++;
        }
    }
    
    for(int j=0; j<oranges.size(); j++){
        if(oranges[j]<0){
            if(b+oranges[j]>=s && b+oranges[j]<=t) cntOrg++;
        }
    }
    
    cout<<cntApp<<endl;
    cout<<cntOrg<<endl;
}