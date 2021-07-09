#include <iostream>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right){

    int inv = 0;
    int i = left;
    int j = mid;
    int k = left;

    while ((i <= mid - 1) && (j <= right)){
        if (arr[i] <= arr[j])
        {
            temp[k++] = temp[i++];
        }
        else
        {
            temp[k++] = temp[j++];
            inv = inv + (mid - i); // Main part
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[j++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (int l = left; l <= right; l++)
    {
        arr[l] = temp[l];
    }

    printf("this is merge function\n");
    return inv;
}

int mergeSort(int arr[], int temp[], int left, int right){

    int inv = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid + 1, right);
        inv += merge(arr, temp, left, mid + 1, right);
    }
    printf("this is mergesort function\n");
    return inv;
}

// int inversionCount(int arr[], int N)
// {
//     // Your Code Here
//     int temp[N];
//     int ans = mergeSort(arr, temp, 0, N - 1);
//     printf("%d\n", ans);
//     printf("this is inv count function\n");
//     return ans;
// }

int main()
{
    /* code */
    int N = 5;
    int arr[N] = {2, 4, 1, 3, 5};
    int temp[N];
    // inversionCount(arr, N);
    int ans = mergeSort(arr, temp, 0, N - 1);
    printf("%d\n", ans);

    return 0;
}
