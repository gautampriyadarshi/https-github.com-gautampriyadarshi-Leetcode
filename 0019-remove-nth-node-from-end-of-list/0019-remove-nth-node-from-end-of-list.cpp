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
        if(head->next == NULL)
            return NULL;

        int count = 0;
        ListNode *root = head;

        while(root != NULL)
        {
            count++;
            root = root->next;
        }

        int x = count-n;
        count = 0;

        if(x == 0)
            return head->next;
            
        root = head;

        while(root != NULL)
        {
            count++;
            if(x == count)
            {
                if(root->next->next != NULL)
                {
                    root->next = root->next->next;
                    break;
                }
                root->next = NULL;
                break;
            }
            root = root->next;
        }
        return head;
    }
};