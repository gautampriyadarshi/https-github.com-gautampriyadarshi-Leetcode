class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for(auto x: mp)
        {
            if(x.second >= 3)
                return false;
        }
        return true;
    }
};