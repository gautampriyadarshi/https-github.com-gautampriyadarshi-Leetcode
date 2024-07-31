class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        if(rowIndex == 0)
            return {1};

        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, 0));
        for(int i = 0; i < dp.size(); i++)
        {
            for(int j = 0; j < dp.size(); j++)
            {
                if(j == 0)
                    dp[i][j] = 1;
                
                if(i == j)
                    dp[i][j] = 1;
            }
        }

        if(rowIndex == 1)
            return {1,1};

        for(int i = 2; i < dp.size(); i++)
        {
            for(int j = 1; j < dp.size(); j++)
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
        
        return ans[rowIndex];
    }
};