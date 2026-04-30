class Solution {
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int orgColor)
    {
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() 
        || image[i][j] != orgColor || image[i][j] == newColor) 
            return; 

        image[i][j] = newColor; // On reaching to a cell giving it required color
        
        dfs(image, i-1, j, newColor, orgColor); // up:    {row-1, col}
        dfs(image, i, j+1, newColor, orgColor); // right: {row, col+1}
        dfs(image, i+1, j, newColor, orgColor); // down:  {row+1, col}
        dfs(image, i, j-1, newColor, orgColor); // left:  {row, col-1}
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int color) 
    {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};