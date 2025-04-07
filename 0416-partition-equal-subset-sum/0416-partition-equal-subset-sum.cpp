#include<bits/stdc++.h>
class Solution {
    /*
    bool solveMem(int index, vector<int> arr, int N, int target, vector<vector<int>> &dp)
    {
        if(index >= N || target < 0)
            return 0;

        if(target == 0)
            return 1;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        bool include = solveMem(index + 1, arr, N, target - arr[index], dp);
        bool exclude = solveMem(index + 1, arr, N, target - 0, dp);
        
        dp[index][target] = include or exclude;
        return dp[index][target];
    }   */

    bool solveTab(int N, vector<int>& arr, int total)
    {
        vector<vector<int>> dp(N+1, vector<int>(total + 1, 0));
        
        for(int i = 0; i <= N; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int index = N-1; index >= 0; index--)
        {
            for(int target = 0; target <= total/2; target++)
            {
                bool include = 0;
                if(target - arr[index] >= 0)
                {
                    include = dp[index+1][target - arr[index]];
                }
                bool exclude = dp[index + 1][target - 0];
        
                dp[index][target] = include or exclude;
            }
        }
        return dp[0][total/2];
    }
public:
    bool canPartition(vector<int>& arr) 
    {
        int N = arr.size(), total = 0;
        for(int i = 0; i < N; i++)
        {
            total += arr[i];
        }
        
        if(total % 2 != 0)
            return 0;
        
        int target = total/2;
        return solveTab(N, arr, total); 
    }
};