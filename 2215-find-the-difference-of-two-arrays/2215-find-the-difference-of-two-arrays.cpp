class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> help;
        vector<vector<int>> ans;
        unordered_map<int, bool> mp, self;

        for(int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i]] = true;
        }

        for(auto x: nums1)
        {
            if(!mp[x] && !self[x])
            {
                help.push_back(x);
                self[x] = true;
            } 
        }

        ans.push_back(help);
        help.clear();
        mp.clear();
        self.clear();

        for(int i = 0; i < nums1.size(); i++)
        {
            mp[nums1[i]] = true;
        }

        for(auto x: nums2)
        {
            if(!mp[x] && !self[x])
            {
                help.push_back(x);
                self[x] = true;
            }
        }

        ans.push_back(help);
        help.clear();
        self.clear();
        
        return ans;
    }
};