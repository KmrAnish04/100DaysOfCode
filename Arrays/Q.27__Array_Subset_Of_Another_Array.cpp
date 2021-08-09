#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    
    bool ans=0;
    unordered_map<int, int>map;
    a
    for(int i=0; i<n; i++){
        map[a1[i]]++;
    }
    
    for(int j=0; j<m; j++){
        if(map[a2[j]]>=1){
            ans=1;
        }
        else{
            ans=0;
            break;
        }
    }
    
    if (ans) return "Yes";
    else
        return "No";
    
}