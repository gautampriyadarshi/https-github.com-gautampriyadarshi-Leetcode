class Solution {
public:
    long long countBadPairs(vector<int>& nums) 
    {
        // 56/65 cases passed with O(n^2).
        unordered_map<int, int> mp;
        long long count = 0, diff = 0, n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            diff = nums[i] - i;
            if(mp[diff] != 0)
                count += mp[diff];
            
            mp[diff]++;
        }

        diff = (long long)(n) * (long long)(n-1)/2;
        return diff - count;
    }
};