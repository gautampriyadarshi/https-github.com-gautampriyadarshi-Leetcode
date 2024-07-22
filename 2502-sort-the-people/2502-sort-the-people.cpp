class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<pair<int, string>> help;
        for(int i = 0; i < heights.size(); i++)
        {
            help.push_back({heights[i], names[i]});
        }

        sort(help.begin(), help.end());
        vector<string> ans;
        for(int i = names.size()-1; i >= 0; i--)
        {
            ans.push_back(help[i].second);
        }
        return ans;
    }
};