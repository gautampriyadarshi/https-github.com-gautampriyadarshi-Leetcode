class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        vector<vector<int>> ans;
        for(int i = 0; i < nums1.size(); i++)
        {
            int idI = nums1[i][0], valI = nums1[i][1];
            for(int j = 0; j < nums2.size(); j++)
            {
                int idJ = nums2[j][0], valJ = nums2[j][1];
                if(idI == idJ)
                {
                    ans.push_back({idI, valI + valJ});
                    nums1[i][0] = -1;
                    nums2[j][0] = -1;
                }
                else
                    continue;
            }
        }

        for(int i = 0; i < nums1.size(); i++)
        {
            if(nums1[i][0] != -1)
                ans.push_back({nums1[i][0], nums1[i][1]});
        }

        for(int i = 0; i < nums2.size(); i++)
        {
            if(nums2[i][0] != -1)
                ans.push_back({nums2[i][0], nums2[i][1]});
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};