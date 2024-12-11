class Solution {
    bool check(string &a, string &b)    
    {
        int n = a.length(), m = b.length();

        if(m < n)   
            return false;

        string x = b.substr(0, n);
        string y = b.substr(m-n);

        return a == x && a == y;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int count = 0;
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i+1; j < words.size(); j++)
            {
                if(check(words[i], words[j]))
                    count++;
            }
        }
        return count;
    }
};