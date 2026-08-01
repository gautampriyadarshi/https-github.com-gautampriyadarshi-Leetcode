class Solution {
    int Rec(int ind, int buy, vector<int>& prices, int n, int fee) 
    { 
        if(ind == n)
            return 0;
        
        int profit = 0;

        if(buy)
            profit = max(-prices[ind] + Rec(ind+1, 0, prices, n, fee),
                        0 + Rec(ind+1, 1, prices, n, fee));
        else
            profit = max(prices[ind] - fee + Rec(ind+1, 1, prices, n, fee),
                        0 + Rec(ind+1, 0, prices, n, fee));
        
        return profit;
    }

    int Mem(int ind, int buy, vector<int>& prices, int n, int fee, vector<vector<int>> &dp) 
    { 
        if(ind == n) 
            return 0; 

        if(dp[ind][buy] != -1)
            return dp[ind][buy];
        
        int profit = 0; 

        if(buy) 
            profit = max( -prices[ind] + Mem(ind+1, 0, prices, n, fee, dp), 
                        0 + Mem(ind+1, 1, prices, n, fee, dp)); 
        else 
            profit = max(prices[ind] - fee + Mem(ind+1, 1, prices, n, fee, dp), 
                        0 + Mem(ind+1, 0, prices, n, fee, dp)); 

        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();

        // Recursion:
        // return Rec(0, 1, prices, n, fee);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return Mem(0, 1, prices, n, fee, dp);
    }
};