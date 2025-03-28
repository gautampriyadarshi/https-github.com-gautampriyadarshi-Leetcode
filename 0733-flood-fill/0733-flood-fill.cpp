class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int st = image[sr][sc], n = image.size(), m = image[0].size();
        
        if(image[sr][sc] == color) 
            return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc] = color;

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        while(!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == st)
                {
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};