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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left == right)
            return head;
        
        vector<int> vec;
        ListNode* root = head;

        while(root != NULL)
        {
            vec.push_back(root->val);
            root = root->next;
        }

        int x = vec.size() - right;
        reverse(vec.begin() + left -1, vec.end() - x);

        ListNode* ans = new ListNode(vec[0]);
        ListNode* nd = ans;
        for(int i = 1; i < vec.size(); i++)
        {
            ListNode* here = new ListNode(vec[i]);
            nd->next = here;
            nd = nd->next;
        }
        head = NULL;
        return ans;
    }
};