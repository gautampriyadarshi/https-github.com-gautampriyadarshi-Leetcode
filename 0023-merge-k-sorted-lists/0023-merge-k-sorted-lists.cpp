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
    ListNode* mergeKLists(vector<ListNode*>& arr) 
    {
        if(arr.size() == 0)
            return NULL;
        
        if(arr.size() == 1)
            return arr[0];
        
        vector<int> vec;
        int x = 0, K = arr.size();
        while(x < K)
        {
            ListNode* nd = arr[x];
            while(nd != NULL)
            {
                vec.push_back(nd->val);
                nd = nd->next;
            }
            x++;
        }

        if(vec.size() == 0)
            return NULL;

        sort(vec.begin(), vec.end());
        ListNode* ans = new ListNode(vec[0]);
        ListNode* temp = ans;
        for(int i = 1; i < vec.size(); i++)
        {
            ListNode* nd = new ListNode(vec[i]);
            temp->next = nd;
            temp = temp->next;
        }
        return ans;    
    }
};