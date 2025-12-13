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
        unordered_map<ListNode*, bool> mp;
        ListNode* node1 = headA;
        ListNode* node2 = headB;

        while(node1 != NULL)
        {
            mp[node1] = true;
            node1 = node1->next;
        }

        while(node2 != NULL)
        {
            if(mp[node2])
                return node2;
            
            node2 = node2->next;
        }
        return NULL;
    }
};