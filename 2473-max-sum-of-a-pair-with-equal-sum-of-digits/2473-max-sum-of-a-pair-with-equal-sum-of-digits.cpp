class Solution {
    int getSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        int maxi = -1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int sm = getSum(nums[i]);

            if(mp[sm].size() < 2)
                mp[sm].push_back(nums[i]);
            else
            {
                mp[sm][0] = mp[sm][1];
                mp[sm][1] = nums[i];
            }

            if(mp[sm].size() == 2)
                maxi = max(maxi, mp[sm][0] + mp[sm][1]);
        }
        return maxi;
    }
};