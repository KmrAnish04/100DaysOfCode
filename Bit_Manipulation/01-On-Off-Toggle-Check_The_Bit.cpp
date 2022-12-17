// *************************** Bit Manipulation ***************************

/*
    Problem Description: 
    Question Link: 
        GFG: 
        Leetcode: 
        pepcoding: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/bit-manipulation/basics-of-bit-official/ojquestion
        nados: 

    Complexity Analysis:
        Expected Time Complexity: 
        Expected Auxiliary Space: 

    Algorithm:
        Explaination Video: https://www.youtube.com/watch?v=v62IKeJtj0k&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe

    
*/


// Code Starts Here
#include<bits/stdc++.h>
using namespace std;


int main(){
    int num, i, j, k, m;
    cin>>num>>i>>j>>k>>m;
    
    int onMask = (1<<i);
    int offMask = ~(1<<j);
    int togMask = (1<<k);
    int chkMask = (1<<m);
    
    cout<<(num|onMask)<<endl;
    cout<<(num&offMask)<<endl;
    cout<<(num^togMask)<<endl;
    (num&chkMask)>0 ? cout<<"true":cout<<"false";
    
    return 0;
    
    
}




// Code Ends Here