class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> help(m, vector<int>(n));

        int row = m-1, col = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                help[i][j] = matrix[row][col];
                row--;
            }
            row = m-1;
            col++;
        }

        matrix = help;
    }
};