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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head == NULL || (head->next == NULL && n == 1))
            return NULL;
        
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            count++;
            curr = curr->next;
        }

        int x = count - n;
        count = 0;
        curr = head;

        if(x == 0)
            return head->next;

        while(curr != NULL)
        {
            count++;
            if(count == x)
            {
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};