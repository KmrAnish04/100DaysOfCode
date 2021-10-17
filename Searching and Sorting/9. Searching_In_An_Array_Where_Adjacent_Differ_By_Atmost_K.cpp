int findIndex(int arr[], int n, int x, int k){
    //code
    int i=0;
    while(i < n)
    {
        int exEle=arr[i];
        int nEleAway=0;

        cout<<"1"<<endl;
        cout<<"exEle="<<exEle;
        cout<<" , ";
        cout<<"nEleAway="<<nEleAway;
        cout<<endl;

        if(arr[i]==x) return i;

        if(exEle<x){
            while(exEle<x){
            exEle+=k;
            nEleAway++;
            }    
        }
        else i++;
        
        cout<<"2"<<endl;
        cout<<"exEle="<<exEle;
        cout<<" , ";
        cout<<"nEleAway="<<nEleAway;
        cout<<endl;

        if (i+nEleAway<n)
        {
            i+=nEleAway;
        }
        else i+=1;
        cout<<"i="<<i<<endl;

    }

    return -1;
    
}


// One More Approach
// Time Complexity: O(N)
// Space Complexity: O(1)

// C++ program to search an element in an array
// where difference between adjacent elements is atmost k
#include<bits/stdc++.h>
using namespace std;
 
// x is the element to be searched in arr[0..n-1]
// such that all elements differ by at-most k.
int search(int arr[], int n, int x, int k)
{
    // Traverse the given array starting from
    // leftmost element
    int i = 0;
    while (i < n)
    {
        // If x is found at index i
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x)/k);
    }
 
    cout << "number is not present!";
    return -1;
}
 