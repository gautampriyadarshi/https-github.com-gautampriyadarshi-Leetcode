class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        // 905/969 cases passed:
        /*
        int count = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for(auto x: mp)
        {
            if(x.first > k)
                count++;
            
            if(x.second == nums.size() && x.first == k)
                return 0;
        }

        if(count == 0)
            return -1;
        
        return mp.size();      */
        
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > k)
                mp[nums[i]]++;
                
            else if(nums[i] < k)
                return -1;
        }
        return mp.size();
    }
};