#include <iostream>
using namespace std;

int merge(int arr[], int left, int mid, int right)
{

    int arrB[N];
    int i = left;
    int j = mid + 1;
    int k = right;
    int inv_count = 0;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            arrB[k] = arrB[i];
            i++;
        }
        else
        {
            arrB[k] = arrB[j];
            j++;
            inv_count = inv_count + mid - i
        }
        k++;

        if (i > mid)
        {
            while (j <= right)
            {
                arrB[k] = arrB[j];
                j++;
                k++;
            }
        }
        else
        {
            while (i <= mid)
            {
                arrB[k] = arrB[i];
                i++;
                j++;
            }
        }
    }

    for (int l = left; l < right; l++)
    {
        arr[k] = arrB[l];
    }

    return 0;
}

int mergeSort(int arr[], left, right){

    int mid, inv_count = 0;
    if (left < right)
    {
        int mid = (left+right)/2;
        inv_count += mergeSort(arr, left, right);
        inv_count += mergeSort(arr, mid+1, right);

        inv_count += merge(arr, right, mid+1, right);
    }

    return inv_count;
    
}