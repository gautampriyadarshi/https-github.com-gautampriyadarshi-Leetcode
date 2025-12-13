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
        if(head->next == NULL)
            return true;
        
        stack<int> st;
        ListNode* node = head;

        while(node != NULL)
        {
            st.push(node->val);
            node = node->next;
        }

        node = head;
        while(node)
        {
            if(node->val != st.top())
                return false;
            
            st.pop();
            node = node->next;
        }
        return true;
    }
};