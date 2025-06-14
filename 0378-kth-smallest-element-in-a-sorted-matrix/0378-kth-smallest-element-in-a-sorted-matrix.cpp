class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        vector<int> help;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                help.push_back(matrix[i][j]);
            }
        }
        
        sort(help.begin(), help.end());
        return help[k-1];
    }
};