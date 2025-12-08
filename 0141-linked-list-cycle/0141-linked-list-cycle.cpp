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
        unordered_map<ListNode*, bool> mp;
        ListNode* node = head;

        while(node != NULL)
        {
            if(mp[node])
                return true;
            
            mp[node] = true;
            node = node->next;
        }
        return false;
    }
};