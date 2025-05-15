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
    ListNode* sortList(ListNode* head) 
    {
        vector<int> vec;
        ListNode* node = head;
        while(node != NULL)
        {
            vec.push_back(node->val);
            node = node->next;
        }
        sort(vec.begin(), vec.end());
        
        ListNode* help = head;
        int i = 0;
        while(help != NULL)
        {
            help->val = vec[i];
            help = help->next;
            i++;
        }
        return head;
    }
};