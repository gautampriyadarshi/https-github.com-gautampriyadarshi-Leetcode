class Solution {
    int Rec(int ind, int buy, int cap, vector<int>& prices, int n) 
    { 
        if(cap == 0 || ind == n)
            return 0;

        int profit = 0; 
        if(buy) 
            profit = max(-prices[ind] + Rec(ind+1, 0, cap, prices, n), 
                        0 + Rec(ind+1, 1, cap, prices, n)); 
        else 
            profit = max(prices[ind] + Rec(ind+1, 1, cap-1, prices, n), 
                        0 + Rec(ind+1, 0, cap, prices, n)); 

        return profit;
    }

    int Mem(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>> &dp) 
    { 
        if(cap == 0 || ind == n)
            return 0;

        if(dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        
        int profit = 0; 

        if(buy) 
            profit = max(-prices[ind] + Mem(ind+1, 0, cap, prices, n, dp), 
                        0 + Mem(ind+1, 1, cap, prices, n, dp)); 
        else 
            profit = max(prices[ind] + Mem(ind+1, 1, cap-1, prices, n, dp), 
                        0 + Mem(ind+1, 0, cap, prices, n, dp)); 

        return dp[ind][buy][cap] = profit;
    }

    int Tab(int k, vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        // Base cases done as all values are 0 initially.

        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap <= k; cap++)
                {
                    int profit = 0; 

                    if(buy) 
                        profit = max(-prices[ind] + dp[ind+1][0][cap], 
                                    0 + dp[ind+1][1][cap]); 
                    else 
                        profit = max(prices[ind] + dp[ind+1][1][cap-1], 
                                    0 + dp[ind+1][0][cap]); 

                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }

    int spaceOptimization(int k, vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        // Base cases done as all values are 0 initially.

        for(int ind = n-1; ind >= 0; ind--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap <= k; cap++)
                {
                    int profit = 0; 

                    if(buy) 
                        profit = max(-prices[ind] + after[0][cap], 0 + after[1][cap]); 
                    else 
                        profit = max(prices[ind] + after[1][cap-1], 0 + after[0][cap]); 

                    curr[buy][cap] = profit;
                }
            }
            after = curr;
        }
        return after[1][k];
    }
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();

        // Recursion:
        // return Rec(0, 1, k, prices, n);

        // Memoization:
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return Mem(0, 1, k, prices, n, dp);

        // Tabulation:
        // return Tab(k, prices);

        // Space Optimization:
        return spaceOptimization(k, prices);
    }
};