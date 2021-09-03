int minJumps(int arr[], int n)
{
    // Your code here
    int maxR = arr[0];
    int steps = arr[0];
    int jmp = 1;

    if (maxR == 0)
        return -1;
    else if (n == 1)
        return 0;
    else if (maxR >= n - 1)
        return jmp;
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
            {
                return jmp;
            }

            maxR = max(maxR, i + arr[i]);
            if (maxR >= n - 1)
            {
                jmp++;
                return jmp;
            }

            steps--;
            if (steps == 0)
            {
                jmp++;
                if (maxR <= i)
                    return -1;
                steps = maxR - i;
            }
        }
    }
}