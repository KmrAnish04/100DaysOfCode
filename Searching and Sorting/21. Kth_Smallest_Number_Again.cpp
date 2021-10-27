
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;                                       // Reading input from STDIN
    
    // int ans = -1;
    
    while(t--){
        int n,q;
        vector<pair<int, int>> arr;
        cin >> n >> q;

        for(int i=0; i<n; i++){
            int a, b;
            cin>>a>>b;
            arr.push_back({a,b});
        }

        sort(arr.begin(), arr.end());

        int idx = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[idx].second>=arr[i].first){
                arr[idx].second = max(arr[i].second, arr[idx].second);
            }
            else{
                idx++;
                arr[idx] = arr[i];
            }
        }

    // for(int i=0; i<arr.size(); i++){
    //     cout<<"Element1: "<<arr[i].first<< " ," <<"Element2: "<< arr[i].second<<"\n"; 
    // }

        while(q--){
            int k;
            cin>>k;
            int ans = -1;

            for (int i = 0; i < idx; i++)
            {
                if((arr[i].second-arr[i].first+1)>=k){
                    ans = arr[i].first+k-1;
                    break;
                }
                else{
                    k = k - (arr[i].second-arr[i].first);
                }
            }

            cout<< ans<<endl;
        }

    }

    

    
}