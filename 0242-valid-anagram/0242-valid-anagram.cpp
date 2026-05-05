class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, int> mp1, mp2;
        for(int i = 0; i < s.size(); i++)
        {
            mp1[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++)
        {
            mp2[t[i]]++;
        }

        for(auto x: mp1)
        {
            for(auto y: mp2)
            {
                if(x.first == y.first && x.second != y.second)
                    return false;

                if(mp2[x.first] == 0 || mp1[y.first] == 0)
                    return false;
            }
            
        }
        return true;
    }
};