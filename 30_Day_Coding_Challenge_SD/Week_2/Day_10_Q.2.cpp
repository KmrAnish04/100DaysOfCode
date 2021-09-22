// Time Complexity: O(N)
// Space Complexity: O(N)
int saveThePrisoner(int n, int m, int s) {
    int last = (m + (s-2))%n+1;
    return last;
    
}