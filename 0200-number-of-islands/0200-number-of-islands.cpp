class Solution {
    void bfs(int ro, int co, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[ro][co] = 1;
        queue<pair<int, int>> q;
        q.push({ro, co});

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traversing in the neighbours and pushing them into queue:
            for (int delRow = -1; delRow <= 1; delRow++)
            {
                for (int delCol = -1; delCol <= 1; delCol++)
                {
                    if((delRow == -1 && delCol == 1) || (delRow == 1 && delCol == 1) || (delRow == 1 && delCol == -1) || (delRow == -1 && delCol == -1))
                        continue;

                    int nRow = row + delRow; // nRow = neighbour Row
                    int nCol = col + delCol; // nCol = neighbour Col

                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !vis[nRow][nCol])
                    {
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!vis[row][col] && grid[row][col] == '1')
                {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};