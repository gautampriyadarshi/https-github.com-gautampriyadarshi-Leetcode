class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        // TLE:- 561/578 cases passed:
        /*unordered_map<int, bool> mp;
        int count = 0;
        for(int i = 0; i < meetings.size(); i++)
        {
            int x = meetings[i][0], y = meetings[i][1];
            for(int j = x; j <= y; j++)
            {
                mp[j] = true;
            }
        }

        for(int i = 1; i <= days; i++)
        {
            if(mp[i] == false)
                count++;
        }
        return count;   */

        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int ans = 0; 
        int maxDays = 0;

        for(int i = 0; i < n; i++)
        { 
            if(i == 0)
            {
                ans += meetings[i][0] - 1;
                maxDays = meetings[i][1];
            }

            else {
                if(meetings[i][0] > maxDays)
                {
                    ans += meetings[i][0] - maxDays -1 ;  
                }
                    maxDays = max(maxDays, meetings[i][1]); 
            }

            if(i == n-1){ 
                maxDays = max(maxDays, meetings[i][1]);
                ans += days - maxDays;
              
            }
        }
        return ans;
    }
};