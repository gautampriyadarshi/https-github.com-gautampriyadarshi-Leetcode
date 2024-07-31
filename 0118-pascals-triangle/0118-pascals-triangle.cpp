class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if(numRows == 1)
            return {{1}};

        vector<vector<int>> dp(numRows, vector<int>(numRows, 0));
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numRows; j++)
            {
                if(j == 0)
                    dp[i][j] = 1;
                
                if(i == j)
                    dp[i][j] = 1;
            }
        }

        if(numRows == 2)
            return {{1}, {1,1}};

        for(int i = 2; i < numRows; i++)
        {
            for(int j = 1; j < numRows; j++)
            {
                if(i != j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i < dp.size(); i++)
        {
            vector<int> help;
            for(int j = 0; j < dp[0].size(); j++)
            {
                if(dp[i][j] != 0)
                    help.push_back(dp[i][j]);
            }
            ans.push_back(help);
            help.clear();
        }
        dp.clear();
        
        return ans;
    }
};