class Solution {
    int Rec(int ind, int T, vector<int> &nums)
    {
        if (ind == 0)
        {
            if (T % nums[0] == 0)
                return T / nums[0];

            return 1e9;
        }

        int notTake = 0 + Rec(ind - 1, T, nums);
        int take = INT_MAX;

        if (nums[ind] <= T)
            take = 1 + Rec(ind, T - nums[ind], nums);

        return min(take, notTake);
    }

    int Mem(int ind, int T, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (T % nums[0] == 0)
                return T / nums[0];

            return 1e9;
        }

        if (dp[ind][T] != -1)
            return dp[ind][T];

        int notTake = 0 + Mem(ind - 1, T, nums, dp);
        int take = INT_MAX;

        if (nums[ind] <= T)
            take = 1 + Mem(ind, T - nums[ind], nums, dp);

        return dp[ind][T] = min(take, notTake);
    }

    int Tab(vector<int> &num, int target)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int T = 0; T <= target; T++)
        {
            if (T % num[0] == 0)
                dp[0][T] = T / num[0];
            else
                dp[0][T] = 1e9;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int T = 0; T <= target; T++)
            {
                int notTake = 0 + dp[ind - 1][T];
                int take = INT_MAX;

                if (num[ind] <= T)
                    take = 1 + dp[ind][T - num[ind]];

                dp[ind][T] = min(take, notTake);
            }
        }

        int ans = dp[n - 1][target];

        if (ans >= 1e9)
            return -1;

        return ans;
    }
public:
    int coinChange(vector<int>& num, int target) 
    {
        int n = num.size();

        // Recusion:
        // int ans = Rec(n - 1, target, num);

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // int ans = Mem(n - 1, target, num, dp);

        // Tabulation:
        int ans = Tab(num, target);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};