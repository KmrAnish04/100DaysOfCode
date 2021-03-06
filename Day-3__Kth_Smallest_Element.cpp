// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    //code here

    // Insertion Sort Technique
    int temp;
    int j;
    //Sorting the array
    for(int i=1; i<r+1; i++){
        temp = arr[i];
        j = i-1;
        
        while(i>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
    return arr[k-1];

    //Bubble Sort Technique
    // int temp;
    // for(int i=0; i<r+1; i++){
    //     int flag = 0;
        
    //     for(int j=0; j<r+1-i; j++){
            
    //         if(arr[j]>arr[j+1]){
    //             temp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = temp;
    //             flag = 1;
    //         }
    //     }
    //     if(flag == 0){
    //     break;}
        
    
    // }
    // for(int m=0; m<r+1; m++){
    //     cout<<arr[m];
    //     cout<<"a";
    // }
    // return arr[k-1];
}