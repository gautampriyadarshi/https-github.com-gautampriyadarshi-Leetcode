class Solution {
    int Rec(int ind, int T, vector<int> &a)
    {
        if (ind == 0)
            return (T % a[0] == 0);

        int notTake = Rec(ind - 1, T, a);
        int take = 0;
        if (a[ind] <= T)
            take = Rec(ind, T - a[ind], a);

        return take + notTake;
    }

    int Mem(int ind, int T, vector<int> &a, vector<vector<int>> &dp)
    {
        if (ind == 0)
            return (T % a[0] == 0);

        if (dp[ind][T] != -1)
            return dp[ind][T];

        int notTake = Mem(ind - 1, T, a, dp);
        int take = 0;
        if (a[ind] <= T)
            take = Mem(ind, T - a[ind], a, dp);

        return dp[ind][T] = take + notTake;
    }

    int Tab(vector<int> &a, int n, int amount)
    {
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int T = 0; T <= amount; T++)
        {
            dp[0][T] = (T % a[0] == 0);
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int T = 0; T <= amount; T++)
            {
                int notTake = dp[ind - 1][T];
                int take = 0;
                if (a[ind] <= T)
                    take = dp[ind][T - a[ind]]; 

                dp[ind][T] = take + notTake;
            }
        }
        return dp[n - 1][amount];
    }

    int spaceOptimization(vector<int> &a, int n, int amount)
    {
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
        for (int T = 0; T <= amount; T++)
        {
            prev[T] = (T % a[0] == 0);
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int T = 0; T <= amount; T++)
            {
                int notTake = prev[T];
                int take = 0;
                if (a[ind] <= T)
                    take = curr[T - a[ind]];

                curr[T] = take + notTake; // Giving Run-time error:
            }
            prev = curr;
        }
        return prev[amount];
    }
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();

        // Recursion:
        // return Rec(n - 1, amount, coins);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return Mem(n - 1, amount, coins, dp);

        // Tabulation:
        // return Tab(coins, n, amount);

        // Space Optimization:
        // return spaceOptimization(coins, n, amount);
    }
};