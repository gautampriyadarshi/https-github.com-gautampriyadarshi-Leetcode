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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL)
            return NULL;
            
        vector<int> vec, main;
        ListNode* node = head;

        while(node != NULL)
        {
            vec.push_back(node->val);
            node = node->next;
        }

        int n = vec.size();
        int x = k % n;
        for(int i = n-x; i < n; i++)
        {
            main.push_back(vec[i]);
        }

        for(int i = 0; i < n-x; i++)
        {
            main.push_back(vec[i]);
        }
        vec.clear();

        ListNode* ans = new ListNode(main[0]);
        ListNode* nd = ans;
        for(int i = 1; i < main.size(); i++)
        {
            ListNode* n = new ListNode(main[i]);
            ans->next = n;
            ans = n;
        }
        return nd;
    }
};