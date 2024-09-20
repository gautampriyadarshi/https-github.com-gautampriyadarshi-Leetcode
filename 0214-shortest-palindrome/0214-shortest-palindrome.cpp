class Solution {
public:
    string shortestPalindrome(string s) 
    {
        const int n = s.size();
        int i = 0;
        for (int j = n-1; j >= 0; j--) 
        {
            while (j >= 0 && s[i] == s[j])
            {
                i++;
                j--;
            }
        }
        if (i == n)
            return s;

        string sub = s.substr(i), remain = sub;
        reverse(remain.begin(), remain.end());
        return remain + shortestPalindrome(s.substr(0, i)) + sub;
    }
};