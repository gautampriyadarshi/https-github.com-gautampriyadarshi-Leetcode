class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        // TLE:- 682/687 cases passed:
        /*  long long count = 0;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] % (nums2[j] * k) == 0)
                    count++;
            }
        }
        return count;   */

        unordered_map<long long, long long> mp;
        for(int i = 0; i < nums2.size(); i++)
        {
            mp[nums2[i] * k]++;
        }

        long long count = 0;
        for(auto x: nums1)
        {
            for(int i = 1; i * i <= x; i++)
            {
                if(x % i == 0)
                {
                    count += mp[i];

                    if(i*i != x)
                        count += mp[x / i];
                }
            }
        }
        return count; 
    }
};