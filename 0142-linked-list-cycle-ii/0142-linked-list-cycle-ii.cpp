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
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode* node = head;
        unordered_map<ListNode*, bool> mp;

        while(node != NULL)
        {
            if(mp[node])
                return node;

            mp[node] = true;
            node = node->next;
        }
        return NULL;
    }
};