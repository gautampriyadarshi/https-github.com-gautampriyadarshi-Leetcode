class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums;
        
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }
        
        vector<int> ans;
        for(auto x: mp)
        {
            if(x.second > n/3)
                ans.push_back(x.first);
        }
        return ans;
    }
};