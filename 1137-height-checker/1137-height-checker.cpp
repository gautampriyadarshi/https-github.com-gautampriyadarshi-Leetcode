class Solution {
public:
    int heightChecker(vector<int>& heights) 
    {
        vector<int> help = heights;
        sort(help.begin(), help.end());
        int count = 0, j = 0;

        for(int i = 0; i < heights.size(); i++)
        {
            if(heights[i] != help[j])
                count++;
            
            j++;
        }
        return count;
    }
};