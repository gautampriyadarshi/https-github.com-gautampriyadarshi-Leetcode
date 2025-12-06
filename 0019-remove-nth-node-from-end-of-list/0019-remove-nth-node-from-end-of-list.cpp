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
        int m = 0;
        ListNode* ptr = head;

        while(ptr != NULL)
        {
            m++;
            ptr = ptr->next;
        }
        ptr = head;

        if(m == n)
            return head->next;
        
        for(int i = 1; i <= m; i++)
        {
            if(i == m-n) {
                ptr->next = ptr->next->next;
                break;
            }
            ptr = ptr->next;
        }
        return head;
    }
};