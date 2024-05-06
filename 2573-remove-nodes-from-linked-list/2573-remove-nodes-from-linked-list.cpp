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
/*
// Time Limit Exceeded: 27/32 cases passes
class Solution {
public:
    ListNode* removeNodes(ListNode* head) 
    {
        if(head->next == NULL)
            return head;
        
        vector<int> given;
        ListNode* node = head;
        while(node != NULL)
        {
            given.push_back(node->val);
            node = node->next;
        }
        
        for(int i = 0; i < given.size(); i++)
        {
            for(int j = given.size()-1; j > i; j--)
            {
                if(given[j] > given[i])
                {
                    given[i] = INT_MAX;
                    break;
                }
            }
        }

        ListNode* h1 = new ListNode();
        ListNode* temp = h1;
        for(auto it: given)
        {
            if(it != INT_MAX)
            {
                temp->next = new ListNode();
                temp = temp->next;
                temp->val = it;
            }
        }
        return h1->next;
    }
};  */