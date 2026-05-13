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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1 && !list2)
            return NULL;
        
        if(list1 && !list2)
            return list1;
        
        if(!list1 && list2)
            return list2;
        
        vector<int> num;
        ListNode* curr = list1;

        while(curr)
        {
            num.push_back(curr->val);
            curr = curr->next;
        }

        curr = list2;
        while(curr)
        {
            num.push_back(curr->val);
            curr = curr->next;
        }

        sort(num.begin(), num.end());

        ListNode* head = new ListNode(num[0]);
        curr = head;
        for(int i = 1; i < num.size(); i++)
        {
            ListNode* node = new ListNode(num[i]);
            curr->next = node;
            curr = curr->next;
        }
        return head;
    }
};