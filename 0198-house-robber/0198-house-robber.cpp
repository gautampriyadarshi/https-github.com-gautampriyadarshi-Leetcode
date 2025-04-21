class Solution {
    int Rec(int ind, vector<int> &nums)
    {
        if (ind == 0)
            return nums[ind]; // ind is 0 means ind+1 was not picked and ind+2 was picked.

        if (ind < 0)
            return 0;

        // Adjacent elements need to be skipped thats's why we did (ind - 2);
        int pick = nums[ind] + Rec(ind - 2, nums);
        int notPick = 0 + Rec(ind - 1, nums);

        return max(pick, notPick);
    }

    int Mem(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind == 0)
            return nums[ind];

        if (ind < 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + Mem(ind - 2, nums, dp);
        int notPick = 0 + Mem(ind - 1, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

    int Tab(int n, vector<int> &nums)
    {
        vector<int> dp(n);
        dp[0] = nums[0];
        int neg = 0;

        for (int i = 1; i < n; i++)
        {
            int take = nums[i];

            if (i > 1)
                take += dp[i - 2];

            int notTake = 0 + dp[i - 1];

            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }

public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        // Recursion:
        // return Rec(n - 1, nums);

        // Memoization:
        // vector<int> dp(n, -1);
        // return Mem(n - 1, nums, dp);

        // Tabulation:
        // return Tab(n, nums);

        // Space Optimization:
        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];

            if (i > 1)
                take += prev2;

            int notTake = 0 + prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};