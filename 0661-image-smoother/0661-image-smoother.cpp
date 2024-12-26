class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int rows = img.size();
        int cols = img[0].size();

        vector<vector<int>> smoothImage(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                int sum = 0, count = 0;
                
                for (int x = i - 1; x <= i + 1; x++) 
                {
                    for (int y = j - 1; y <= j + 1; y++) 
                    {
                        if (0 <= x && x < rows && 0 <= y && y < cols) 
                        {
                            sum += img[x][y];
                            count += 1;
                        }
                    }
                }
                smoothImage[i][j] = sum / count;
            }
        }
        return smoothImage;
    }
};