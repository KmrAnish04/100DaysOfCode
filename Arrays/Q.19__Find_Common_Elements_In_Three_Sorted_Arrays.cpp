class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            // Time Complexity = O(n1+n2+n3)
            // Space Complexity = O(n1+n2+n3)
            unordered_map<int,int>mapArr;
            unordered_map<int,int>mapBrr;
            unordered_map<int,int>mapCrr;
            vector<int> result;
                    
            for(int i=0; i<n1; i++){
                
                if(mapArr[A[i]] == 0){
                    mapArr[A[i]] = 1;
                }
            }
            for(int i=0; i<n2; i++){
                
                if(mapBrr[B[i]] == 0){
                    mapBrr[B[i]] = 1;
                }
            }
            for(int i=0; i<n3; i++){
                
                if(mapCrr[C[i]] == 0){
                    mapCrr[C[i]] = 1;
                }
            }
            
            for(int i=0; i<n1; i++){
        
                if(mapArr[A[i]]==1 && mapBrr[A[i]]==1 && mapCrr[A[i]]==1){
                    result.push_back(A[i]);
                    mapArr[A[i]]=0;
                }
                
            }
            for(int i = 0; i<result.size(); i++)
                printf("%d", result[i]);
            return result;
        }

};