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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        // TLE:
    /*  vector<int> vec;
        ListNode* node = head;

        while(node != NULL)
        {
            vec.push_back(node->val);
            node = node->next;
        }

        if(vec.size() == 2)
            return {-1, -1};
        
        for(int i = 1; i < vec.size()-1; i++)
        {
            if(vec[i] > vec[i+1] && vec[i] > vec[i-1])
                vec[i] = INT_MAX;
            
            else if(vec[i] < vec[i+1] && vec[i] < vec[i-1])
                vec[i] = INT_MIN;
        }

        int dis_mini = INT_MAX, dis_max = INT_MIN;
        
        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] == INT_MIN || vec[i] == INT_MAX)
            {
                for(int j = i+1; j < vec.size(); j++)
                {
                    if(vec[j] == INT_MIN || vec[j] == INT_MAX)
                    {
                        dis_mini = min(dis_mini, j-i);
                        dis_max  = max(dis_max, j-i);

                        //cout << j-i << " ";
                    }
                }
            }
        }   

        if(dis_mini == INT_MAX)
            dis_mini = -1;
        
        if(dis_max == INT_MIN)
            dis_max = -1;

        return {dis_mini, dis_max}; */

        vector<int>v,arr;          
        ListNode*temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);      // convert list to a vector
            temp=temp->next;
        }
        int mini=INT_MAX,maxi=-1;
        if(v.size()<4) return {-1,-1};   // if vector size if <4 then mini maxi not possible
        for(int i=1;i<v.size()-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){            // find local max and psh index in arr
                arr.push_back(i);
            }
            if(v[i]<v[i-1] && v[i]<v[i+1]){
                arr.push_back(i);             // find local min and push it to arr
            }
        }
        if(arr.size()<2) return {-1,-1};      // if size less than 2 so dist cant be calc 

        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            mini=min(mini,abs(arr[i]-arr[i+1]));        // to find min distance
        }
        maxi=abs(arr[0]-arr[arr.size()-1]);             // find max dist
        return {mini,maxi};
    }
};