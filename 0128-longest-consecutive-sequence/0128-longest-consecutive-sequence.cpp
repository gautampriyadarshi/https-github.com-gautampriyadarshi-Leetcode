class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        map<int, int> mp;
        for (int i : nums) 
        {
            mp[i]++;
        }

        int count = 0;
        int mx = 0;
        int cur = mp.begin()->first;

        for (auto it : mp) 
        {
            if (it.first - cur == 1) 
            {
                count++;
                cur = it.first;
            } 
            else 
            {
                mx = max(count, mx);
                count = 1;
                cur = it.first;
            }
        }
        mx = max(count, mx);
        return mx;
    }
};