class Solution {
public:
    int maxDifference(string s) 
    {
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        int maxi = INT_MIN, mini = INT_MAX;
        for(auto x: mp)
        {
            if(x.second % 2 != 0)
            {
                if(x.second > maxi)
                    maxi = x.second;
            }
            else
            {
                if(x.second < mini)
                    mini = x.second;
            }
        }
        return (maxi - mini);
    }
};