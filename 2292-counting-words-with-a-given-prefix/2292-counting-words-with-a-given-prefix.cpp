class Solution {
    bool check(string a, string b)
    {
        // a is pref and b is the word.
        int m = a.size(), n = b.size(), i = 0;
        while(i < m)
        {
            if(a[i] == b[i])
                i++;
            else
                return false;
        }
        return true;
    }
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(check(pref, words[i]))
                count++;
        }
        return count;
    }
};