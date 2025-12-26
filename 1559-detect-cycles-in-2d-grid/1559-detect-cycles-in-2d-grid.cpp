class Solution {
    bool bfs(int row, int col, int pRow, int pCol, vector<vector<int>> &vis, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};

        queue<pair<pair<int, int>, pair<int, int>>> q;  // queue<pair<child, parent>> q;
        q.push({{row, col}, {pRow, pCol}});

        while(!q.empty())
        {
            auto [curR, curC] = q.front().first;
            auto [parR, parC] = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nRow = dRow[i] + curR;  // curR not row
                int nCol = dCol[i] + curC;  // curC not col

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                && grid[nRow][nCol] == grid[row][col])
                {
                    if(vis[nRow][nCol] == 0)
                    {
                        vis[nRow][nCol] = 1;
                        q.push({{nRow, nCol}, {curR, curC}});
                    }
                    else if(nRow != parR && nCol != parC)
                        return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j])
                { 
                    vis[i][j] = 1;
                    if(bfs(i, j, -1, -1, vis, grid))
                        return true;
                }
            }
        }
        return false;
    }
};

// SC: O(n*m)
// TC: O(n*m)