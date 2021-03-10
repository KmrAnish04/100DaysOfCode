#include <iostream>
using namespace std;

//User function template in C++

// a and b : given array with n and m size respectively

int doUnion(int a[], int n, int b[], int m)
{
    //code here
    int sizeA = n;
    int sizeB = m;
    int count = 0;
    int matchForA = 0;
    int matchforB = 0;
    
    

    ///////////For A///////////////

    for (int k = 0; k < sizeA; k++)
    {
        for (int l = 0; l < sizeA; l++)
        {
            if (k != l && (a[k] != 0 || a[l] != 0))
            {
                if (a[k] == a[l])
                {
                    a[l] = 0;
                    matchForA++;
                }
            }
        }
    }

    // for (int i = 0; i < sizeA; i++)
    // {
    //     cout << a[i];
    // }
    // cout << "New Array\n";
    int newA[n - matchForA];
    for (int i = 0; i < sizeA; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i; j < sizeA; j++)
            {
                a[j] = a[j + 1];
            }
        }
    }
    for (int i = 0; i < sizeA - matchForA; i++)
    {
        // cout << a[i];
        newA[i] = a[i];
    }

    ///////////For A Ending///////////////
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//
    ///////////For B///////////////

    for (int k = 0; k < sizeB; k++)
    {
        for (int l = 0; l < sizeB; l++)
        {
            if (k != l && (b[k] != 0 || b[l] != 0))
            {
                if (b[k] == b[l])
                {
                    b[l] = 0;
                    matchforB++;
                }
            }
        }
    }

    // for (int i = 0; i < sizeB; i++)
    // {
    //     cout << b[i];
    // }
    // cout << "New Array\n";
    int newB[m - matchforB];
    for (int i = 0; i < sizeB; i++)
    {
        if (b[i] == 0)
        {
            for (int j = i; j < sizeB; j++)
            {
                b[j] = b[j + 1];
            }
        }
    }
    for (int i = 0; i < sizeB - matchforB; i++)
    {
        // cout << b[i];
        newA[i] = newB[i];
    }

    ///////////For B Ending///////////////

    for (int i = 0; i < sizeA-matchForA; i++)
    {
        bool flag;
        for (int j = 0; j < sizeB-matchforB; j++)
        {
            if (newA[i] != newB[j])
            {
                flag = false;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            count++;
        }
    }

    if ((sizeA-matchForA) > (sizeB-matchforB))
    {
        count = (sizeB-matchforB) + count;
    }
    else if ((sizeB-matchforB) > (sizeA-matchForA))
    {
        count = (sizeA-matchForA) + count;
    }
    else
    {
        count = (sizeA-matchForA) + count;
    }

    cout<<count;
    return count;
}

int main()
{
    int n;
    int m;
    
    

    cout<<"Size of array A";
    cin>>n;
    int a[n];
    cout<<"Elements of Array A";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    cout<<"Size of array B";
    cin>>m;
    int b[m];
    cout<<"Elements of Array B";
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }

    doUnion(a, n, b, m);
    
    return 0;
}