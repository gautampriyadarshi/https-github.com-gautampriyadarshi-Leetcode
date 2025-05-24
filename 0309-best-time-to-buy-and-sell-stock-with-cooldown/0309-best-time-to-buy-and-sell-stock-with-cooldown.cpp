class Solution {
    int Rec(int ind, int buy, vector<int> &prices, int n)
    {
        if (ind >= n)
            return 0;

        int profit = 0;

        if (buy)
            profit = max(-prices[ind] + Rec(ind + 1, 0, prices, n),
                        0 + Rec(ind + 1, 1, prices, n));
        else
            profit = max(prices[ind] + Rec(ind + 2, 1, prices, n),
                        0 + Rec(ind + 1, 0, prices, n));

        return profit;
    }

    int Mem(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp)
    {
        if (ind >= n)
            return 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        int profit = 0;

        if (buy)
            profit = max(-prices[ind] + Mem(ind + 1, 0, prices, n, dp),
                        0 + Mem(ind + 1, 1, prices, n, dp));
        else
            profit = max(prices[ind] + Mem(ind + 2, 1, prices, n, dp),
                        0 + Mem(ind + 1, 0, prices, n, dp));

        return dp[ind][buy] = profit;
    }

    int Tab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                    profit = max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                else
                    profit = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);

                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();

        // Recursion:
        // return Rec(0, 1, prices, n);

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return Mem(0, 1, prices, n, dp);

        // Tabulation:
        return Tab(prices);
    }
};