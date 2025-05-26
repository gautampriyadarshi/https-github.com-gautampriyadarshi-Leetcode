class Solution {
    int Rec(int ind, int prev_ind, vector<int>& nums, int n) 
    { 
        if(ind == n) 
            return 0; 

        int len = 0 + Rec(ind+1, prev_ind, nums, n); 

        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) 
            len = max(len, 1 + Rec(ind+1, ind, nums, n)); 
        
        return len; 
    }

    int Mem(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>> &dp) 
    { 
        if(ind == n) 
            return 0; 

        if(dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int len = 0 + Mem(ind+1, prev_ind, nums, n, dp); 

        if (prev_ind == -1 || nums[ind] > nums[prev_ind]) 
            len = max(len, 1 + Mem(ind+1, ind, nums, n, dp)); 
        
        return dp[ind][prev_ind + 1] = len; 
    }

    // In co-ordinate shifting second parameter must be added with (+1).
    int Tab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int len = 0 + dp[ind + 1][prev_ind + 1];

                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                    len = max(len, 1 + dp[ind + 1][ind + 1]);

                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][-1 + 1];
    }

    int spaceOptimization(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
            {
                int len = 0 + next[prev_ind + 1];

                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                    len = max(len, 1 + next[ind + 1]);

                curr[prev_ind + 1] = len;
            }
            next = curr;
        }
        return next[-1 + 1];
    }

    int optimizedTab(vector<int>& nums)
    {
        // For returning the length:
        /*
        int n = nums.size(), maxi = 1;
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++)
        {
            for(int prev = 0; prev < i; prev++)
            {
                if(nums[prev] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;    */

        // For printing:
        int n = nums.size(), maxi = 1, lastIndex = 0;
        vector<int> dp(n, 1), hash(n);

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);

        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());

        for(auto x: temp)
        {
            cout << x << " ";
        }

        return maxi;
    }
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();

        // Recursion:
        // return Rec(0, -1, nums, n);

        // Mempization:
        // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // return Mem(0, -1, nums, n, dp);

        // Tabulation:
        // return Tab(nums);

        // Space Optimization:
        // return spaceOptimization(nums);

        // Optimized: For printing purpose
        return optimizedTab(nums);
    }
};