class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> ans(row, vector<int>(col));

        // Across Rows:
        for(int i = 0; i < row-1; i++)
        {
            vector<int> temp;
            for(int k = i, j = 0; k < row && j < col; )
            {
                temp.push_back(mat[k++][j++]);
            }

            sort(temp.begin(), temp.end());
            int p = 0;

            for(int k = i, j = 0; k < row && j < col; )
            {
                mat[k++][j++] = temp[p++];
            }
        }

        // Across Col:
        for(int j = 0; j < col-1; j++)
        {
            vector<int> temp;
            for(int k = j, i = 0; i < row && k < col; )
            {
                temp.push_back(mat[i++][k++]);
            }

            sort(temp.begin(), temp.end());
            int p = 0;

            for(int k = j, i = 0; i < row && k < col; )
            {
                mat[i++][k++] = temp[p++];
            }
        }
        return mat;
    }
};