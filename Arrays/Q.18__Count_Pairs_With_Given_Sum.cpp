class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int count = 0;
        unordered_map<int,int>mapArr;
        
        for(int i=0; i<n; i++){
            int x = k-arr[i];
            
            if(mapArr[x]==0){
                mapArr[arr[i]]++;
            }
            else{
                count += mapArr[x];
                mapArr[arr[i]]++;
            }
        }
        
        return count;
    }
};