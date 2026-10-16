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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head || !head->next) 
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Anchor to attach at the end of the odd list

        while (even != NULL && even->next != NULL) 
        {
            // Link odd to the next odd node (skipping even)
            odd->next = even->next;
            odd = odd->next;

            // Link even to the next even node (skipping odd)
            even->next = odd->next;
            even = even->next;
        }

        // Attach the head of the even list to the tail of the odd list
        odd->next = evenHead;

        return head;
    }
};