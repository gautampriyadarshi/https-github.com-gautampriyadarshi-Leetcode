class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return {0,1};
        
        int countPairs = 0, countLeft = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for(auto x: mp)
        {
            if(x.second == 1)
                countLeft++;
            else if(x.second % 2 == 0)
                countPairs += x.second/2;
            else if(x.second > 2)
            {
                countPairs += x.second/2;
                countLeft++;
            }
        }

        vector<int> ans = {countPairs, countLeft};
        return ans;
    }
};