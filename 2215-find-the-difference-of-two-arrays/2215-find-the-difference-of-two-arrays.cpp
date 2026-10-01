class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<int> onlyInNums1, onlyInNums2;

        for (int x : s1) 
        {
            if (s2.find(x) == s2.end()) 
                onlyInNums1.push_back(x);
        }

        for (int x : s2) 
        {
            if (s1.find(x) == s1.end()) 
                onlyInNums2.push_back(x);
        }

        return {onlyInNums1, onlyInNums2};
    }
};

//////// Below code I wrote but then optimized the code, above one is optimized

/*****            
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
};          ******/