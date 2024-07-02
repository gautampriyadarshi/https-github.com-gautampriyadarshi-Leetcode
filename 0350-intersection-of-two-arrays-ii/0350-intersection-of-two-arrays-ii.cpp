class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_map<int, int> mp1, mp2;

        for(int i = 0; i < nums1.size(); i++)
        {
            mp1[nums1[i]]++;
        }

        for(int i = 0; i < nums2.size(); i++)
        {
            mp2[nums2[i]]++;
        }
        
        for(auto x: mp1)
        {
            for(auto y: mp2)
            {
                if(x.first == y.first)
                {
                    int p = min(x.second, y.second);
                    while(p > 0)
                    {
                        ans.push_back(x.first);
                        p--;
                    }
                }
            }
        }
        return ans;
    }
};