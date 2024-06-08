class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        map<int, int> mp;
        mp[0] = -1;

        int sum = 0, n = nums.size(), mod;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            mod = sum % k;

            if(mp.find(mod) == mp.end()) 
                mp[mod] = i;

            else if((i - mp[mod]) > 1) 
                return true;
        }
        return false;

        // 79/99 cases passed
        /*
        unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            // calculating prefix sum [sum from 0 to i]
            sum += nums[i];  

            if(sum % k == 0)
                count++;
            else
                count = 0;

            if(count >= 1)
                return true;

            mp[sum]++; 
        }
        
        return false;   */
    }
};