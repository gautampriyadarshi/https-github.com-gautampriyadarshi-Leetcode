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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> ans(k);
        int size = 0;
        ListNode* current = head;

        while (current != NULL) 
        {
            size++;
            current = current->next;
        }

        int split = size / k;
        int Remaining = size % k;

        current = head;
        ListNode* prev = current;

        for (int i = 0; i < k; i++) 
        {
            ListNode* newPart = current;
            int currentSize = split;

            if (Remaining > 0) 
            {
                Remaining--;
                currentSize++;
            }

            int j = 0;
            while (j < currentSize) 
            {
                prev = current;
                if (current != NULL) 
                    current = current->next;

                j++;
            }

            if (prev != NULL) 
                prev->next = NULL;

            ans[i] = newPart;
        }
        return ans;
    }
};