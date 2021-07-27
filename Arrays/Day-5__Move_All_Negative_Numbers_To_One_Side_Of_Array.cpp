#include <iostream>
using namespace std;

void sorter(int arr[], int n)
{

    // Rearranging the array.
    int temp;
    int end = n;
    for (int i = 0; i < end; i++)
    {
        if (arr[i] > 0)
        {
            temp = arr[i];
            for (int j = i; j < end; j++)
            {
                arr[j] = arr[j + 1];
            }
            arr[end - 1] = temp;
            i--;
            end--;
        }
    }

}

int main()
{
    //code
    int N;
    cin >> N;

    int arr[N];
    for (int k = 0; k < N; k++)
    {
        cin >> arr[k];
    }

    sorter(arr, N);

    // Printing the rearranged array.
    for (int l = 0; l < N; l++)
    {
        cout << arr[l];
        cout << ",";
    }

    return 0;
}