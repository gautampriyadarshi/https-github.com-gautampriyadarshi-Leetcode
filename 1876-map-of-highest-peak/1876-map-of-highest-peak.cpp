class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) 
    {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>>dp(n, vector<int>(m, n+m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1) 
                    dp[i][j] = 0;
                else 
                {
                    if (i > 0) 
                        dp[i][j] = min (dp[i][j], dp[i-1][j] + 1); //top

                    if (j > 0) 
                        dp[i][j] = min (dp[i][j], dp[i][j-1] + 1); //left
                }
            }
        }

        //reverse 
        for (int i = n-1; i >= 0; i--)
        {
            for (int j = m-1; j >= 0; j--)
            {
                if (i < n-1) 
                    dp[i][j] = min (dp[i][j], dp[i+1][j] + 1); //bottom

                if (j < m-1) 
                    dp[i][j] = min (dp[i][j], dp[i][j+1] + 1); //right
            }
        }
        return dp;
    }
};