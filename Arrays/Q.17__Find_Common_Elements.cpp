
/*
    The below solution giving correct output but giving TLE in gfg comiler, need optimization.
*/

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> wholeArr;
            map<int,int>mapArr;
            map<int,int>mapBrr;
            map<int,int>mapCrr;
            vector<int> result;
                    
            for(int i=0; i<n1; i++){
                wholeArr.push_back(A[i]);
                if(mapArr[A[i]] == 0){
                    mapArr[A[i]] = 1;
                }
            }
            for(int i=0; i<n2; i++){
                wholeArr.push_back(B[i]);
                if(mapBrr[B[i]] == 0){
                    mapBrr[B[i]] = 1;
                }
            }
            for(int i=0; i<n3; i++){
                wholeArr.push_back(C[i]);
                if(mapCrr[C[i]] == 0){
                    mapCrr[C[i]] = 1;
                }
            }
            
            for(int i=0; i<wholeArr.size(); i++){
        
                if(mapArr[wholeArr[i]]==1 && mapBrr[wholeArr[i]]==1 && mapCrr[wholeArr[i]]==1){
                    result.push_back(wholeArr[i]);
                    mapArr[wholeArr[i]]=0;
                }
                
            }
            return result;
        }

};