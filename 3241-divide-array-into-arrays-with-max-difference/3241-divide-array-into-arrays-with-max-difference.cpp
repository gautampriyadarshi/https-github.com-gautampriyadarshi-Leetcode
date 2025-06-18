class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for (int i = 0; i <= n-3; i = i+3)
        {
            if (nums[i+2] - nums[i+1] <= k && nums[i+1] - nums[i] <= k && nums[i+2] - nums[i] <= k)
                ans.push_back({nums[i], nums[i+1], nums[i+2]});
            else
                return {};
        }
        return ans;
    }
};