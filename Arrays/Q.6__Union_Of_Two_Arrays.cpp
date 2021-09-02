int doUnion(int a[], int n, int b[], int m)  {
        //code here
        unordered_map<int, int>arrb;
        int ans=0;
        
        for(int i=0; i<n; i++){
            if(arrb[a[i]]==0){
                arrb[a[i]]++;
            }
        }
        
        for(int j=0; j<m; j++){
            if(arrb[b[j]]==0){
                arrb[b[j]]++;
            }
        }
        
        ans=arrb.size();
        
        return ans;
    }