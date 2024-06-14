class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) 
    {
        // TLE: 55/63 cases passed.
        /*    int count = 0;
        unordered_map<int,int> mp;
        unordered_map<int, bool> mb;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(mp[nums[i]] == 1)
                continue;
            
            if(mp[nums[i]] > 1)
            {
                if(mb[nums[i]] == false)
                {
                    mb[nums[i]] = true;
                    continue;
                }
                else
                {
                    while(mp[nums[i]] > 0)
                    {
                        nums[i]++;
                        count++;
                        if(mp[nums[i]] == 0)
                        {
                            mp[nums[i]]++;
                            break;
                        }
                    }
                }
            }
        }
        return count;   */

        map<int, int> mp;

        for(int i : nums) 
            mp[i]++;

        int ans = 0;
        for(auto i : mp)
        {
            if(i.second > 1)
            {
                ans += (i.second - 1);
                mp[i.first + 1] += (i.second - 1);
            } 
        }
        return ans;
    }
};