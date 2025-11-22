class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        vector<int> help = intervals[0];
        for(int i = 1; i < intervals.size(); ++i)
        {
            vector<int> vec = intervals[i];

            if(help[1] >= vec[0]) {
                help[1] = max(help[1], vec[1]);
            }
            else {
                ans.push_back(help);
                help = vec;
                vec.clear();
            }
        }

        ans.push_back(help);
        help.clear();

        return ans;
    }
};