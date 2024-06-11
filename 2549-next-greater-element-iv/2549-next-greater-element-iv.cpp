class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) 
    {
        stack<int> s1, s2, tmp;
        vector<int> ans(nums.size(), -1);

        for(int i = 0; i < nums.size(); i++)
        {
            // Update ans
            while(!s2.empty() && nums[s2.top()] < nums[i])
            {
                ans[s2.top()] = nums[i];
                s2.pop();
            }

            //if find first max go for second so push it to the s2 
            while(!s1.empty() && nums[s1.top()]<nums[i])
            {
                tmp.push(s1.top());
                s1.pop();
            }

            //this while is becoz we want all elm in decresing order
            while(!tmp.empty())
            {
                s2.push(tmp.top());
                tmp.pop();
            }
            s1.push(i);
        }
        return ans;

        // TLE: 45/51 cases passed.
        /* vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
        {
            int ct = 0, x = ans.size();
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[j] > nums[i])
                    ct++;
                
                if(ct == 2)
                {
                    ans.push_back(nums[j]);
                    break;
                }
            }

            if(ans.size() == x)
                ans.push_back(-1);
        }
        return ans; */
    }
};