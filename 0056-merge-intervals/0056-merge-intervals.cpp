class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        // vector<int> help = intervals[0];
        int x1 = intervals[0][0], y1 = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i)
        {
            // vector<int> vec = intervals[i];  // {x, y}
            int x2 = intervals[i][0], y2 = intervals[i][1];

            if(y1 >= x2) {
                y1 = max(y1, y2);
            }
            else {
                ans.push_back({x1, y1});
                x1 = x2;
                y1 = y2;
                // help = {x2, y2};
                // vec.clear();
            }
        }

        ans.push_back({x1, y1});
        // help.clear();

        return ans;
    }
};
// In new change optimized the space and now not using two extra vectors of N space.