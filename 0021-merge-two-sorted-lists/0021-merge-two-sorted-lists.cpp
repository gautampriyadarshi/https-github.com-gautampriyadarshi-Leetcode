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
        if(list1 == NULL && list2 != NULL)
            return list2;
        
        if(list2 == NULL && list1 != NULL)
            return list1;
        
        if(list1 == NULL && list2 == NULL)
            return NULL;
        
        vector<int> help;
        ListNode* curr = list1;

        while(curr != NULL)
        {
            help.push_back(curr->val);
            curr = curr->next;
        }

        curr = list2;
        while(curr != NULL)
        {
            help.push_back(curr->val);
            curr = curr->next;
        }

        sort(help.begin(), help.end());
        ListNode* ans = new ListNode(help[0]);
        ListNode* nd = ans;

        for(int i = 1; i < help.size(); i++)
        {
            ListNode* node = new ListNode(help[i]);
            nd->next = node;
            nd = nd->next;
        }
        help.clear();
        
        return ans;
    }
};