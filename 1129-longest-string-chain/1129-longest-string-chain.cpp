bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
class Solution {
    bool check(string &s1, string &s2)
    {
        if(s1.size() != s2.size() + 1)
            return false;
        
        int first = 0, second = 0;
        while(first < s1.size())
        {
            if(s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
                first++;
        }

        if(first == s1.size() && second == s2.size())
            return true;

        return false;
    }
    int optimizedTab(vector<string>& words)
    {
        // For returning the length: Code of Longest Increasing Subsequence
        int n = words.size(), maxi = 1;
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), comp);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (check(words[i], words[prev]) && 1 + dp[prev] > dp[i])
                    dp[i] = 1 + dp[prev];
            }

            if (dp[i] > maxi)
                maxi = dp[i];
        }
        return maxi;
    }
public:
    int longestStrChain(vector<string>& words) 
    {
        return optimizedTab(words);
    }
};