class Solution {
    void change(vector<vector<int>>& vec, int row, int col)
    {
        int i = 0, j = 0;
        while(j < vec[0].size())
        {
            vec[row][j] = 0;
            j++;
        }

        while(i < vec.size())
        {
            vec[i][col] = 0;
            i++;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> vec(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                    change(vec, i, j);
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vec[i][j] == -1)
                    vec[i][j] = matrix[i][j];
            }
        }

        matrix = vec;
    }
};