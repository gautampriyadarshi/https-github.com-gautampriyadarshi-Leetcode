class Solution {
    string invert(string s)
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }

    string solveRec(int n)
    {
        if(n == 1)
            return "0";
        
        string s = solveRec(n-1);
        string rev = invert(s);
        reverse(rev.begin(), rev.end());

        return s + "1" + rev;
    }
public:
    char findKthBit(int n, int k) 
    {
        string ans = solveRec(n);
        return ans[k-1];
    }
};