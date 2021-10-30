class Solution
{
    int findZero(int fact){
        int zeros=0;
        int p=5;
        
        while(fact/p>0){
            zeros += fact/p;
            p *= 5;
        }
        
        return zeros;
    }
    
    public:
        int findNum(int n)
        {
            //complete the function here
            int l=0;
            int r=5*n;
            
            while(l<r){
                int mid = (l+r)/2;
                if(findZero(mid) < n) l = mid+1;
                else if(findZero(mid) >= n) r = mid;
            }
            
            return l;
        }