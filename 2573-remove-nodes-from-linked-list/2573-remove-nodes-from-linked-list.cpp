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
    vector<int> carry;
    int maxx=0;

    void reverse_traverse(ListNode* head)
    {
        if(head == NULL)
            return;

        reverse_traverse(head->next);
        if(head->val >= maxx)
        {
            maxx=max(maxx,head->val);
            carry.emplace_back(maxx);
        }
        
    }

    ListNode* removeNodes(ListNode* head) 
    {
        reverse_traverse(head);
        reverse(carry.begin(),carry.end());

        ListNode* h1 = new ListNode();
        ListNode* temp = h1;

        for(auto it:carry)
        { 
            temp->next = new ListNode();
            temp = temp->next;
            temp->val = it;
        }
        return h1->next;
    }
};