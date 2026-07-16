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
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();

        // Recursion:
        // return Rec(n - 1, amount, coins);

        // Memoization:
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return Mem(n - 1, amount, coins, dp);
    }
};