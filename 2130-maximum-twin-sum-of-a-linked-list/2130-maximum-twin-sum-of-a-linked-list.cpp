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
    int pairSum(ListNode* head) 
    {
        vector<int> help;
        ListNode* node = head;

        while(node != NULL)
        {
            help.push_back(node->val);
            node = node->next;
        }

        int n = help.size();
        int maxi = 0, j = n-1, sum = 0;
        for(int i = 0; i < n/2; i++)
        {
            sum = help[i]+help[j];
            maxi = max(maxi, sum);
            j--;
        }
        return maxi;
    }
};