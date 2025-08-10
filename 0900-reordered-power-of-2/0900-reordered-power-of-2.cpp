class Solution {
    string solve(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return s;
    }
public:
    bool reorderedPowerOf2(int n) 
    {
        string s = solve(n);
        for (int i = 0; i < 32; i++)
        {
            int k = (1 << i);
            if (s == solve(k))
                return true;
        }
        return false;
    }
};