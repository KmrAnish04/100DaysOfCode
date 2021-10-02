// Solution by Anish
// Using Hashing/maps
// Time Complexity: O(N)
// Space Complexity: O(N)
int beautifulTriplets(int d, vector<int> arr) {
    int size=arr.size();
    unordered_map<int, int> map;
    int count=0;
    for(int i=0; i<size; i++){
        map[arr[i]]++;
    }
    
    for(int i=0; i<=size-3; i++){
        int tplt1 = arr[i]+d;
        int tplt2 = tplt1+d;
        if(map[tplt1]>=1 && map[tplt2]>=1) count++;
    }
    
    return count;
}
