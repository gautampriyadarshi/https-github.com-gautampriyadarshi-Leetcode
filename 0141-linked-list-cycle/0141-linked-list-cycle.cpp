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
        ListNode* root = head;

        while(root != NULL)
        {
            if(mp[root] == true)
                return true;
            
            mp[root] = true;
            root = root->next;
        }
        return false;
    }
};