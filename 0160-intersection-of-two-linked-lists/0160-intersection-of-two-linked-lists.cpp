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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_map<ListNode*, int> mp;
        ListNode* n1 = headA;
        while(n1 != NULL)
        {
            mp[n1]++;
            n1 = n1->next;
        }

        ListNode* n2 = headB;
        while(n2 != NULL)
        {
            if(mp[n2] > 0)
                return n2;

            n2 = n2->next;
        }
        return NULL;
    }
};