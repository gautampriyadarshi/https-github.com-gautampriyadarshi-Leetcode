class Solution {
    int solveMem(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if(i <= 0 || j <= 0)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = solveMem(i-1, j, m, n, dp) + solveMem(i, j-1, m, n, dp);

    }
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solveMem(m-1, n-1, m, n,  dp);
    }
};