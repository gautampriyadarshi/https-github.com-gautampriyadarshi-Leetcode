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
    int gcd(int x, int y)
    {
        int mini = min(x,y);
        while(mini > 0)
        {
            if(x % mini == 0 && y % mini == 0)
                break;
            
            mini--;
        }
        return mini;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) 
    {
        if(head == NULL || head->next == NULL) 
            return head;

        ListNode* cur = head->next;
        ListNode* prev = head;

        while(cur != NULL)
        {
            ListNode* temp = new ListNode(gcd(cur->val, prev->val));
            temp->next = cur;
            prev->next = temp;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};