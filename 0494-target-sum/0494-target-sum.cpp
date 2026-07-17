class Solution {
    int Rec(int ind, int sum, vector<int> &num)
    {
        if (ind == 0)
        {
            if (sum == 0 && num[0] == 0)
                return 2;

            if (sum == 0 || num[0] == sum)
                return 1;

            return 0;
        }

        int notTake = Rec(ind - 1, sum, num);
        int take = 0;

        if (num[ind] <= sum)
            take = Rec(ind - 1, sum - num[ind], num);
        
        return (take + notTake);
    }

    int Mem(int ind, int sum, vector<int> &num, vector<vector<int>> &dp)
    {
        // Base case modified from dp17, to handle if (num[ind] == 0) else everything is same.
        if (ind == 0)
        {
            if (sum == 0 && num[0] == 0)
                return 2;   // (include + exclude)

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

    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();

        // Recursion:
        // return Rec(n-1, tar, num);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
        return Mem(n - 1, tar, num, dp);
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