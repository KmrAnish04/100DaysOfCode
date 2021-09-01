#include <iostream>
#include <algorithm>

using namespace std;

int partitionFunc(int arr[], int low, int high)
{

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[high]);

    return i;
}

int quickSelect(int arr[], int low, int high, int k){
    
    int pI = partitionFunc(arr, low, high);

    if(pI > k){
        return quickSelect(arr, low, pI-1, k);
    }
    else if (pI < k)
    {
        return quickSelect(arr, pI+1, high, k);
    }
    else
    {
        return arr[pI];
    }
    
    
}

int main() {
    int sizeArr;
    cout<<"Enter size of array:: \n";
    cin>>sizeArr;

    int arr[sizeArr];
    int k;
    for (int i = 0; i < sizeArr; i++)
    {
        cout<<"Enter "<<i<<"th element of array\n";
        cin>>arr[i];
    }

    cout<<"Enter the k value:: \n";
    cin>>k;

    for (int j = 0; j < sizeArr; j++)
    {
        cout<<arr[j]<<" ";
    }
    
    cout<<"\n";
    int ans=quickSelect(arr , 0, sizeArr-1, k-1);
    cout<<k<<"(kth) smallest element is:: "<<ans;

    cout<<"\n";
    for (int j = 0; j < sizeArr; j++)
    {
        cout<<arr[j]<<" ";
    }
    
    
}