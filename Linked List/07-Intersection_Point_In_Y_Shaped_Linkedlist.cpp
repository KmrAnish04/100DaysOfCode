/*
    Anish's solution
    Question Link GFG: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/
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

/*
    Anish's Solution
    Same Question on LeetCode
    Solution for Leetcode question of the same problem
    Question Link Leetcode: https://leetcode.com/problems/intersection-of-two-linked-lists/
    Comlexity Analysis:
    Time: O(N+M)
    Space: O(1)

*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        int n = 0;
        int m = 0;
        ListNode *tmpNode = head1;
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

        cout << "n=" << n << endl;
        cout << "m=" << m << endl;

        // if(n==1 && m==1) return head1;
        int maxSize = max(n, m);
        int diff = abs(n - m);

        cout << "maxSize=" << maxSize << endl;
        cout << "diff=" << diff << endl;

        ListNode *newHead1 = head1;
        ListNode *newHead2 = head2;
        if (n > m)
        {
            for (int i = 0; i < diff; i++)
            {
                newHead1 = newHead1->next;
            }
        }
        else if (m > n)
        {
            for (int i = 0; i < diff; i++)
            {
                newHead2 = newHead2->next;
            }
        }

        cout << "newHead1=" << newHead1->val << endl;
        cout << "newHead2=" << newHead2->val << endl;

        ListNode *answer = NULL;
        ListNode *tmp1 = newHead1;
        ListNode *tmp2 = newHead2;
        while (tmp1 != NULL && tmp2 != NULL)
        {
            if (tmp1 == tmp2 && tmp1 != NULL && tmp2 != NULL)
            {
                answer = tmp1;
                break;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

        return answer;
    }
};