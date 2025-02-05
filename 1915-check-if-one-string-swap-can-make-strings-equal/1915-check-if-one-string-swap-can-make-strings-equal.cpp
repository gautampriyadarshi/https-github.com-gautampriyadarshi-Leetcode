class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        if (s1 == s2) 
            return true;
        
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) 
        {
            if (s1[i] != s2[i]) 
                diff.push_back(i);

            if (diff.size() > 2) 
                return false;
        }
        return diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];

        /* 130/132 testcases passed:
        if(s1.size() != s2.size())
            return false;

        int count = 0, j = 0;
        unordered_map<char, int> mp1;
        for(int i = 0; i < s1.size(); i++)
        {
            mp1[s1[i]]++;
            if(s1[i] != s2[j])
                count++;
            
            j++;

            if(count > 2)
                return false;
        }

        if((s1.size() <= 2 && count == 1) || (count == 1))
            return false;
        
        for(int i = 0; i < s2.size(); i++)
        {
            if(mp1[s2[i]] == 0)
                return false;
            
            mp2[s2[i]]++;
        }
        return true;    */
    }
};