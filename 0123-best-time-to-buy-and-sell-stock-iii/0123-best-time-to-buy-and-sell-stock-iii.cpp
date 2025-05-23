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
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();

        // Recursion:
        // return Rec(0, 1, 2, prices, n);

        // Memoization:
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return Mem(0, 1, 2, prices, n, dp);

    }
};