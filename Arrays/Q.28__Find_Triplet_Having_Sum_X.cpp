bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        bool ans = false;
        int sum;
        
        sort(A, A+n);
        // for(int m=0; m<n; m++)cout<<A[m];
        
        for(int i=0; i<n-2; i++){
            int j=i+1;
            int k=n-1;
            
            while(ans==false && j<k){
                sum = A[i]+A[j]+A[k];
                
                if(sum<X)j++;
                
                else if(sum>X)k--;
                
                else if(sum==X)ans=true;
            }
        }
        
        return ans;
    }