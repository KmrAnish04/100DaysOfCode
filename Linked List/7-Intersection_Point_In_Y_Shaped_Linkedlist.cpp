/*
    Anish's solution
    Complexity Analysis:
    Time: O(N+M)
    Space: O(1)
*/


int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    int n = 0;
    int m = 0;
    Node *tmpNode = head1;
    while (tmpNode != NULL)
    {
        n++;
        tmpNode = tmpNode->next;
    }

    tmpNode = head2;
    while (tmpNode != NULL)
    {
        m++;
        tmpNode = tmpNode->next;
    }

    if (n == 1 && m == 1)
        return head1->data;
    int maxSize = max(n, m);
    int diff = abs(n - m);

    if (n > m)
    {
        for (int i = 0; i < diff; i++)
        {
            head1 = head1->next;
        }
    }
    else if (m > n)
    {
        for (int i = 0; i < diff; i++)
        {
            head2 = head2->next;
        }
    }

    int answer;
    Node *tmp1 = head1;
    Node *tmp2 = head2;
    while (tmp1 != NULL && tmp2 != NULL)
    {
        if (tmp1 == tmp2)
        {
            answer = tmp1->data;
            break;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    return answer;
}