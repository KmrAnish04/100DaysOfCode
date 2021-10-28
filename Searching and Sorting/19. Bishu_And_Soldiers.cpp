
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr, int l, int r, int x)
{
    int index;
    while (l <= r) {
        int m = (l+r)/ 2;
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m+1;
 
        // If x greater, ignore left half
        if (arr[m] < x){
            l = m + 1;
            index=m+1;
        }
 
        // If x is smaller, ignore right half
        else{
            r = m - 1;
            index=m;
        }
        // index = m;
        
    }
 
    // if we reach here, then element was
    // not present
    return index;
}

vector<int> bishuFight(vector<int> pows, int bishuPower){
    vector<int> result;
    vector<int> preSum;
    preSum.push_back(pows[0]);
    
    for (int i = 1; i < pows.size(); i++)
    {
        preSum.push_back(pows[i]+preSum[i-1]);
    }

    int a = binarySearch(pows, 0, pows.size()-1, bishuPower);
    // if (a==0)
    // {
    //     if (bishuPower>= pows[0])
    //     {
    //         result.push_back(a+1);
    //         result.push_back(preSum[0]);
    //     }
    //     else{
    //         result.push_back(0);
    //         result.push_back(0);
    //     }
    // }
    // else{
    //     result.push_back(a);
    //     result.push_back(preSum[a]);
    // }
    result.push_back(a);
    result.push_back(preSum[a-1]);

    // cout<<"binarySearch result="<<a<<endl;

    return result;
}

int main(){
    // cout<<"start"<<endl;
    int noOfSold;
    vector<int> solPow;
    int noOfRounds;
    
    
    cin>>noOfSold;
    for (int i = 0; i < noOfSold; i++)
    {
        int element;
        cin>>element;
        solPow.push_back(element); 
        // cout<<"input";   
    }

    // cout<<noOfSold<<endl; //
    // for (int i = 0; i < noOfSold; i++)
    // {
    //     cout<<solPow[i]<<" ";
    // }

    // cout<<endl;
    
    cin>>noOfRounds;
    // cout<<noOfRounds<<endl; //
    while(noOfRounds--){
        int bishuPow;
        cin>>bishuPow;
        // cout<<bishuPow; //
        // cout<<endl; //
        sort(solPow.begin(), solPow.end());
        vector<int> ans = bishuFight(solPow, bishuPow);
        if (!ans.empty())
        {
            // cout<<"[";
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            // cout<<"]";
        }
        else cout<<-1;
        cout<<endl;
    }
    // cout<<noOfSold<<endl;
    
    

    return 0;
}

