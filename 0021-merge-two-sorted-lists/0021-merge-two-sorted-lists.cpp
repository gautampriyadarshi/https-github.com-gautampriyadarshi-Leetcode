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
        if(list1 == NULL && list2 == NULL)
            return NULL;
        else if(list1 == NULL)
            return list2;
        else if(list2 == NULL)
            return list1;

        vector<int> vec;
        ListNode* root = list1;
        while(root != NULL)
        {
            vec.push_back(root->val);
            root = root->next;
        }

        root = list2;
        while(root != NULL)
        {
            vec.push_back(root->val);
            root = root->next;
        }

        sort(vec.begin(), vec.end());

        ListNode* ans = new ListNode(vec[0]);
        ListNode* nd = ans;
        for(int i = 1; i < vec.size(); i++)
        {
            ListNode* node = new ListNode(vec[i]);
            nd->next = node;
            nd = nd->next;
        }
        return ans;
    }
};