class Solution {
public:
    int minimumLength(string s) 
    {
        int count = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        for(auto x: mp)
        {
            if(x.second % 2 == 0)
                count += 2;
            else if(x.second % 2 == 1)
                count += 1 ;
        }
        return count;
    }
};