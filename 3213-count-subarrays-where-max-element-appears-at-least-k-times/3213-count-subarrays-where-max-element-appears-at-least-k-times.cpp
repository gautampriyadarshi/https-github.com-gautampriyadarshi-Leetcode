class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        if(k > nums.size())
            return 0;

        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
        }

        int i = 0, j = 0;
        long long ans = 0;
        unordered_map<int,int> mp;
        
        while(j < nums.size())
        {
            mp[nums[j]]++;
            while(mp[maxi] >= k)
            {
                ans += nums.size()-j;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};