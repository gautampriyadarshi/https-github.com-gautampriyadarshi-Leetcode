class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        // My solution gave TLE & wrong answer, this is someone else code :)
        long long sum = 0;
        int n = nums.size();
        int ans = n, curr = 0;
        
        for(int i = 0; i < n; i++)
        {
            curr += nums[i];
            curr %= p;
        }
        
        map<int, int> mp;
        int need = curr;

        if(need == 0)
            return 0;

        mp[0] = -1;
        curr = 0;

        for(int i = 0; i < n; i++)
        {
            curr += nums[i];
            curr %= p;

            if(mp.find((curr - need + p) % p) != mp.end())
            {  
                ans = min(ans, i- mp[(curr - need + p) % p]);
            }
            mp[curr] = i;   
        }
        return ans == n ? -1 : ans;
    }
};