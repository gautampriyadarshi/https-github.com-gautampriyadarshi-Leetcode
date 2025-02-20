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
        if (!head || !head->next) return true;

        // Find the middle of the list
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        ListNode *prev = nullptr, *curr = slow, *temp;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Compare the two halves
        ListNode *first = head, *second = prev;
        while (second) {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;
    }
};