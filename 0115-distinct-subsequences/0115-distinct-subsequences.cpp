class Solution {
    int Rec(int i, int j, string s, string t) 
    { 
        if(j < 0) 
            return 1; 

        if(i < 0) 
            return 0; 

        if(s[i] == t[j]) 
            return Rec(i-1, j-1, s, t) + Rec(i-1, j, s, t); 
        
        return Rec(i-1, j, s, t); 
    }

    int Mem(int i, int j, string &s, string &t, vector<vector<int>> &dp) 
    { 
        if(j < 0) 
            return 1; 

        if(i < 0) 
            return 0; 
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j]) 
            return dp[i][j] = Mem(i-1, j-1, s, t, dp) + Mem(i-1, j, s, t, dp); 
        
        return dp[i][j] = Mem(i-1, j, s, t, dp); 
    }

    int Tab(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));

        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 
                else
                    dp[i][j] = dp[i-1][j]; 
            }
        }
        return (int)dp[n][m];
    }

    int spaceOptimization(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<double> prev(m+1, 0), curr(m+1, 0);
        prev[0] = curr[0] = 1;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1]) 
                    curr[j] = prev[j-1] + prev[j]; 
                else
                    curr[j] = prev[j]; 
            }
            prev = curr;
        }
        return (int)prev[m];
    }
public:
    int numDistinct(string s, string t) 
    {
        int n = s.size(), m = t.size();

        // Recursion:
        // return Rec(n-1, m-1, s, t);

        // Memoization:
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return Mem(n-1, m-1, s, t, dp);

        // Tabulation:
        // return Tab(s, t);

        // Space Optimization:
        return spaceOptimization(s, t);
    }
};