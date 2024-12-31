class Solution {    
int solveTab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for(int k = n - 1; k >= 0; k--)
    {
        // 1 Day pass:
        int option1 = cost[0] + dp[k + 1];

        // 7 Days pass:
        int i;  // i is 7 din k baad wala index.
        for(i = k; i < n && days[i] < days[k] + 7; i++);
        int option2 = cost[1] + dp[i];

        // 30 Days pass:
        for(i = k; i < n && days[i] < days[k] + 30; i++);
        int option3 = cost[2] + dp[i];
        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        //return solveRec(n, days, cost, 0);
        return solveTab(n, days, cost);
    }
};