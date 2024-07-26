class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) 
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == key)
                mp[nums[i+1]]++;
        }

        int maxi = INT_MIN, ans = 0;
        for(auto x: mp)
        {
            if(x.second > maxi)
            {
                maxi = x.second;
                ans = x.first;
            }
        }
        return ans;
    }
};