class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        nums.clear();
        for(auto x: mp)
        {
            nums.push_back(x.first);
        }

        return nums.size();
    }
};