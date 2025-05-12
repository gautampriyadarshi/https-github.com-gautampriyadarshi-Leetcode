class Solution {
    int Mem(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
    {
        // Base case modified from dp17, to handle if (num[ind] == 0) else everything is same.
        if (ind == 0)
        {
            if (sum == 0 && num[0] == 0)
                return 2;

            if (sum == 0 || num[0] == sum)
                return 1;

            return 0;
        }

        if (dp[ind][sum] != -1)
            return dp[ind][sum];

        int notTake = Mem(ind - 1, sum, num, dp);
        int take = 0;

        if (num[ind] <= sum)
            take = Mem(ind - 1, sum - num[ind], num, dp);

        return dp[ind][sum] = (notTake + take);
    }

    int Tab(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

        if (num[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (num[0] != 0 && num[0] <= tar)
            dp[0][num[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= tar; sum++)
            {
                int notTake = dp[i - 1][sum];
                int take = 0;

                if (num[i] <= sum)
                    take = dp[i - 1][sum - num[i]];

                dp[i][sum] = (notTake + take);
            }
        }
        return dp[n - 1][tar];
    }

    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        // return Mem(n - 1, tar, num, dp);

        // Tabulation:
        // return Tab(num, tar);

        // Space Optimization:
        vector<int> prev(tar + 1, 0), curr(tar + 1, 0);

        if (num[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;

        if (num[0] != 0 && num[0] <= tar)
            prev[num[0]] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int sum = 0; sum <= tar; sum++)
            {
                int notTake = prev[sum];
                int take = 0;

                if (num[i] <= sum)
                    take = prev[sum - num[i]];

                curr[sum] = notTake + take;
            }
            prev = curr;
        }
        return prev[tar];
    }

    int countPartition(int n, int d, vector<int> &arr)
    {
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            totalSum += arr[i];
        }

        if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
            return 0;

        return findWays(arr, (totalSum - d) / 2);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        // Similar to partition array into two subset with given difference.
        int n = nums.size();
        return countPartition(n, target, nums);
    }
};