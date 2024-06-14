class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) 
    {
        // TLE: 523/536 cases passed:
        /*  int n = queries.size();
        vector<bool> ans;
        int i = 0;
        while(i < queries.size())
        {
            bool written = false;
            int m = ans.size();
            int x = queries[i][0], y = queries[i][1];
            for(int j = x; j < y; j++)
            {
                if((nums[j] % 2 == 0 && nums[j+1] % 2 == 0) || (nums[j] % 2 != 0 && nums[j+1] % 2 != 0))
                {
                    if(written == false)
                    {
                        ans.push_back(0);
                        written = true;
                    }
                }
            }
            
            if(ans.size() == m)
                ans.push_back(1);
            
            i++;
        }
        return ans; */

        int n = nums.size();
        vector<int> arr(n, n);
        vector<bool> ans;

        for(int i = n-2; i >= 0; i--)
        {
            if((nums[i] + nums[i+1]) & 1) 
                arr[i] = arr[i+1];
            else 
                arr[i] = i;
        }
        
        for(auto it : queries)
        {
            if(arr[it[0]] < it[1]) 
                ans.push_back(false);
            else 
                ans.push_back(true);
        }

        return ans;
    }
};