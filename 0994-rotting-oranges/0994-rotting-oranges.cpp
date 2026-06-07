// SC - O(n*m)
// TC - O(n*m) + O(4*n*m) = O(n*m)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        // {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)    // Rotten Orange found
                {
                    q.push({{i, j}, 0});    // All rotten orange will be pushed
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;
        int dRow[] = {-1, 0, +1, 0};
        int dCol[] = {0, +1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = max(tm, t);

            for (int i = 0; i < 4; i++)
            {
                int nRow = r + dRow[i]; // Travelling neighbouring row
                int nCol = c + dCol[i]; // Travelling neighbouring col

                if (nRow >= 0 && nRow < n 
                    && nCol >= 0 && nCol < m 
                    && vis[nRow][nCol] != 2 && grid[nRow][nCol] == 1)   
                    // Orange should be fresh i.e. '1'
                {
                    q.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Not visited and fresh
                if (vis[i][j] != 2 && grid[i][j] == 1)  
                    return -1;
            }
        }
        return tm;
    }
};