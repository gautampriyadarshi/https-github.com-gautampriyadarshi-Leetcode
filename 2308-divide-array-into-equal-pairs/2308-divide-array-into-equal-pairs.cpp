class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        int count = 0;
        for(auto x: mp)
        {
            if(x.second % 2 != 0)
                return false;
            else
            {
                count += x.second/2;
            }
        }

        return count == nums.size()/2;
    }
};