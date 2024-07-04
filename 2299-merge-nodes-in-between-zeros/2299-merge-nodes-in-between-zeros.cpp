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
    ListNode* mergeNodes(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return NULL;

        vector<int> vec;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int sum=0;
        while(curr != NULL)
        {
            if(curr->val ==0)
            {
                prev = curr;
                curr = curr->next;
                vec.push_back(sum);
                sum=0;
            }

            if(curr!=NULL)
            {
                sum += curr->val;
                curr = curr->next;
            }
        }

        ListNode* temp = new ListNode(vec[0]);
        ListNode* extra = temp;
        for(int i=1; i<vec.size(); i++)
        {
            extra->next = new ListNode(vec[i]);
            extra = extra->next;
        }
        return temp;  
    }
};