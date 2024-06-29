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
    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        vector<vector<int>> main;
        vector<int> vec;
        ListNode* node = head;

        while(node != NULL)
        {
            vec.push_back(node->val);
            node = node->next;
        }

        int i = 0, count = 1;
        while(i < vec.size())
        {
            int temp = count;
            vector<int> help;
            while(temp != 0 && i != vec.size())
            {
                temp--;
                help.push_back(vec[i]);
                i++;
            }
            main.push_back(help);
            count++;
        }

        for(int i = 0; i < main.size(); i++)
        {
            if(main[i].size() % 2 == 0)
                reverse(main[i].begin(), main[i].end());
        }
        vec.clear();

        for(int i = 0; i < main.size(); i++)
        {
            for(int j = 0; j < main[i].size(); j++)
            {
                vec.push_back(main[i][j]);
            }
        }
        main.clear();

        int x = 0;
        ListNode* p = head;
        while(p != NULL)
        {
            p->val = vec[x];
            x++;
            p = p->next;
        }
        return head;
    }
};