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
    bool isPalindrome(ListNode* head) 
    {
        if(!head->next)
            return true;
        
        vector<int> vec;
        ListNode* curr = head;

        while(curr)
        {
            vec.push_back(curr->val);
            curr = curr->next;
        }

        int k = vec.size()-1;
        for(int i = 0; i < vec.size()/2; i++)
        {
            if(vec[i] != vec[k--])
                return false;
        }
        return true;
    }
};