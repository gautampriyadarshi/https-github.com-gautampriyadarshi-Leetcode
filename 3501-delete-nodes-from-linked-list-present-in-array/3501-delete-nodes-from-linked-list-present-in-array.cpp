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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) 
    {
        vector<int> help;
        ListNode* node = head;

        while(node != NULL)
        {
            help.push_back(node->val);
            node = node->next;
        }

        unordered_map<int, bool> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = true;
        }

        for(int i = 0; i < help.size(); i++)
        {
            if(mp[help[i]] == true)
                help[i] = -1;
        }

        int ind = 0;
        for(int i = 0; i < help.size(); i++)
        {
            if(help[i] != -1)
            {
                ind = i;
                break;
            }
        }

        ListNode* ans = new ListNode(help[ind]);
        node = ans;

        for(int i = ind+1; i < help.size(); i++)
        {
            if(help[i] != -1)
            {
                ListNode* hp = new ListNode(help[i]);
                node->next = hp;
                node = node->next;
            }
        }
        return ans;
    }
};