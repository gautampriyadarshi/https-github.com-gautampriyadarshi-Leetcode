class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]]++;

            if(mp[nums[i]] > n/2)
                return nums[i];
        }
        return 0;
    }
};