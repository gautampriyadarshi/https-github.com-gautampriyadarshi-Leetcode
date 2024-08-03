class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < groupSizes.size(); i++)
        {
            mp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for(auto x: mp)
        {
            if(x.second.size() == x.first)
                ans.push_back(x.second);
            else if(x.second.size() > x.first)
            {
                int m = x.first;
                cout << m << " ";
                int count = 0;
                vector<int> help;
                for(int i = 0; i < x.second.size(); i++)
                {
                    count++;
                    help.push_back(x.second[i]);
                    if(count == m)
                    {
                        ans.push_back(help);
                        count = 0;
                        help.clear();
                    }   
                }
            }
        }
        return ans;
    }
};