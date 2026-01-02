class Solution {
    void bfs(int ro, int co, vector<vector<int>> &vis, vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[ro][co] = 1;

        queue<pair<int, int>> q;
        q.push({ro, co});

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
                && grid[nRow][nCol] == '1' && !vis[nRow][nCol])
                {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};

// O(m*n) is for queue and other is for visited array

// SC: O(m*n) + O(m*n)
// TC: O(m*n)