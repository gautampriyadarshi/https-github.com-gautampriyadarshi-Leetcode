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
        int m = 0, n = 0;

        ListNode* n1 = l1;
        while(n1 != NULL)
        {
            m++;
            if(n1->next == NULL)
                break;
            
            n1 = n1->next;
        }

        ListNode* n2 = l2;
        while(n2 != NULL)
        {
            n++;
            if(n2->next == NULL)
                break;

            n2 = n2->next;
        }

        if(m > n)
        {
            while(m > n)
            {
                ListNode* node = new ListNode(0);
                n2->next = node;
                n2 = n2->next;
                n++;
            }
        }
        else if(n > m)
        {
            while(n > m)
            {
                ListNode* node = new ListNode(0);
                n1->next = node;
                n1 = n1->next;
                m++;
            }
        }

        int carry = 0;
        n1 = l1;
        n2 = l2;

        ListNode* node = new ListNode;
        ListNode* an = node;
        int sum = n1->val + n2->val;
        if(sum > 9)
        {
            node->val = (sum % 10);
            carry = 1;
        }
        else
        {
            node->val = sum;
            carry = 0;
        }
        n1 = n1->next;
        n2 = n2->next;
        
        for(int i = 1; i < m; i++)
        {
            int sum = n1->val + n2->val + carry;

            ListNode* nd = new ListNode;
            if(sum > 9)
            {
                nd->val = (sum % 10);
                carry = 1;
            }
            else if(sum <= 9)
            {
                nd->val = sum;
                carry = 0;
            }

            node->next = nd;
            node = nd;

            n1 = n1->next;
            n2 = n2->next;
        }

        if(carry != 0)
        {
            ListNode* nd = new ListNode(1);
            node->next = nd;
        }

        return an;
    }
    /*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        vector<int> vec1, vec2, ans;

        ListNode* n1 = l1;
        while(n1 != NULL)
        {
            vec1.push_back(n1->val);
            n1 = n1->next;
        }

        ListNode* n2 = l2;
        while(n2 != NULL)
        {
            vec2.push_back(n2->val);
            n2 = n2->next;
        }

        int m = vec1.size(), n = vec2.size();
        if(m > n)
        {
            while(m > n)
            {
                vec2.push_back(0);
                n++;
            }
        }
        else if(n > m)
        {
            while(n > m)
            {
                vec1.push_back(0);
                m++;
            }
        }

        int carry = 0;
        for(int i = 0; i < vec1.size(); i++)
        {
            int sum = vec1[i] + vec2[i] + carry;

            if(sum > 9)
            {
                ans.push_back(sum % 10);
                carry = 1;
            }
            else if(sum <= 9)
            {
                ans.push_back(sum);
                carry = 0;
            }
        }

        if(carry != 0)
            ans.push_back(1);
        
        ListNode* node = new ListNode(ans[0]);
        ListNode* an = node;

        for(int i = 1; i < ans.size(); i++)
        {
            ListNode* nd = new ListNode(ans[i]);
            node->next = nd;
            node = nd;
        }
        ans.clear(), vec1.clear(), vec2.clear();
        return an;
    }   */
};