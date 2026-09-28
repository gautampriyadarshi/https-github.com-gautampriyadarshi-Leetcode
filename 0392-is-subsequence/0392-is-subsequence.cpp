class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int m = s.size(), n = t.size(), i = 0, j = 0;

        if(m == 0)
            return true;

        while(i < m && j < n)
        {
            if(s[i] == t[j])
            {
                if(i == m-1)
                    return true;

                i++;
                j++;
            }
            else
                j++;
        }
        return false;
    }
};