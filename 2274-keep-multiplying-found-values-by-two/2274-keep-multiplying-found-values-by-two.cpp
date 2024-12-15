class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        int copy = original;
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
           
        for(int i = 0; i < nums.size(); i++)
        {
            if(mp.find(copy) != mp.end())
                copy = 2* copy;
        }
        return copy;
    }
};