class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m = heights.size(), n = heights[0].size();
        
        // Min-heap to store {current_max_effort, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
                       
        vector<vector<int>> minEffort(m, vector<int>(n, INT_MAX));
        
        pq.push({0, {0, 0}});
        minEffort[0][0] = 0;
        
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};
        
        while (!pq.empty()) 
        {
            int effort = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            // If we reached the destination, return the effort!
            if (r == m - 1 && c == n - 1) 
                return effort;
            
            // If we've already found a better way to this cell, skip processing
            if (effort > minEffort[r][c]) 
                continue;
            
            for (int i = 0; i < 4; i++) 
            {
                int R = r + dRow[i];
                int C = c + dCol[i];
                
                if (R >= 0 && R < m && C >= 0 && C < n) 
                {
                    int nextEffort = max(effort, abs(heights[r][c] - heights[R][C]));
                    
                    if (nextEffort < minEffort[R][C]) {
                        minEffort[R][C] = nextEffort;
                        pq.push({nextEffort, {R, C}});
                    }
                }
            }
        }
        return 0; 
    }
};