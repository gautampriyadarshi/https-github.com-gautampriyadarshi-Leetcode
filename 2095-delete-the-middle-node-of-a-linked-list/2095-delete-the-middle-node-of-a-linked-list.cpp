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
    ListNode* deleteMiddle(ListNode* head) 
    {
        int count = 0, x = 0;
        ListNode* node = head;

        while(node != NULL)
        {
            count++;
            node = node->next;
        }

        if(count == 1)
            return NULL;

        node = head;
        while(node != NULL)
        {
            x++;
            if(x == count/2)
            {
                node->next = node->next->next;
                break;
            }
        
            node = node->next;
        }
        return head;
    }
};