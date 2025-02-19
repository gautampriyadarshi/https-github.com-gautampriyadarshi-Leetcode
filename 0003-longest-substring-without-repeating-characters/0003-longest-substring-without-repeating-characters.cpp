class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0 || s.size() == 1)
            return s.size();
            
        unordered_map<char,int> mp;
        int maxi = 0, j = 0, count = 0;

        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            count++;

            while(mp[s[i]] > 1)
            {
                count--;
                mp[s[j++]]--;
            }
            maxi = max(count, maxi);

            /* My approach but 408 cases passed only:-
            if(mp[s[i]] == 0)
                mp[s[i]]++;
            else
            {
                int x = mp.size();
                maxi = max(maxi, x);
                mp.clear();
                mp[s[i]]++;
            }   */
        }
        return maxi;
    }
};