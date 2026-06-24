// TC: O(n*n)
// SC: O(n*n)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        dist[0][0] = 1;
        q.push({1, {0,0}});     // {dis, {row, col}}

        int dRow[] = {-1, -1, 0, +1, +1, +1, 0, -1};
        int dCol[] = {0, +1, +1, +1, 0, -1, -1, -1};

        while(!q.empty())
        {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            for(int i = 0; i < 8; i++)
            {
                int R = r + dRow[i];
                int C = c + dCol[i];

                if(R >= 0 && R < n && C >= 0 && C < n && 
                grid[R][C] == 0 && d + 1< dist[R][C])
                {
                    dist[R][C] = d+1;
                    q.push({d+1, {R, C}});
                }
            }
        }

        if(dist[n-1][n-1] == INT_MAX)
            return -1;
        
        return dist[n-1][n-1];
    }
};