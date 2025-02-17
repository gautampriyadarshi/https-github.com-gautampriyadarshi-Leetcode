class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int x = -1;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;

            if(mp[nums[i]] == 2)
            {
                x = nums[i];
                break;
            }
        }
        return x;
    }
};