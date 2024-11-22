class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.length();
        unordered_set<string> mp;

        for(int i = 0; i<n/2; i++)
        {
            int len_sub = i+1;
            mp.insert(s.substr(0,len_sub));

            for(int j=i+1; j<n; )
            {
                if(mp.find(s.substr(j,len_sub)) != mp.end() && j+len_sub == n)
                    return true;
                
                else if(mp.find(s.substr(j,len_sub)) == mp.end())
                {
                    mp.clear();
                    break;
                }
                else
                    j = j+len_sub;
            }
        }
        return false;
    }
};