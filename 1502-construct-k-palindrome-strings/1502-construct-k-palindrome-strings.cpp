class Solution {
public:
    bool canConstruct(string s, int k) 
    {
        // 90/108 cases passed.     
        /*
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        bool seen = false;
        for(auto x: mp)
        {
            if(x.second % 2 == 0)
                seen = true;
            
            if(x.second == s.size())
                return true;
        }

        if(!seen)
            return false;
        
        return true;    */

        unordered_map<char, int> mp;
        int single = 0;
        for(int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        for(auto x: mp)
        {
            if(x.second % 2 == 1)
                single++;
        }

        if(single <= k && k <= s.size())
            return true;
        
        return false;
    }
};