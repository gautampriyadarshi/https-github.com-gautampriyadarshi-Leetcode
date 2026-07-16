class Solution {
    long long Rec(int ind, int remainingWall, vector<int> &cost, vector<int> &time)
    {
        if(remainingWall <= 0)
            return 0;
        
        if(ind < 0)
            return INT_MAX;

        long long paid = cost[ind] + Rec(ind-1, remainingWall-1-time[ind], 
                                                cost, time);    // Take
        long long free = 0 + Rec(ind-1, remainingWall, cost, time);     // notTake
        return min(paid, free);
    }

    long long Mem(int ind, int remainingWall, vector<int> &cost, vector<int> &time,
                    vector<vector<int>> &dp)
    {
        if(remainingWall <= 0)
            return 0;
        
        if(ind < 0)
            return INT_MAX;

        if(dp[ind][remainingWall] != -1)
            return dp[ind][remainingWall];

        long long paid = cost[ind] + Mem(ind-1, remainingWall-1-time[ind], 
                                                cost, time, dp);    // Take
        long long free = 0 + Mem(ind-1, remainingWall, cost, time, dp);     // notTake
        return dp[ind][remainingWall] = min(paid, free);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        int n = cost.size();
        
        // Recursion:
        // return Rec(n-1, n, cost, time);
        
        // Memoization:
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return Mem(n-1, n, cost, time, dp);
    }
};

/************* 
// Reason for doing remainingWall-1-time[ind]
1. The - 1 (The Paid Painter's Job)

The paid painter instantly takes responsibility for this specific wall (ind). Because they are going to paint it, your total to-do list of walls decreases by 1.
(This is the remainingWall - 1 part).

2. The - time[ind] (The Free Painter's Bonus)

The problem has a very specific rule: The free painter can paint 1 wall per unit of time, but ONLY while the paid painter is currently working.

Let's say time[ind] = 3.
This means the paid painter is going to be locked in a room painting wall ind for 3 whole days.

Because the paid painter is busy for 3 days, the free painter is "unlocked" for 3 days!
While the paid painter is doing their job on wall ind, the free painter runs around and paints 3 entirely different walls for absolutely zero cost.

So, by paying for this one wall, you didn't just get 1 wall painted. You got the paid painter's wall (1) PLUS the walls the free painter did in the background (3).

Your total to-do list decreases by 4 walls total!   
***********/