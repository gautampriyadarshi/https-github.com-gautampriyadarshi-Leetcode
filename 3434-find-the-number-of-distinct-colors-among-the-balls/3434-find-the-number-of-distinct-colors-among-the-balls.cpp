class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        int distinctColors = 0;
        unordered_map<int, int> ballColor, colorFreq;
        vector<int> ans;

        for(auto i : queries)
        {
            int ball = i[0], color = i[1];

            // check if the ball is already colored
            auto& prevColor = ballColor[ball];
            if(prevColor)
            {
                if(--colorFreq[prevColor] == 0) 
                    --distinctColors;
            }

            // mark the ball with the curr color
            prevColor = color;
            if(++colorFreq[color] == 1) 
                ++distinctColors;

            ans.push_back(distinctColors);
        }   
        return ans;
    }
};