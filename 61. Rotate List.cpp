/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head or !head->next)
            return head;
        int len = 1;
        ListNode *ptr = head;

        while (ptr->next)
        {
            ++len;
            ptr = ptr->next;
        }

        ptr->next = head;
        k = k % len;
        k = len - k;

        while (k--)
        {
            ptr = ptr->next;
        }

        head = ptr->next;
        ptr->next = NULL;

        return head;
    }
};