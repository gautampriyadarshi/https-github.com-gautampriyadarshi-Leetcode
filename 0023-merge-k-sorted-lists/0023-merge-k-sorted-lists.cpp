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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size() == 0)
            return NULL;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < lists.size(); i++)
        {
            ListNode* node = lists[i];
            while(node != NULL)
            {
                pq.push(node->val);
                node = node->next;
            }
        }

        if(pq.empty())
            return NULL; 

        ListNode* root = new ListNode(pq.top());
        pq.pop();
        ListNode* node = root;

        while(!pq.empty())
        {
            ListNode* nd = new ListNode(pq.top());
            node->next = nd;
            node = nd;
            pq.pop();
        }

        return root;
    }
};