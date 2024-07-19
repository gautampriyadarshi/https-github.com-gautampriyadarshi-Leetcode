class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        // Row:
        vector<int> help1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                mini = min(mini, matrix[i][j]);
            }
            help1.push_back(mini);
            mini = INT_MAX;
        }

        // Column:
        vector<int> help2;
        for(int j = 0; j < n; j++)
        {
            for(int i = 0; i < m; i++)
            {
                maxi = max(maxi, matrix[i][j]);
            }
            help2.push_back(maxi);
            maxi = INT_MIN;
        }

        vector<int> ans;
        for(int i = 0; i < help2.size(); i++)
        {
            for(int j = 0; j < help1.size(); j++)
            {
                if(help1[j] == help2[i])
                    ans.push_back(help1[j]);
            }
        }
        return ans;
    }
};