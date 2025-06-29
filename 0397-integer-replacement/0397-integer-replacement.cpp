#include<bits/stdc++.h>
class Solution {
public:
    int solve(int n, unordered_map<long long, int> &dp)
    {
        if(n == 1)
            return 0;

        if(dp[n] != 0)
            return dp[n];

        if(n % 2 == 0)
            dp[n] = solve(n/2, dp) + 1;
        else
            dp[n] = min(solve(n-1, dp), solve(n+1, dp)) + 1;

        return dp[n];
    }

    int integerReplacement(int n) 
    {
        unordered_map<long long, int> dp;
        if(n == INT_MAX)
            return 32;

        long long int ans = solve(n, dp);
        return ans;
    }
};