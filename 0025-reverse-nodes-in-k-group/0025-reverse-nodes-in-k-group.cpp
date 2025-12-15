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
    void add(vector<int> &vec, vector<int> help)
    {
        for(int i = 0; i < help.size(); i++)
        {
            vec.push_back(help[i]);
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        vector<int> vec, help;
        ListNode* node = head;
        int x = 0;

        while(node != NULL)
        {
            help.push_back(node->val);
            x++;

            if(x == k)
            {
                reverse(help.begin(), help.end());
                add(vec, help);
                help.clear();
                x = 0;
            }
            node = node->next;
        }

        if(x != 0)
        {
            add(vec, help);
            help.clear();
            x = 0;
        }

        ListNode* ans = new ListNode(vec[0]);
        ListNode* nd = ans;

        for(int i = 1; i < vec.size(); i++)
        {
            ListNode* n = new ListNode(vec[i]);
            ans->next = n;
            ans = ans->next;
        }

        return nd;
    }
};