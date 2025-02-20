/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast != NULL)
        {
            if(fast->next != NULL && fast->next->next != NULL)
            {
                if(fast->next == slow || fast->next->next == slow)
                    return true;
                
                slow = slow->next;
                fast = fast->next->next;
            }
            else
                return false;
        }
        return false;
    }
};