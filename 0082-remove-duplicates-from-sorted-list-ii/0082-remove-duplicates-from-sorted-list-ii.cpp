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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        vector<int> vec, list;
        unordered_map<int, int> mp;
        ListNode* node = head;

        while(node != NULL)
        {
            vec.push_back(node->val);
            node = node->next;
        }

        for(int i = 0; i < vec.size(); i++)
        {
            mp[vec[i]]++;
        }

        for(int i = 0; i < vec.size(); i++)
        {
            if(mp[vec[i]] == 1)
                list.push_back(vec[i]);
        }
        vec.clear();
        mp.clear();

        if(list.size() == 0)
            return NULL;

        ListNode* ans = new ListNode(list[0]);
        ListNode* root = ans;
        for(int i = 1; i < list.size(); i++)
        {
            ListNode* nn = new ListNode(list[i]);
            root->next = nn;
            root = root->next;
        }
        list.clear();
        return ans;
    }
};