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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {   
        if(!l1 && !l2)
            return NULL;
        
        if(l1 && !l2)
            return l1;

        if(!l1 && l2)
            return l2;

        vector<int> vec, num1, num2;
        ListNode* curr = l1;

        while(curr != NULL)
        {
            num1.push_back(curr->val);
            curr = curr->next;
        }

        curr = l2;
        while(curr != NULL)
        {
            num2.push_back(curr->val);
            curr = curr->next;
        }

        int m = num1.size(), n = num2.size();

        if(m != n)
        {
            while(m > n)
            {
                num2.push_back(0);
                n++;
            }

            while(m < n)
            {
                num1.push_back(0);
                m++;
            }
        }

        int j = 0, carry = 0;
        for(int i = 0; i < num1.size(); i++)
        {
            int sum = num1[i] + num2[j] + carry;

            if(sum <= 9)
            {
                vec.push_back(sum);
                carry = 0;
            }
            else
            {
                vec.push_back(sum % 10);
                carry = 1;
            }

            j++;
        }

        if(carry != 0)
            vec.push_back(1);

        ListNode* node = new ListNode(vec[0]);
        curr = node;

        for(int i = 1; i < vec.size(); i++)
        {
            ListNode* nd = new ListNode(vec[i]);
            curr->next = nd;
            curr = nd;
        }
        
        vec.shrink_to_fit();
        num1.shrink_to_fit();
        num2.shrink_to_fit();

        return node;
    }
};