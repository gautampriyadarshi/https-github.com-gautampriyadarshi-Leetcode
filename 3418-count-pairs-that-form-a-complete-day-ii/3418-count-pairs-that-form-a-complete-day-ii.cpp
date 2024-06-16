class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) 
    {
        // TLE: 711/713 cases passed.
        /*long long count = 0;
        for(int i = 0; i < hours.size(); i++)
        {
            for(int j = i+1; j < hours.size(); j++)
            {
                if((hours[i]+hours[j]) % 24 == 0)
                    count++;
            }
        }
        return count;   */

        long long ans = 0;
        unordered_map<int,int> mp;

        for(int i = 0; i < hours.size(); i++)
        {
            int m = hours[i] % 24;

            if(mp.count(m))
                ans += mp[m];
            
            mp[(24-m) % 24]++;
        }
        return ans;   
    }
};