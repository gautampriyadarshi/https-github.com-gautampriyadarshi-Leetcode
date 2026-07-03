class Solution {
    int Rec(int i, int j)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;
        
        int left = Rec(i, j-1);
        int up = Rec(i-1, j);

        return left + up;
    }

    int Mem(int i, int j, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int left = Mem(i, j-1, dp);
        int up = Mem(i-1, j, dp);

        return dp[i][j] = left + up;
    }
public:
    int uniquePaths(int m, int n) 
    {
        // Recursion:
        // return Rec(m-1, n-1);

        // Memoization:
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return Mem(m-1, n-1, dp);
    }
};