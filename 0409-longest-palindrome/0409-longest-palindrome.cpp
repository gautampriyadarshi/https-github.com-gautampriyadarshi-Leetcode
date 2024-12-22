class Solution {
public:
    int longestPalindrome(string s) 
    {
        if(s.size() == 1)
            return 1;

        unordered_map<char,int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        int count = 0, y = 0;
        for(auto x: mp)
        {
            if(x.second % 2)
            {
                count += x.second - 1;
                y = 1;
            }
            else
                count += x.second;
        }
        count += y;

        return count;
    }
};