class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        // My code:
        // TLE: 562/578 cases passed:
    /*  int count = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < meetings.size(); i++)
        {
            for(int j = meetings[i][0]; j <= meetings[i][1]; j++)
            {
                if(mp[j] == 0)
                {
                    mp[j]++;
                    count++;
                }
            }
        }
        return days - count;    */

        int freeDays = 0, latestEnd = 0;
        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) 
        {
            int start = meeting[0], end = meeting[1];
            if (start > latestEnd + 1) 
                freeDays += start - latestEnd - 1;
            
            latestEnd = max(latestEnd, end);
        }
        freeDays += days - latestEnd;

        return freeDays;
    }
};