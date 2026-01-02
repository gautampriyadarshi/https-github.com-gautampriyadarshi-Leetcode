class Solution {
    int bfs(int ro, int co, vector<vector<int>> &vis, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        vis[ro][co] = 1;

        queue<pair<int, int>> q;
        q.push({ro, co});
        area++;

        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nRow = dRow[i] + row;
                int nCol = dCol[i] + col;

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m 
                && grid[nRow][nCol] == 1 && !vis[nRow][nCol])
                {
                    
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                    area++;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    int x = bfs(i, j, vis, grid);
                    maxArea = max(maxArea, x);
                }
            }
        }
        return maxArea;
    }
};